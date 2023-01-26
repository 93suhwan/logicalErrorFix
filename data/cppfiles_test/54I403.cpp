#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int nax = 2e5;
int T, n, k;
ll qexp(int a, int b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
void solve() {
  cin >> n >> k;
  ll ans = 1, pre = 1;
  if (n & 1) {
    for (int i = k - 1; ~i; i -= 1) {
      ans = ans * (1 + qexp(2, n - 1)) % mod;
    }
  } else {
    for (int i = k - 1; ~i; i -= 1) {
      ans = (ans + pre * qexp(qexp(2, n), i) % mod) % mod;
      pre = pre * (qexp(2, n - 1) - 1 + mod) % mod;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  while (T--) solve();
  return 0;
}
