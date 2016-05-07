#include <stdio.h>
#include <stdint.h>

#define N 100

int main() {
  uint64_t sum = N * (N + 1) / 2;
  uint64_t sq_sum =  (N * (N + 1) * (2 * N + 1)) / 6;

  printf("solution = %llu\n", sum * sum - sq_sum);
}
