#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int solution(uint32_t n) {
  int count = 0;

  while(n) {
    count += (n & 1);
    n >>= 1;
  }

  return count;
}

int main(void) {
  printf("-- Leetcode 191: Number of 1 Bits --\n");

  uint32_t n = 0b11111111111111111111111111111101;

  printf("Input: %b\n", n);
  printf("Solution: %d\n", solution(n));
}
