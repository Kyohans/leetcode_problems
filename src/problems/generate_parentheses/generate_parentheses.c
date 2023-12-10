#include <stdio.h>
#include <stdlib.h>

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
// Example 1:
//
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
//
// Example 2:
//
// Input: n = 1
// Output: ["()"]

#define MAXSIZE 16

typedef struct {
  char ** parentheses;
  int top;
} stack;

typedef struct {
  char * b;
  int top;
} string_builder;

void helper(stack * st, int idx, int open, int close, int n) {
  static char str[MAXSIZE];

  if(close == n) {
    st->parentheses[st->top++] = str;
    return;
  } else {
    if(close < open) {
      str[idx] = ')';
      helper(st, idx + 1, open, close + 1, n);
    }

    if(open < n) {
      str[idx] = '(';
      helper(st, idx + 1, open + 1, close, n);
    }
  }
}

void helper2(stack * st, string_builder * builder, int left, int right) {
  if(left == 0 && right == 0) {
    st->parentheses[st->top++] = builder->b;
    return;
  }

  if(left > right || left < 0 || right < 0) {
    return;
  }

  builder->b[builder->top++] = '(';
  helper2(st, builder, left - 1, right);
  builder->b[builder->top--] = '\0';

  builder->b[builder->top++] = ')';
  helper2(st, builder, left, right - 1);
  builder->b[builder->top--] = '\0';
}

char ** generate_parentheses(int n) {
  stack * st = malloc(sizeof(stack));
  st->parentheses = (char **)malloc(sizeof(char *) * n);
  st->top = 0;

  string_builder * builder = malloc(sizeof(string_builder));
  builder->b = (char *)malloc(sizeof(char) * (n * 2));
  builder->top = 0;

  helper2(st, builder, n, n);
  return st->parentheses;
}

int main(void) {
  printf("-- Leetcode 22: Generate Parentheses --\n");
  int n = 5;
  char ** solution = generate_parentheses(n);
  for(int i = 0; i < n; i++) {
    printf("%s\n", solution[i]);
  }
  return 0;
}
