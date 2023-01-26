#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
  return x * f;
}
const int N = 30;
int n, m, k, s[N][N], vis[N][N], ans;
char ch[N];
int main() {
  int T = read();
  while (T--) {
    memset(vis, 0, sizeof(vis));
    n = read(), m = read(), k = read(), ans = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%s", ch + 1);
      for (int j = 1; j <= m; j++) {
        if (ch[j] == '.')
          s[i][j] = 0;
        else {
          ans++;
          s[i][j] = 1;
        }
      }
    }
    for (int i = n; i >= 1; i--) {
      for (int j = 1; j <= m; j++) {
        if (s[i][j]) {
          int h = 0;
          while (i - h && j - h && j + h <= m && s[i - h][j - h] &&
                 s[i - h][j + h]) {
            h++;
          }
          if (h > k)
            while (h--) {
              vis[i - h][j - h] = vis[i - h][j + h] = 1;
            }
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (vis[i][j]) ans--;
      }
    }
    if (ans)
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
