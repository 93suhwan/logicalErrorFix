#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
const long long Inf = 1ll << 60ll;
namespace io {
char buf[(1 << 23)], *p1 = buf, *p2 = buf, c;
int f;
template <typename T>
T read() {
  T x = 0;
  f = 0;
  c = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, (1 << 23), stdin), p1 == p2)
           ? EOF
           : *p1++);
  while (!isdigit(c))
    (c == '-') && (f = 1),
        c = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, (1 << 23), stdin),
                          p1 == p2)
                 ? EOF
                 : *p1++);
  while (isdigit(c))
    x = x * 10 + (c & 15),
    c = (p1 == p2 &&
                 (p2 = (p1 = buf) + fread(buf, 1, (1 << 23), stdin), p1 == p2)
             ? EOF
             : *p1++);
  return f ? -x : x;
}
}  // namespace io
const int N = 505;
int n, m, kmp[N], dp[N][N][N], nxt[N][N];
char a[N], b[N];
void upt(int& x, int y) { x = min(x, y); }
int main() {
  scanf("%d%d", &n, &m);
  scanf("%s", a + 1);
  scanf("%s", b + 1);
  for (int i = 2, j = 0; i <= m; ++i) {
    while (j && b[i] != b[j + 1]) j = kmp[j];
    if (b[i] == b[j + 1]) ++j;
    kmp[i] = j;
  }
  memset(dp, 0x3f, sizeof(dp));
  for (int i = 1, j = 0, match = 0; i <= n; ++i) {
    while (j && b[j + 1] != a[i]) j = kmp[j];
    if (a[i] == b[j + 1]) ++j;
    if (j == m) {
      ++match;
      j = kmp[j];
    }
    dp[i][match][j] = 0;
  }
  dp[0][0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < min(m, i); ++j) {
      int t = j, c = b[j + 1] ^ 1;
      while (t && b[t + 1] != c) t = kmp[t];
      if (b[t + 1] == c) ++t;
      nxt[i][j] = t;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= max(i - m + 1, 0); ++j) {
      for (int k = 0; k < m; ++k) {
        upt(dp[i + 1][j + (k == m - 1)][k == m - 1 ? kmp[m] : k + 1],
            dp[i][j][k] + (a[i + 1] != b[k + 1]));
        upt(dp[i + 1][j][nxt[i][k]], dp[i][j][k] + (a[i + 1] == b[k + 1]));
      }
    }
  }
  for (int i = 0; i <= n - m + 1; ++i) {
    int t = inf;
    for (int j = 0; j < m; ++j) t = min(t, dp[n][i][j]);
    if (t > n)
      printf("-1 ");
    else
      printf("%d ", t);
  }
  return 0;
}
