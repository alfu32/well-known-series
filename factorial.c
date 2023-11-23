#include <stdio.h>
#include <stdlib.h>
typedef unsigned long long u64;

u64* factorial(long n) {
    u64 *factorialn = malloc((n+1)*sizeof(u64));
    if (factorialn == NULL) {
        printf("Error: Not enough memory to allocate the Fibonacci series.\n");
        exit(1);
    }
    factorialn[0] = 1;
    for (int i=1; i<=n; ++i) {
        factorialn[i] = i*factorialn[i-1];
    }
    return factorialn;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Error: The number of arguments is not correct.\n");
        exit(1);
    }
    int n = atoi(argv[1]);
    u64 *catas = factorial(n);
    for (int i=0; i<=n; ++i) {
        printf("factorial [%8d] -> (%12llu) \n",i, catas[i]);
    }
    free(catas);
    return 0;
}