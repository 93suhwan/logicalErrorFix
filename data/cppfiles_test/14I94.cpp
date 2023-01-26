#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int x = 0, sgn = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') sgn = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return sgn * x;
}
const int maxn = 2000 + 222;
int T, n, k, ans, a[maxn], d[maxn][maxn];
void dp() {
  memset(d, 0, sizeof(d));
  ans = 0x3f3f3f3f;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == i)
      d[i][0] = d[i - 1][0] + 1;
    else
      d[i][0] = d[i - 1][0];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      d[i][j] = max(d[i][j], d[i - 1][j - 1] + (a[i] == j));
      d[i][j] = max(d[i][j], d[i - 1][j]);
      if (d[i][j] >= k) {
        ans = min(ans, i - j);
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  T = read();
  while (T--) {
    n = read();
    k = read();
    for (register int(i) = (1); i <= (n); (i)++) a[i] = read();
    dp();
    if (ans == 0x3f3f3f3f)
      cout << "-1" << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
