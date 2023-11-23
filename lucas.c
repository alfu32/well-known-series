#include <stdio.h>
#include <stdlib.h>
typedef unsigned long long u64;

u64* lucas(int n) {
    u64 *fib = malloc((n+1)*sizeof(u64));
    if (fib == NULL) {
        printf("Error: Not enough memory to allocate the Fibonacci series.\n");
        exit(1);
    }
    fib[0] = 2;
    fib[1] = 1;
    for (int i=2; i<=n; ++i) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Error: The number of arguments is not correct.\n");
        exit(1);
    }
    int n = atoi(argv[1]);
    u64 *fib = lucas(n);
    for (int i=0; i<=n; ++i) {
        printf("lucas [%4d] -> (%12llu) \n",i, fib[i]);
    }
    free(fib);
    return 0;
}