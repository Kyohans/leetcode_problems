#include <stdio.h>
#include <stdlib.h>

// Leetcode 238
// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
// You must write an algorithm that runs in O(n) time and without using the division operation.

int * product_except_self(int * nums, int numsSize) {
  int prefix[numsSize];
  int suffix[numsSize];
  prefix[0] = 1;
  suffix[numsSize - 1] = 1;

  for(int i = 1; i < numsSize; i++) prefix[i] = prefix[i - 1] * nums[i - 1];
  for(int i = numsSize - 2; i >= 0; i--) suffix[i] = suffix[i + 1] * nums[i + 1];

  int * ret = calloc(numsSize, sizeof(int));
  for(int i = 0; i < numsSize; i++) {
    ret[i] = prefix[i] * suffix[i];
  }

  return ret;
}

void print_array(int * arr, int numsSize) {
  for(int i = 0; i < numsSize; i++) {
    if(i == numsSize - 1) printf("%d]\n", arr[i]);
    else printf("%d, ", arr[i]);
  }
}

int main(void) {
  printf("-- Leetcode 238: Product of Array Except Self --\n");
  int nums[4] = {1,2,3,4};
  int numsSize = 4;
  printf("Input: [");
  print_array(nums, numsSize);

  int * ret = product_except_self(nums, numsSize);
  printf("Solution: [");
  print_array(ret, numsSize);
}
