#include <bits/stdc++.h>
int main() {
  int numSets;
  scanf("%d", &numSets);
  for (int setNum = 0; setNum < numSets; ++setNum) {
    char symbol = ' ';
    int a = 0;
    int b = 0;
    int c = 0;
    while (symbol != '\n') {
      scanf("%c", &symbol);
      switch (symbol) {
        case 'A':
          a++;
          break;
        case 'B':
          b++;
          break;
        case 'C':
          c++;
          break;
        default:
          break;
      }
    }
    if (a + c == b) {
      printf("YES");
    } else {
      printf("NO");
    }
  }
  return 0;
}
