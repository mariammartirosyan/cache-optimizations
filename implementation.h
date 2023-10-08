void naive(int *src, int *dst, int SIZE)
{
    for(int i=0; i < SIZE; i++)
        for(int j=0; j < SIZE; j++)
            dst[(j * SIZE) + i] = src[(i * SIZE) + j];
}

void aware(int *src, int *dst, int SIZE)
{
    int tileSize = 8;
    for (int i = 0;i < SIZE;i+=tileSize) {
        
       for (int j = 0;j < SIZE;j+=tileSize) {
           
           for (int k = i; k < i + tileSize; k++)
           {
               for (int m = j; m < j + tileSize; m++)
               {
                   dst[(m * SIZE) + k] = src[(k * SIZE) + m];
               }
           }
       }
   }
}
//source begin: https://stackoverflow.com/questions/4909263/how-to-efficiently-de-interleave-bits-inverse-morton
int morton_decode(int z)
{
    int w = (z & 0xAAAAAAAA) << 31 | (z & 0x55555555);
    w = (w | (w >> 1)) & 0x3333333333333333;
    w = (w | (w >> 2)) & 0x0F0F0F0F0F0F0F0F;
    w = (w | (w >> 4)) & 0x00FF00FF00FF00FF;
    w = (w | (w >> 8)) & 0x0000FFFF0000FFFF;
    return w;
}
//source end

void oblivious(int *src, int *dst, int SIZE)
{
    for (int z = 0;z < SIZE*SIZE;z++) {
        int i = morton_decode(z >> 1);
        int j = morton_decode(z);
            dst[(j * SIZE) + i] = src[(i * SIZE) + j];
        }
}

void optimized(int *src, int *dst, int SIZE)
{
    int tileSize=8;
    for (int z = 0;z < SIZE*SIZE;z+=tileSize*tileSize) {
        
        int i = morton_decode(z >> 1);
        int j = morton_decode(z);
        
        for (int k = i; k < i + tileSize; k++)
        {
            for (int m = j; m < j + tileSize; m++)
            {
                dst[(m * SIZE) + k] = src[(k * SIZE) + m];
            }
        }
    }
}
