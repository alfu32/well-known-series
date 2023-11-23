#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>


typedef unsigned long long u64;

typedef struct BoolArray{
    u64 len;
    bool* data;
} BoolArray;

typedef struct U64Array{
    u64 len;
    u64* data;
} U64Array;


bool isPrime(u64 n) {
    if (n <= 1) return false; // 0 and 1 are not prime numbers
    if (n <= 3) return true;  // 2 and 3 are prime numbers

    // Check if n is divisible by 2 or 3
    if (n % 2 == 0 || n % 3 == 0) return false;

    // Check the numbers of the form 6k ± 1 up to sqrt(n)
    for (u64 i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

BoolArray sievePrimes(u64 limit){
    // Allocate memory for the prime number array
    bool *isPrime = malloc((limit + 1) * sizeof(bool));
    if (isPrime == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    BoolArray s={limit+1,isPrime};

    // Initialize all entries as true. A value in isPrime[i] will
    // finally be false if i is Not a prime, else true.
    for (u64 i = 0; i <= limit; i++) {
        isPrime[i] = true;
    }

    for (u64 p = 2; p * p <= limit; p++) {
        // If isPrime[p] is not changed, then it is a prime
        if (isPrime[p] == true) {
            // Update all multiples of p as not prime
            for (u64 i = p * p; i <= limit; i += p) {
                isPrime[i] = false;
            }
        }
    }

    // Count all prime numbers
    int primeCount=0;
    for (u64 p = 2; p <= limit; p++) {
        if (isPrime[p]) {
            primeCount++;
        } 
    }
    return s;

}

U64Array filterPrimes(BoolArray all) {
    // Allocate memory for the prime number array

    // Count all prime numbers
    int primeCount=0;
    for (u64 p = 2; p <= all.len; p++) {
        if (all.data[p]) {
            primeCount++;
        } 
    }
    // alloc result array
    u64 *primes = malloc((primeCount) * sizeof(u64));
    if (primes == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    int pk=0;
    for (u64 p = 2; p <= all.len; p++) {
        if (all.data[p]) {
            primes[pk]=p;
            pk++;
        }
    }
    U64Array r = {primeCount,primes};
    return r;
}


int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Error: The number of arguments is not correct.\n");
        exit(1);
    }
    int number = atoi(argv[1]);
    BoolArray sieve = sievePrimes(number);
    U64Array primes = filterPrimes(sieve);

    for(int i=0;i<primes.len;i++){
        printf("prime [%8d] -> (%12llu) \n",i, primes.data[i]);
    }

    free(sieve.data);
    free(primes.data);

    return 0;
}
