#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMSIZE 3

// Given an array of strings nums containing n unique binary strings each of length n, 
// return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.

char * solution(char ** nums, int numsSize) {
  int len = strlen(nums[0]);
  char * answer = calloc(len, sizeof(char));

  for(int i = 0; i < numsSize; i++) {
    answer[i] = (nums[i][i] == '1') ? '0' : '1';
  }

  return answer;
}

int main(void) {
  int numsSize = NUMSIZE;
  char * nums[NUMSIZE] = {"111", "101", "001"};

  printf("-- Leetcode 1980: Find Unique Binary String --\n");
  printf("Input: [");
  for(int i = 0; i < NUMSIZE; i++) {
    if(i == NUMSIZE - 1) printf("%s]\n", nums[i]);
    else printf("%s, ", nums[i]);
  }

  printf("Solution: %s\n", solution(nums, numsSize));
}
