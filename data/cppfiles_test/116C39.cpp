#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T& t) {
  long long c = getchar();
  t = 0;
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) t = (t << 3) + (t << 1) + c - 48, c = getchar();
}
template <typename T, typename... Args>
inline void read(T& t, Args&... args) {
  read(t);
  read(args...);
}
template <typename T>
inline void wrt(T x) {
  if (0 <= x && x < 10) {
    putchar(x + '0');
    return;
  }
  wrt(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
inline void wrt(T x, char c) {
  wrt(x);
  putchar(c);
}
const int mod = 998244353;
const int N = 5e5 + 200;
int n, a[N];
long long dp[N][3], sum[N][3];
long long ans;
void work() {
  ans = 0;
  read(n);
  for (int i = 1; i <= n; ++i) read(a[i]);
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= 2; ++j) dp[i][j] = sum[i][j] = 0;
  for (int i = 1; i <= n; ++i) {
    dp[i][0] = (a[i] == 1) ? 1 : 0;
    dp[i][1] = (a[i] == 0) ? 1 : 0;
    dp[i][2] = 0;
    dp[i][0] = (dp[i][0] + sum[a[i]][0]) % mod;
    if (a[i] >= 2)
      dp[i][0] = (dp[i][0] + sum[a[i] - 2][1]) % mod,
      dp[i][0] = (dp[i][0] + sum[a[i] - 2][2]) % mod;
    if (a[i] >= 1) dp[i][1] = (dp[i][1] + sum[a[i] - 1][1]) % mod;
    dp[i][1] = (dp[i][1] + sum[a[i]][1]) % mod;
    dp[i][2] = (dp[i][2] + sum[a[i]][2]) % mod;
    if (a[i] + 2 <= n) dp[i][2] = (dp[i][2] + sum[a[i] + 2][0]) % mod;
    sum[a[i]][0] = (sum[a[i]][0] + dp[i][0]) % mod;
    sum[a[i]][2] = (sum[a[i]][2] + dp[i][2]) % mod;
    sum[a[i]][1] = (sum[a[i]][1] + dp[i][1]) % mod;
    ans = (ans + dp[i][0]) % mod;
    ans = (ans + dp[i][1]) % mod;
    ans = (ans + dp[i][2]) % mod;
  }
  wrt(ans, '\n');
  return;
}
int T;
int main() {
  read(T);
  while (T--) work();
  return 0;
}
