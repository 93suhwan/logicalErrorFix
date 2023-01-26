#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chkmax(T &first, T second) {
  first < second ? first = second : T();
}
template <typename T>
void chkmin(T &first, T second) {
  second < first ? first = second : T();
}
template <typename T>
void readint(T &first) {
  first = 0;
  int f = 1;
  char c;
  for (c = getchar(); !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) first = first * 10 + (c - '0');
  first *= f;
}
const int MOD = 998244353;
inline int dmy(int first) { return first >= MOD ? first - MOD : first; }
inline void inc(int &first, int second) {
  (first += second) >= MOD ? first -= MOD : 0;
}
int qmi(int first, int second) {
  int ans = 1;
  for (; second; second >>= 1, first = 1ll * first * first % MOD)
    if (second & 1) ans = 1ll * ans * first % MOD;
  return ans;
}
const int MAXN = 100005;
int n, a[MAXN], dp[2][MAXN];
int m, b[MAXN], fac[MAXN];
int main() {
  readint(m);
  for (int i = 1; i <= m; ++i) readint(b[i]);
  for (int u = 1; u <= m; u += b[u]) {
    if (u + b[u] - 1 > m) return 0 * printf("0\n");
    for (int i = u; i <= u + b[u] - 1; ++i)
      if (b[i] != b[u]) return 0 * printf("0\n");
    a[++n] = (b[u] > 1);
  }
  dp[a[1]][1] = 1 + a[1];
  for (int i = 2; i <= n; ++i)
    if (!a[i]) {
      for (int j = i - 1; j; --j)
        inc(dp[0][j + 1], dp[0][j]), inc(dp[0][j + 1], dp[1][j]),
            inc(dp[1][j], dmy(dp[0][j] << 1)), dp[0][j] = 0;
    } else {
      for (int j = i - 1, u; j; --j)
        u = dmy(dp[0][j] << 1), inc(dp[1][j + 1], u),
        inc(dp[1][j + 1], dmy(dp[1][j] << 1)), inc(dp[1][j], u), dp[0][j] = 0;
    }
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = 1ll * fac[i - 1] * i % MOD;
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    int t = 1ll * fac[i] * (dp[0][i] + dp[1][i]) % MOD;
    if ((n - i) & 1)
      inc(res, MOD - t);
    else
      inc(res, t);
  }
  printf("%d\n", res);
  return 0;
}
