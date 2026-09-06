# DAA Lab-06 - Question 3

## Convolution of Two Vectors

Given vectors `A` and `B` of lengths `m` and `n`, where `n >= m`, compute their convolution.

The lab asks for an `O(n log n)` divide-and-conquer algorithm. This is achieved using the Fast Fourier Transform (FFT):

1. Pad both vectors with zeros.
2. Compute FFT of both vectors.
3. Multiply corresponding frequency-domain values.
4. Compute inverse FFT.
5. Read the convolution result.

### Complexity

The FFT takes `O(N log N)` time, where `N` is the selected power-of-two size. Pointwise multiplication takes `O(N)`. Therefore the complete convolution takes `O(N log N)` time.

### Compile

```bash
gcc q3_convolution.c -o q3 -lm
```

### Run

```bash
./q3
```
