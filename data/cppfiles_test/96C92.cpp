#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int add(int x, int y) {
  x += y;
  return x >= mod ? x - mod : x;
}
int sub(int x, int y) {
  x -= y;
  return x < 0 ? x + mod : x;
}
int mul(int x, int y) { return (long long)x * y % mod; }
int quick_pow(int x, int k) {
  int ans = 1;
  while (k != 0) {
    if (k & 1) ans = mul(ans, x);
    x = mul(x, x);
    k >>= 1;
  }
  return ans;
}
int inv(int x) { return quick_pow(x, mod - 2); }
const int maxn = 510;
int fac[maxn], ifac[maxn];
void init() {
  int N = maxn - 1;
  fac[0] = fac[1] = 1;
  for (int i = 2; i <= N; i++) fac[i] = mul(fac[i - 1], i);
  ifac[N] = inv(fac[N]);
  for (int i = N - 1; i >= 0; i--) ifac[i] = mul(ifac[i + 1], i + 1);
}
int C(int m, int n) { return mul(fac[m], mul(ifac[n], ifac[m - n])); }
int dp[maxn][maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  init();
  int n, x;
  cin >> n >> x;
  dp[n][0] = 1;
  for (int i = n; i > 1; i--) {
    for (int j = 0; j <= x; j++) {
      int t = min(x, j + i - 1), per = 1;
      for (int k = i; k >= 0; k--) {
        dp[k][t] = add(dp[k][t], mul(mul(C(i, k), per), dp[i][j]));
        per = mul(per, t - j);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= x; i++) ans = add(ans, dp[0][i]);
  cout << ans << '\n';
  return 0;
}
