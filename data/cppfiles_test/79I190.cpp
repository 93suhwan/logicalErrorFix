#include <bits/stdc++.h>
const int N = 1e7 + 7;
using namespace std;
char s[N];
long long p[N];
long long t, a, b, m, n, x, sign, ans;
char c;
int main() {
  scanf("%d", &t);
  while (t--) {
    memset(s, 0, sizeof s);
    memset(p, 0, sizeof p);
    sign = 0;
    cin >> m;
    for (int i = 1; i <= m; i++) {
      c = getchar();
      while (c < '0' || c > '9') c = getchar();
      p[i] = c - '0';
      if (p[i] == 1 || p[i] == 4 || p[i] == 6 || p[i] == 8 || p[i] == 9) {
        sign = 1;
        printf("1\n%d\n", i);
        break;
      }
    }
    if (sign == 1) {
      continue;
    }
    sign = 0;
    for (int i = 1; i <= m; i++) {
      for (int j = i + 1; j <= m; j++) {
        ans = p[i] * 10 + p[j];
        if (ans != 23 && ans != 32 && ans != 37 && ans != 73 && ans != 53) {
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
