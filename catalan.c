#include <stdio.h>
#include <stdlib.h>
typedef unsigned long long u64;

u64* catalan(long n) {
    u64 *catan = malloc((n+1)*sizeof(u64));
    if (catan == NULL) {
        printf("Error: Not enough memory to allocate the Fibonacci series.\n");
        exit(1);
    }
    catan[0] = 1;
    for (int i=1; i<=n; ++i) {
        int k=i-1;
        catan[i] = 2*(2*k+1)*catan[k]/(k+2);
    }
    return catan;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Error: The number of arguments is not correct.\n");
        exit(1);
    }
    int n = atoi(argv[1]);
    u64 *catas = catalan(n);
    for (int i=0; i<=n; ++i) {
        printf("catalan [%8d] -> (%12llu) \n",i, catas[i]);
    }
    free(catas);
    return 0;
}