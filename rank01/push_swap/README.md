*This project has been made as part of the 42 curriculum by aramos-e, czuluaga*

# PUSH_SWAP

---

## Description

The goal of this project is to sort a stack of integers using only permitted stack operations and a secondary stack. The program implements multiple sorting algorithms, each optimized for different input sizes and disorder levels.

**Sorting Strategies:**
- **Simple**: O(n²) - Selection Sort (Straightforward approach for small datasets)
- **Medium**: O(n√n) - Chunk Based Sort (Balanced performance for medium-sized inputs)
- **Complex**: O(n log n) - Radix Sort (Optimal performance using bit-based sorting)
- **Adaptive**: Automatically selects the best algorithm based on the input's disorder index

The **disorder index** measures how unsorted the input is (0 = sorted, 1 = reverse sorted). The adaptive algorithm uses this metric to choose the most efficient sorting strategy automatically.

## Instructions

### Compilation

Run `make` to compile the project and generate the `push_swap` binary.

### Usage

```
./push_swap [--strat] [--bench] [numbers]
```

**Strategy Options:**
- `--simple` - Use the O(n²) algorithm
- `--medium` - Use the O(n√n) algorithm  
- `--complex` - Use the O(n log n) algorithm
- `--adaptive` - Automatically select the best algorithm (default)

**Benchmarking:**
- `--bench` - Display operation counts and algorithm statistics

**Input:**
- Numbers can be provided as individual arguments or as a single quoted string

### Examples

```bash
./push_swap --simple --bench 1 5 32 23 9999
./push_swap --bench 1 5 32 23 9999
./push_swap "1 5 32 23 9999"
```

### Allowed Operations

The program sorts stack A using these operations with stack B:
- **sa/sb/ss** - Swap first two elements
- **pa/pb** - Push top element from one stack to the other
- **ra/rb/rr** - Rotate (move first element to end)
- **rra/rrb/rrr** - Reverse rotate (move last element to top)

## Resources

- [Radix Sort Article](https://www.geeksforgeeks.org/dsa/radix-sort/)
- [Bitwise Operators in C](https://www.geeksforgeeks.org/c/bitwise-operators-in-c-cpp/)
- AI assistance for algorithm research and binary operator concepts

## Algorithms

### Simple Algorithm - O(n²)
Finds the minimum element, pushes it to stack B, and repeats. Simple but inefficient for large inputs. Best for small datasets (n < 10).

### Medium Algorithm - O(n√n)
Divides numbers into chunks, processes them in order, and efficiently merges sorted data. Provides good balance for medium-sized inputs (10 < n < 500).

### Complex Algorithm - O(n log n)
Uses bit-by-bit sorting based on binary representation (radix sort principles). Highly optimized for large datasets (n > 500) with minimal operations.

### Adaptive Algorithm
Calculates the disorder index and automatically selects the algorithm with the best estimated performance. Recommended for general use.