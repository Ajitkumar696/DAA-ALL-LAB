#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double r, i;
} Complex;

Complex add(Complex a, Complex b) {
    Complex c = {a.r + b.r, a.i + b.i};
    return c;
}

Complex sub(Complex a, Complex b) {
    Complex c = {a.r - b.r, a.i - b.i};
    return c;
}

Complex mul(Complex a, Complex b) {
    Complex c = {a.r * b.r - a.i * b.i, a.r * b.i + a.i * b.r};
    return c;
}

void fft(Complex *a, int n, int invert) {
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        while (j & bit) {
            j ^= bit;
            bit >>= 1;
        }
        j ^= bit;
        if (i < j) {
            Complex t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2.0 * acos(-1.0) / len * (invert ? -1 : 1);
        Complex wlen = {cos(ang), sin(ang)};

        for (int i = 0; i < n; i += len) {
            Complex w = {1, 0};
            for (int j = 0; j < len / 2; j++) {
                Complex u = a[i + j];
                Complex v = mul(a[i + j + len / 2], w);
                a[i + j] = add(u, v);
                a[i + j + len / 2] = sub(u, v);
                w = mul(w, wlen);
            }
        }
    }

    if (invert)
        for (int i = 0; i < n; i++) {
            a[i].r /= n;
            a[i].i /= n;
        }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int size = 1;
    while (size < m + n - 1) size <<= 1;

    Complex *A = calloc(size, sizeof(Complex));
    Complex *B = calloc(size, sizeof(Complex));

    for (int i = 0; i < m; i++) scanf("%lf", &A[i].r);
    for (int i = 0; i < n; i++) scanf("%lf", &B[i].r);

    fft(A, size, 0);
    fft(B, size, 0);

    for (int i = 0; i < size; i++) A[i] = mul(A[i], B[i]);

    fft(A, size, 1);

    for (int i = 0; i < m + n - 1; i++)
        printf("%.0f ", A[i].r);
    printf("\n");

    free(A);
    free(B);
    return 0;
}
