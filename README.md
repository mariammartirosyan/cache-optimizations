# CacheOptimizations

implementation.h file contains four different implementations of matrix transposition. 

  1. Normal Implementation
  2. Cache-Aware solution with the use of cache-tiling
     In order to make better use of cache memory by reducing the movement of data from main memory, I partitioned the matrix into blocks(tiles) such that while scanning in row-major order the row would completely fit in the cache line.
  3. Cache-oblivious solution
     The characteristics of the memory hierarchy are not taken into account, however traversing the matrix in Z-order results in better performance. 
  4. Optimized solution
     The matrix is being traversed in Z-order, but also the size of the cache line is considered, which results in better utilization of cache memory.
