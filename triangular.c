#include <stdio.h>
#include <stdlib.h>
typedef unsigned long long u64;

u64* triangular(long n) {
    u64 *triangn = malloc((n+1)*sizeof(u64));
    if (triangn == NULL) {
        printf("Error: Not enough memory to allocate the Fibonacci series.\n");
        exit(1);
    }
    triangn[0] = 1;
    for (int i=1; i<=n; ++i) {
        triangn[i] = i*(i+1)/2;
    }
    return triangn;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Error: The number of arguments is not correct.\n");
        exit(1);
    }
    int n = atoi(argv[1]);
    u64 *catas = triangular(n);
    for (int i=0; i<=n; ++i) {
        printf("triangular [%8d] -> (%12llu) \n",i, catas[i]);
    }
    free(catas);
    return 0;
}