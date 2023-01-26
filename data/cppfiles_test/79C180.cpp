#include <bits/stdc++.h>
const int N = 1e+7;
using namespace std;
char s[100];
int p[100];
int t, a, b, m, n, x, sign;
char c;
int main() {
  scanf("%d", &t);
  while (t--) {
    sign = 0;
    scanf("%d", &m);
    scanf("%s", s + 1);
    for (int i = 1; i <= m; i++) {
      p[i] = s[i] - '0';
      if (p[i] == 1 || p[i] == 4 || p[i] == 6 || p[i] == 8 || p[i] == 9) {
        sign = 1;
        printf("1\n%d\n", p[i]);
        break;
      }
    }
    if (sign == 1) {
      continue;
    }
    sign = 0;
    for (int i = 1; i <= m; i++) {
      for (int j = i + 1; j <= m; j++) {
        int ans = p[i] * 10 + p[j];
        if (ans != 23 && ans != 37 && ans != 53 && ans != 73) {
          printf("2\n%d\n", ans);
          sign = 1;
          break;
        }
      }
      if (sign == 1) break;
    }
  }
  return 0;
}
