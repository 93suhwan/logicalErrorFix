#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 4010;
const long long INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
const long long mod = 1e9 + 7;
long long T, n, m;
long long dp[MAXN][MAXN], f[MAXN][MAXN];
char s[MAXN], t[MAXN];
template <typename T>
inline bool read(T &a) {
  a = 0;
  char c = getchar();
  long long f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    a = a * 10 + (c ^ 48);
    c = getchar();
  }
  return a *= f, true;
}
template <typename A, typename... B>
inline bool read(A &x, B &...y) {
  return read(x) && read(y...);
}
void solve() {
  read(n);
  scanf("%s%s", s + 1, t + 1);
  for (long long i = 2; i <= n; i += 2) {
    if (s[i] != '?') s[i] = '0' + '1' - s[i];
    if (t[i] != '?') t[i] = '0' + '1' - t[i];
  }
  f[0][0 + n + 1] = 1;
  for (long long i = 1; i <= n; ++i)
    for (long long j = -i, ls, rs, lt, rt; j <= i; ++j) {
      ls = (s[i] == '1') ? 1 : 0, rs = (s[i] == '0') ? 0 : 1;
      lt = (t[i] == '1') ? 1 : 0, rt = (t[i] == '0') ? 0 : 1;
      for (long long a = ls; a <= rs; ++a)
        for (long long b = lt; b <= rt; ++b) {
          if (a == b) {
            (f[i][j + n + 1] += f[i - 1][j + n + 1]) %= mod;
            (dp[i][j + n + 1] += dp[i - 1][j + n + 1]) %= mod;
          }
          if (a && !b) {
            (f[i][j + n + 1] += f[i - 1][j - 1 + n + 1]) %= mod;
            (dp[i][j + n + 1] +=
             dp[i - 1][j - 1 + n + 1] +
             f[i - 1][j - 1 + n + 1] * (j - 1 < 0 ? i : (mod - i))) %= mod;
          }
          if (!a && b) {
            (f[i][j + n + 1] += f[i - 1][j + 1 + n + 1]) %= mod;
            (dp[i][j + n + 1] +=
             dp[i - 1][j + 1 + n + 1] +
             f[i - 1][j + 1 + n + 1] * (j + 1 > 0 ? i : (mod - i))) %= mod;
          }
        }
    }
  printf("%lld\n", dp[n][0 + n + 1]);
  for (long long i = 0; i <= n; ++i)
    for (long long j = -i; j <= i; ++j) dp[i][j + n + 1] = f[i][j + n + 1] = 0;
}
signed main() {
  read(T);
  while (T--) solve();
  return 0;
}
