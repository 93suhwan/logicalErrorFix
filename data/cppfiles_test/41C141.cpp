#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, m, f[4][7][N];
char s[N];
inline int read() {
  int x = 0, ff = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') ff = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * ff;
}
int main() {
  n = read();
  m = read();
  scanf("%s", s + 1);
  for (int i = 1; i <= 6; i++) {
    for (int st = 1; st <= 3; st++) {
      for (int j = st; j <= n; j++) {
        if (i == 1) {
          if ((j - st + 1) % 3 == 1)
            f[st][i][j] = f[st][i][j - 1] + (s[j] != 'a');
          if ((j - st + 1) % 3 == 2)
            f[st][i][j] = f[st][i][j - 1] + (s[j] != 'b');
          if ((j - st + 1) % 3 == 0)
            f[st][i][j] = f[st][i][j - 1] + (s[j] != 'c');
        }
        if (i == 2) {
          if ((j - st + 1) % 3 == 1)
            f[st][i][j] = f[st][i][j - 1] + (s[j] != 'b');
          if ((j - st + 1) % 3 == 2)
            f[st][i][j] = f[st][i][j - 1] + (s[j] != 'a');
          if ((j - st + 1) % 3 == 0)
            f[st][i][j] = f[st][i][j - 1] + (s[j] != 'c');
        }
        if (i == 3) {
          if ((j - st + 1) % 3 == 1)
            f[st][i][j] = f[st][i][j - 1] + (s[j] != 'a');
          if ((j - st + 1) % 3 == 2)
            f[st][i][j] = f[st][i][j - 1] + (s[j] != 'c');
          if ((j - st + 1) % 3 == 0)
            f[st][i][j] = f[st][i][j - 1] + (s[j] != 'b');
        }
        if (i == 4) {
          if ((j - st + 1) % 3 == 1)
            f[st][i][j] = f[st][i][j - 1] + (s[j] != 'c');
          if ((j - st + 1) % 3 == 2)
            f[st][i][j] = f[st][i][j - 1] + (s[j] != 'a');
          if ((j - st + 1) % 3 == 0)
            f[st][i][j] = f[st][i][j - 1] + (s[j] != 'b');
        }
        if (i == 5) {
          if ((j - st + 1) % 3 == 1)
            f[st][i][j] = f[st][i][j - 1] + (s[j] != 'b');
          if ((j - st + 1) % 3 == 2)
            f[st][i][j] = f[st][i][j - 1] + (s[j] != 'c');
          if ((j - st + 1) % 3 == 0)
            f[st][i][j] = f[st][i][j - 1] + (s[j] != 'a');
        }
        if (i == 6) {
          if ((j - st + 1) % 3 == 1)
            f[st][i][j] = f[st][i][j - 1] + (s[j] != 'c');
          if ((j - st + 1) % 3 == 2)
            f[st][i][j] = f[st][i][j - 1] + (s[j] != 'b');
          if ((j - st + 1) % 3 == 0)
            f[st][i][j] = f[st][i][j - 1] + (s[j] != 'a');
        }
      }
    }
  }
  while (m--) {
    int ans = 0x3f3f3f3f;
    int l, r;
    l = read();
    r = read();
    for (int i = 1; i <= 6; i++)
      ans =
          min(ans, f[l % 3 ? l % 3 : 3][i][r] - f[l % 3 ? l % 3 : 3][i][l - 1]);
    printf("%d\n", ans);
  }
  return 0;
}
