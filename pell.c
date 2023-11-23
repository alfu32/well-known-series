#include <stdio.h>
#include <stdlib.h>
typedef unsigned long long u64;

u64* pell(int n) {
    u64 *pelln = malloc((n+1)*sizeof(u64));
    if (pelln == NULL) {
        printf("Error: Not enough memory to allocate the Fibonacci series.\n");
        exit(1);
    }
    pelln[0] = 0;
    pelln[1] = 1;
    for (int i=2; i<=n; ++i) {
        pelln[i] = 2*pelln[i-1] + pelln[i-2];
    }
    return pelln;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Error: The number of arguments is not correct.\n");
        exit(1);
    }
    int n = atoi(argv[1]);
    u64 *pells = pell(n);
    for (int i=0; i<=n; ++i) {
        printf("pell [%4d] -> (%12llu) \n",i, pells[i]);
    }
    free(pells);
    return 0;
}