#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// The demons had captured the princess and imprisoned her in the bottom-right corner of a dungeon. 
// The dungeon consists of m x n rooms laid out in a 2D grid. 
// Our valiant knight was initially positioned in the top-left room and must fight his way through dungeon to rescue the princess.
//
// The knight has an initial health point represented by a positive integer. 
// If at any point his health point drops to 0 or below, he dies immediately.
//
// Some of the rooms are guarded by demons (represented by negative integers), so the knight loses health upon entering these rooms; 
// other rooms are either empty (represented as 0) or contain magic orbs that increase the knight's health (represented by positive integers).
//
// To reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.
//
// Return the knight's minimum initial health so that he can rescue the princess.
//
// Note that any room can contain threats or power-ups, 
// even the first room the knight enters and the bottom-right room where the princess is imprisoned.

#define MIN(a, b) (a >= b) ? a : b;
#define M 3
#define N 3

int traverse(int ** dungeon, int health, int x, int y, int m, int n) {
  if(x < 0 || x >= m || y < 0 || y >= n) return health;

  int damage = dungeon[x][y];

  return MIN(
      traverse(dungeon, health + damage, x + 1, y, m, n),
      traverse(dungeon, health + damage, x, y + 1, m, n)
  );
}

int solution(int ** dungeon, int m, int n) {
  int health = traverse(dungeon, 0, 0, 0, m, n);
  return (health <= 0) ? health * -1 + 1 : health;
}

int main(void) {
  printf("-- Leetcode 174: Dungeon Game --\n");
  int floor1[N] = {-2,-3,3};
  int floor2[N] = {-5,-10,1};
  int floor3[N] = {10,30,-5};
  int ** dungeon = (int **)malloc(sizeof(int *) * M);
  dungeon[0] = floor1;
  dungeon[1] = floor2;
  dungeon[2] = floor3;

  printf("%d\n", solution(dungeon, M, N));
  return 0;
}
