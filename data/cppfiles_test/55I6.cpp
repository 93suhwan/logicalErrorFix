#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
long long mu(long long a, long long b) {
  if (b == 0) return 1;
  long long t = mu(a, b / 2);
  t = (t * t) % MOD;
  if (b & 1) t = (t * a) % MOD;
  return t;
}
long long t, n, k, gt[N], inv[N], d[N], f[N];
long long P(int k, int n) {
  if (k > n) return 0;
  return (gt[n] * inv[n - k]) % MOD;
}
long long C(int k, int n) {
  if (k > n) return 0;
  return ((gt[n] * inv[k]) % MOD * inv[n - k]) % MOD;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long m = 2e5;
  gt[0] = 1;
  for (int i = 1; i <= m; ++i) gt[i] = (gt[i - 1] * i) % MOD;
  inv[m] = mu(gt[m], MOD - 2);
  for (int i = m - 1; i >= 0; --i) inv[i] = (inv[i + 1] * (i + 1)) % MOD;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    long long res1 = 0, res2 = 0;
    for (int i = 0; i <= n; ++i)
      if (i & 1)
        res1 = (res1 + C(i, n)) % MOD;
      else
        res2 = (res2 + C(i, n)) % MOD;
    if (n & 1) {
      cout << mu(res2 + 1, k) << '\n';
    } else {
      long long ans = 0;
      for (int i = 1; i <= k; ++i) {
        long long res = 1;
        res = (res * mu(res2 - 1, i - 1)) % MOD;
        res = (res * mu(2, n * (k - i))) % MOD;
        ans = (ans + res) % MOD;
      }
      ans = (ans + mu(res2 - 1, k)) % MOD;
      cout << ans << '\n';
    }
  }
}
