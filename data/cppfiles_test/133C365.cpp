#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int t, n, i, j, chk;
  char str[110][3];
  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    scanf("%d", &n);
    for (j = 0; j < n - 2; j++) {
      scanf("%s", str[j]);
    }
    printf("%c", str[0][0]);
    chk = 0;
    for (j = 0; j < n - 3; j++) {
      if (str[j][1] == str[j + 1][0]) {
        printf("%c", str[j][1]);
        continue;
      } else {
        printf("%c%c", str[j][1], str[j + 1][0]);
        chk = 1;
      }
    }
    printf("%c", str[n - 3][1]);
    if (chk == 0) printf("a");
    printf("\n");
  }
  return 0;
}
