#include <bits/stdc++.h>
using namespace std;
int mod = 998244353;
const int N = 505;
int fac[N], inv_fac[N];
int mod_pow(int b, int p) {
  int ans = 1;
  while (p) {
    if (p & 1) {
      ans = (1ll * ans * b) % mod;
      p--;
    }
    b = (1ll * b * b) % mod;
    p /= 2;
  }
  return ans;
}
void calc_fac() {
  fac[0] = 1;
  inv_fac[0] = 1;
  for (int i = 1; i < 505; i++) {
    fac[i] = (1ll * fac[i - 1] * i) % mod;
    inv_fac[i] = mod_pow(fac[i], mod - 2);
  }
}
int nCr(int n, int r) {
  if (r > n) {
    return 0;
  }
  return 1ll * fac[n] * inv_fac[n - r] % mod * inv_fac[r] % mod;
}
void solve() {
  int n, x;
  cin >> n >> x;
  vector<vector<int>> power(x + 5, vector<int>(n + 5));
  for (int i = 1; i <= x; i++) {
    power[i][0] = 1;
    for (int j = 1; j <= n; j++) {
      power[i][j] = 1ll * power[i][j - 1] * i % mod;
    }
  }
  vector<vector<int>> dp(n + 5, vector<int>(x + 5));
  for (int nums = 2; nums <= n; nums++) {
    for (int lim = 1; lim <= x; lim++) {
      if (lim < nums) {
        dp[nums][lim] = power[lim][nums];
      } else {
        dp[nums][lim] = power[nums - 1][nums];
        for (int killed = 0; killed < nums; killed++) {
          int alive = nums - killed;
          dp[nums][lim] = (dp[nums][lim] + 1ll * dp[alive][lim - (nums - 1)] *
                                               nCr(nums, killed) % mod *
                                               power[nums - 1][killed] % mod) %
                          mod;
        }
      }
    }
  }
  cout << dp[n][x] << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  calc_fac();
  solve();
  return 0;
}
