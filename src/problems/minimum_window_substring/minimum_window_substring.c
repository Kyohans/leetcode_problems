#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Given two strings s and t of lengths m and n respectively, return the minimum window substring
// of s such that every character in t (including duplicates) is included in the window. 
// If there is no such substring, return the empty string "".
//
// The testcases will be generated such that the answer is unique.

static int s_map[96] = {0};
static int t_map[96] = {0};

bool isincluded(char * t) {
  for(size_t i = 0; i < strlen(t); i++) {
    if(s_map[t[i] - 'A'] < t_map[t[i] - 'A']) return false;
  }

  return true;
}

char * solution(char * s, char * t) {
  size_t slen = strlen(s);
  size_t tlen = strlen(t);

  for(int i = 0; i < tlen; i++) t_map[t[i] - 'A']++;

  int l = 0, r = 0;
  int fl = 0, fr = 0;
  int min = INT_MAX;
  for(; r < slen; r++) {
    s_map[s[r] - 'A']++;
    printf("%d, %d\n", s_map[s[r] - 'A'], t_map[s[r] - 'A']);
    if(isincluded(t)) {
      if(r - l + 1 <= min) {
        min = r - l + 1;
        fl = l;
        fr = r;
      }

      do {
        s_map[s[l++] - 'A']--;
      } while(l < slen && t_map[s[l] - 'A'] == 0);
    }
  }

  if(INT_MAX == min) return "";

  char * res = (char *)malloc(sizeof(char) * (fr - fl + 2));
  strncpy(res, s + fl, fr - fl + 1);
  return res;
}

int main(int argc, char ** argv) {
  printf("-- Leetcode 76: Minimum Window Substring --\n");
  if(argc < 2) {
    printf("Solution: %s\n", solution("ab", "a"));
  } else {
    printf("Solution: %s\n", solution(argv[1], argv[2]));
  }
}
