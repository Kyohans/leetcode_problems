
// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit.
// Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

#include <stdlib.h>
#include <stdio.h>
#include <structs/linkedlist.h>

node * add_two_numbers(node * list1, node * list2) {
  node * a = list1;
  node * b = list2;

  int num1 = 0;
  int num2 = 0;
  while(a || b) {
    if(a) num1 = num1 * 10 + a->val;
    
    if(b) num2 = num2 * 10 + b->val;

    a = a->next;
    b = b->next;
  }

  int sum = num1 + num2;
  node * head = malloc(sizeof(node));
  node * curr = head;
  while(sum) {
    int digit = sum % 10;
    curr->val = digit;
    sum /= 10;

    if(sum > 0) {
      curr->next = malloc(sizeof(node));
      curr = curr->next;
    }
  }

  return head;
}

node * solution2(node * list1, node * list2) {
  node * head = malloc(sizeof(node));
  node * curr = head;

  node * a = list1, * b = list2;
  int carry = 0;
  while(a != NULL || b != NULL) {
    int sum = 0;
    if(a) sum += a->val;
    if(b) sum += b->val;
    if(carry > 0) sum += carry;

    int append = sum % 10;
    if(sum >= 10) {
      sum /= 10;
      carry = sum % 10;
    }

    curr->val = append;
    curr->next = malloc(sizeof(node));
    curr = curr->next;

    a = a->next;
    b = b->next;
  }

  return head;
}

int main(void) {
  printf("-- Leetcode 2: Add Two Numbers --\n") ;
  node * l11 = malloc(sizeof(node));
  node * l12 = malloc(sizeof(node));
  node * l13 = malloc(sizeof(node));
  l11->val = 2;
  l12->val = 4;
  l13->val = 3;
  l12->next = l13;
  l11->next = l12;

  node * l21 = malloc(sizeof(node));
  node * l22 = malloc(sizeof(node));
  node * l23 = malloc(sizeof(node));
  l21->val = 5;
  l22->val = 6;
  l23->val = 4;
  l22->next = l23;
  l21->next = l22;

  node * head = solution2(l11, l21);
  while(head) {
    printf("%d\n", head->val);
    head = head->next;
  }
}
