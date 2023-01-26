#include <bits/stdc++.h>
using namespace std;
char s[105];
int T, n;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    scanf("%s", s + 1);
    int p = 1;
    while (p <= n && s[p] == '?') ++p;
    if (p > n) {
      for (int i = 1; i <= n; ++i) {
        if (i & 1)
          printf("B");
        else
          printf("R");
      }
      printf("\n");
      continue;
    }
    for (int i = p - 1; i >= 1; --i) {
      if ((p - i) & 1) {
        if (s[p] == 'B')
          s[i] = 'R';
        else
          s[i] = 'B';
      } else {
        if (s[p] == 'B')
          s[i] = 'B';
        else
          s[i] = 'R';
      }
    }
    for (int i = p + 1; i <= n + 1; ++i) {
      if (i == n + 1 || s[i] != '?') {
        for (int j = p + 1; j < i; ++j) {
          if ((j - p) & 1) {
            if (s[p] == 'B')
              s[j] = 'R';
            else
              s[j] = 'B';
          } else {
            if (s[p] == 'B')
              s[j] = 'B';
            else
              s[j] = 'R';
          }
        }
        p = i;
      }
    }
    printf("%s\n", s + 1);
  }
  return 0;
}
