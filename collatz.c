#include <stdio.h>
#include <stdlib.h>

int countCollatzTerms(int val) {
    int i=val;
    int k=0;
    while (i>4) {
        //printf("counting [%4d] -> (%4d) \n",k, i);
        if (i % 2 == 0) {
            i = i>>1;
        } else {
            i = 2 * i + i + 1;
        }
        k++;
    }
    k+=2;
    return k;
}

int* generateCollatzSeries(int val) {
    int sz = countCollatzTerms(val);
    //printf("allocating %d ints.\n",sz);

    int *collatz = malloc((sz+1)*sizeof(int));
    if (collatz == NULL) {
        printf("Error: Not enough memory to allocate the Fibonacci series.\n");
        exit(1);
    }
    int i=val;
    int k=sz;
    while (k>=0) {
        //printf("generating [%4d] -> (%4d) \n",k, i);
        collatz[k]=i;
        k--;
        if (i % 2 == 0) {
            i = i>>1;
        } else {
            i = 2 * i + i + 1;
        }
    }
    /// collatz[2]=4;
    /// collatz[1]=2;
    /// collatz[0]=1;
    return collatz;
}

void generateCollatzSignature(int val) {
    int i=val;
    while (i>4) {
        if (i % 2 == 0) {
            i = i>>1;
            printf("0");
        } else {
            i = 2 * i + i + 1;
            printf("1");
        }
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Error: The number of arguments is not correct.\n");
        exit(1);
    }
    int n = atoi(argv[1]);
    int sz=countCollatzTerms(n);
    int *col = generateCollatzSeries(n);
    for (int i=0; i<=sz; ++i) {
        printf("collatz [%4d] -> (%4d) \n",i, col[i]);
    }
    free(col);

    for (int i=1; i<=n; ++i) {
        printf("sig [%8d] ->  ",i);
        generateCollatzSignature(i);
        printf(" \n");
    }
    return 0;
}