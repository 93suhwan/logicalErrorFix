#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, k;
const int N = 200020;
long long dp[N];
int qpow(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = 1ll * res * x % mod;
    x = 1ll * x * x % mod;
    y >>= 1;
  }
  return res;
}
void solve() {
  cin >> n >> k;
  long long ans = qpow(2, n - 1);
  if (n & 1) {
    int t1 = (qpow(2, n - 1) + 1) % mod;
    cout << qpow(t1, k) << endl;
  } else {
    long long res = 0;
    for (int i = 0; i < k; ++i) {
      res = (res + qpow(ans - 1, i) * qpow(2, k - i - 1)) % mod;
    }
    res = (res + qpow(ans - 1, k)) % mod;
    cout << res << endl;
  }
}
int T = 1;
signed main() {
  cin >> T;
  while (T--) solve();
  return 0;
}
