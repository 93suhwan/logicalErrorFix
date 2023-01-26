#include <bits/stdc++.h>
using namespace std;
const long long N = 2100;
long long T, n, dp[N][N * 2], f[N][N * 2], lim;
char s[N], t[N];
inline void add(long long &a, long long b) {
  a = ((a + b >= 1000000007) ? a + b - 1000000007 : a + b);
}
inline void del(long long &a, long long b) {
  a = ((a - b < 0) ? a - b + 1000000007 : a - b);
}
inline void mul(long long &a, long long b) { a = a * b % 1000000007; }
inline long long m_pow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) mul(ans, a);
    b >>= 1;
    mul(a, a);
  }
  return ans;
}
inline void ckmin(long long &a, long long b) { a = ((a < b) ? a : b); }
inline void ckmax(long long &a, long long b) { a = ((a > b) ? a : b); }
inline long long read() {
  long long f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
signed main() {
  T = read();
  while (T--) {
    n = read();
    scanf("%s%s", s + 1, t + 1);
    for (long long i = 2; i <= n; i += 2) {
      if (s[i] != '?') s[i] = ((s[i] - '0') ^ 1) + '0';
      if (t[i] != '?') t[i] = ((t[i] - '0') ^ 1) + '0';
    }
    long long lim = n;
    for (long long i = 0; i <= n; i++)
      for (long long j = 0; j <= 2 * n; j++) dp[i][j] = f[i][j] = 0;
    dp[0][lim] = 0;
    f[0][lim] = 1;
    for (long long i = 0; i < n; i++) {
      for (long long j = lim - i; j <= lim + i; j++)
        if (f[i][j]) {
          for (long long k = 0; k < 2; k++)
            for (long long p = 0; p < 2; p++) {
              if (s[i + 1] == '0' + (k ^ 1) || t[i + 1] == '0' + (p ^ 1))
                continue;
              long long d = j + k - p;
              add(dp[i + 1][d],
                  (dp[i][j] + abs(j - lim) * f[i][j]) % 1000000007);
              add(f[i + 1][d], f[i][j]);
            }
        }
    }
    printf("%lld\n", dp[n][lim]);
  }
}
