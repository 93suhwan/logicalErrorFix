#include <bits/stdc++.h>
using std::cin;
using std::cout;
const int N = 16, N2 = 16400, mod = 1000000007;
int n, ALL;
int a[N];
int prob[N2];
int G[N][N], cr[N][N2];
long long PowerMod(long long a, int n, long long c = 1) {
  for (; n; n >>= 1, a = a * a % mod)
    if (n & 1) c = c * a % mod;
  return c;
}
int cross(int A, int B) {
  int ret = 1;
  for (; A; A &= A - 1) ret = (long long)ret * cr[__builtin_ctz(A)][B] % mod;
  return ret;
}
int main() {
  int i, j, ans = 0;
  std::ios::sync_with_stdio(false), cin.tie(nullptr);
  cin >> n, ALL = ~(-1 << n);
  for (i = 0; i < n; ++i) cin >> a[i];
  for (i = 0; i < n; ++i)
    for (j = 0; j < n; ++j) G[i][j] = PowerMod(a[i] + a[j], mod - 2, a[i]);
  for (i = 0; i < n; ++i) {
    *cr[i] = 1;
    for (j = 1; j <= ALL; ++j)
      cr[i][j] = (long long)cr[i][j & (j - 1)] * G[i][__builtin_ctz(j)] % mod;
  }
  for (i = 1; i <= ALL; ++i) {
    prob[i] = 1;
    for (j = i & (i - 1); j; j = (j - 1) & i)
      prob[i] = (prob[i] - (long long)prob[j] * cross(j, i - j)) % mod;
    prob[i] = (prob[i] + mod) % mod;
    ans = (ans + (long long)prob[i] * cross(i, ALL - i) % mod *
                     __builtin_popcount(i)) %
          mod;
  }
  cout << ans << '\n';
  return 0;
}
