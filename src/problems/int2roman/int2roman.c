#include <stdlib.h>
#include <stdio.h>

#define MAXNUM 3999

char * int2roman(int num) {
  if(num < 1 || num > MAXNUM) return "";

  char * map[1001] = {0};
  map[1] = "I";
  map[4] = "IV";
  map[5] = "V";
  map[9] = "IX";
  map[10] = "X";
  map[40] = "XL";
  map[50] = "L";
  map[90] = "XC";
  map[100] = "C";
  map[400] = "CD";
  map[500] = "D";
  map[900] = "CM";
  map[1000] = "M";

  char * roman = (char *)calloc(50, sizeof(char));
  int count = 0;

  int n = num;
  for(int i = 1000; i >= 0; i--) {
    if(map[i] != NULL) {
      while(n >= i) {
        int size = (i == 4 || i == 9 || i == 40 || i == 90 || i == 400 || i == 900) ? 2 : 1;
        for(int j = 0; j < size; j++) roman[count++] = map[i][j];
        n -= i;
      }
    }
  }

  return roman;
}

int main(int argc, char * argv[]) {
  int num = 0;

  if(argc < 2) {
    num = 58;
  } else {
    num = atoi(argv[1]);
  }

  printf("Solution: %s\n", int2roman(num));
  return 0;
}
