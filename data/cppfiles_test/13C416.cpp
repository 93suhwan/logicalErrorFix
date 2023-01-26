#include <bits/stdc++.h>
void checkLetter(char *symbol, int *a, int *b, int *c);
int main() {
  int numSets;
  scanf("%d\n", &numSets);
  for (int setNum = 0; setNum < numSets; ++setNum) {
    int a = 0;
    int b = 0;
    int c = 0;
    char symbol;
    checkLetter(&symbol, &a, &b, &c);
    while (symbol != '\n') {
      checkLetter(&symbol, &a, &b, &c);
    }
    if (a + c == b) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
void checkLetter(char *symbol, int *a, int *b, int *c) {
  scanf("%c", symbol);
  switch (*symbol) {
    case 'A':
      (*a)++;
      break;
    case 'B':
      (*b)++;
      break;
    case 'C':
      (*c)++;
      break;
    default:
      break;
  }
}
