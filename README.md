# Cache Optimization

This project aims to demonstrate how effectively utilizing cache behavior can optimize performance. As a practical example, matrix transposition is used to compare four different strategies.

## Strategies

### 1. Naive Solution
The naive solution does not take cache behavior into account, which leads to poor performance. Since the memory layout is in row-major order, writing to the destination matrix in column-major order results in frequent cache misses. During write operations, non-contiguous memory locations are accessed, causing cache lines to be frequently evicted and reloaded with new data.

### 2. Cache-Aware Solution
In the cache-aware solution, cache characteristics were considered. The system has an 8-way set-associative cache with a cache line size of 64 bytes. The implementation divides the original matrix into 8x8 tiles, which fit well into the cache, making both read and write accesses more efficient by reducing cache misses.

### 3. Cache-Oblivious Solution
The cache-oblivious solution achieves better performance compared to the naive solution, despite not having any knowledge of cache size. It traverses the matrix in **Z-order (Morton order)**, which exploits spatial locality by ensuring that accessed elements are stored close to each in memory, reducing cache misses. However, this approach doesn’t perform as efficiently as the cache-aware solution.

### 4. Optimized Solution
The optimized solution combines the benefits of **Z-order traversal** and **cache-aware tiling**. This approach achieves the best performance by making the most efficient use of cache lines.

## Results

| Strategy     | Time (sec) | Speedup |
|--------------|----------------|---------|
| Naive        | 25.29          | -       |
| Aware        | 5.29           | 4.7     |
| Oblivious    | 7.36           | 3.4     |
| Optimized    | 3.01           | 8.4     |