# priority-queue-project
# Priority Queue Implementations

This project compares different priority queue data structures, including:

- Binary Heap
- Binomial Heap
- Fibonacci Heap

## Overview

Priority queues are fundamental data structures used in algorithms such as Dijkstra’s shortest path and Prim’s minimum spanning tree.

This project focuses on understanding the trade-offs between different implementations in both theory and practice.

## Implementations

### Binary Heap
- Array-based implementation
- Efficient and simple
- O(log n) insert and extract-min

### Binomial Heap
- Supports merging of heaps
- Tree-based structure

### Fibonacci Heap
- Theoretically efficient
- O(1) amortized insert and decrease-key
- Simplified implementation in this project

## Experiments

We tested performance using randomly generated data with sizes:
- 1,000
- 10,000
- 50,000

Results show that binary heaps perform better in practice despite higher theoretical complexity.

Compile using:
