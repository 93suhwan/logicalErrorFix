#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
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
  for (int i = 1; i < N; i++) {
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
  int n, k;
  cin >> n >> k;
  vector<vector<int>> POW(n + 5, vector<int>(k + 5));
  for (int i = 1; i < n + 5; i++) {
    POW[i][0] = 1;
    for (int j = 1; j < k + 5; j++) {
      POW[i][j] = POW[i][j - 1] * i % mod;
    }
  }
  vector<vector<int>> dp(n + 5, vector<int>(k + 5));
  for (int initial_alive = 2; initial_alive < n + 5; initial_alive++) {
    for (int limit = 1; limit < k + 5; limit++) {
      if (limit < initial_alive) {
        dp[initial_alive][limit] = POW[limit][initial_alive];
      } else {
        dp[initial_alive][limit] = POW[initial_alive - 1][initial_alive];
        dp[initial_alive][limit] =
            (0ll + dp[initial_alive][limit] +
             dp[initial_alive][limit - (initial_alive - 1)]) %
            mod;
        for (int alive = 1; alive < initial_alive; alive++) {
          int killed = initial_alive - alive;
          dp[initial_alive][limit] =
              (0ll + dp[initial_alive][limit] +
               1ll * nCr(initial_alive, alive) % mod *
                   POW[initial_alive - 1][killed] % mod *
                   dp[alive][limit - (initial_alive - 1)]) %
              mod;
        }
      }
    }
  }
  cout << dp[n][k] << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  calc_fac();
  solve();
  return 0;
}
