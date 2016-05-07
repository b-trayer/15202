#include <stdio.h>
#include <stdint.h>
#include <math.h>

int divisors(long long  x) {
    long long limit = x;
    int numberOfDivisors = 0;

    if (x == 1) return 1;

    for (long long i = 1; i < limit; ++i) {
        if (x % i == 0) {
            limit = x / i;
            if (limit != i) {
                numberOfDivisors++;
            }
            numberOfDivisors++;
        }
    }
    return numberOfDivisors;
}


int main () {
    long long number = 1;
    int i = 1;
    while (divisors (number) < 500) {
        number = (i * (1 + i))/2;
        i++;
    }
    printf("%lli\n", number);
}
