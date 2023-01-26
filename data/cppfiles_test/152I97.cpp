#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int ans = 0, f = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ans = (ans << 1) + (ans << 3) + c - '0';
    c = getchar();
  }
  return ans * f;
}
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x / 10) write(x / 10);
  putchar((char)(x % 10) + '0');
}
template <typename T>
inline T Abs(T a) {
  return a > 0 ? a : -a;
};
template <typename T, typename TT>
inline T Min(T a, TT b) {
  return a < b ? a : b;
}
template <typename T, typename TT>
inline T Max(T a, TT b) {
  return a < b ? b : a;
}
const int N = 1e6 + 5;
int t, n, a[N], dp[N][2][2], p1[N][2][2], p2[N][2][2], p3[N][2][2];
inline void update(int x, int y, int z, int v, int Y, int Z) {
  if (dp[x][y][z] < v) {
    dp[x][y][z] = v;
    p1[x][y][z] = (v > 0);
    p2[x][y][z] = Y;
    p3[x][y][z] = Z;
  }
}
void print(int x, int y, int z) {
  if (!x) return;
  print(x - 1, p2[x][y][z], p3[x][y][z]);
  write(p1[x][y][z] ? -a[x] : a[x]);
  putchar(' ');
}
signed main() {
  t = read();
  while (t--) {
    n = read();
    for (int i = 1; i <= n; ++i) a[i] = read();
    for (int i = 1; i <= n; ++i)
      for (int j = 0; j <= 1; ++j)
        for (int k = 0; k <= 1; ++k) dp[i][j][k] = -1e9;
    dp[1][0][0] = 1e9;
    dp[1][0][1] = 1e9;
    for (int i = 1; i <= n - 1; ++i)
      for (int j = 0; j <= 1; ++j)
        for (int k = 0; k <= 1; ++k)
          if (dp[i][j][k] != -1e9) {
            int x, y;
            if (j == 0) x = (k ? a[i] : -a[i]), y = dp[i][j][k];
            if (j == 1) y = (k ? a[i] : -a[i]), x = dp[i][j][k];
            if (a[i + 1] < y) {
              if (a[i + 1] < x)
                update(i + 1, 0, 1, y, j, k);
              else
                update(i + 1, 1, 1, x, j, k);
            }
            if (-a[i + 1] < y) {
              if (-a[i + 1] < x)
                update(i + 1, 0, 0, y, j, k);
              else
                update(i + 1, 1, 0, x, j, k);
            }
          }
    int flag = 1;
    for (int i = 0; i <= 1 && flag; ++i)
      for (int j = 0; j <= 1 && flag; ++j)
        if (dp[n][i][j] != -1e9) {
          puts("YES");
          print(n, i, j);
          puts("");
          flag = 0;
        }
    if (flag) puts("NO");
  }
  return 0;
}
