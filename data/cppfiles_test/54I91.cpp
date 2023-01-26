#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 3e5 + 5;
int f[N], inv[N], n, k, XOR, dp[N];
int pow(int a, int b) {
  int res = 1;
  while (b) {
    if (b % 2) {
      res = 1ll * res * a % MOD;
    }
    a = 1ll * a * a % MOD;
    b /= 2;
  }
  return res;
}
void precompute() {
  f[1] = 1;
  for (int i = 2; i < N; ++i) {
    f[i] = 1ll * f[i - 1] * i % MOD;
  }
  inv[N - 1] = pow(f[N - 1], MOD - 2);
  for (int i = N - 2; i >= 0; --i) {
    inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
  }
}
int nCr(int x, int y) {
  return x - y >= 0 ? 1ll * f[x] * inv[y] % MOD * inv[x - y] % MOD : 0;
}
int go(int bit) {
  if (bit == k) {
    return 1;
  }
  if (dp[bit] != -1) {
    return dp[bit];
  }
  int cnt = 0;
  if (n % 2 == 0) {
    cnt = (cnt + pow(2, k - bit - 1)) % MOD;
  }
  if (n % 2) {
    cnt = (cnt + go(bit + 1)) % MOD;
  }
  cnt = (cnt + 1ll * XOR * go(bit + 1)) % MOD;
  return dp[bit] = cnt;
}
void solve() {
  cin >> n >> k;
  memset(dp, -1, sizeof(dp));
  XOR = 0;
  for (int i = 0; i < n; i += 2) {
    XOR = (XOR + nCr(n, i)) % MOD;
  }
  cout << go(0) << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  precompute();
  int t = 1;
  cin >> t;
  int i = 1;
  while (t--) {
    solve();
  }
  return 0;
}
