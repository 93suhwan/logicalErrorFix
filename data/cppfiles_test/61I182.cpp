#include <bits/stdc++.h>
using namespace std;
using PII = pair<long long, long long>;
const long long N = 10000, M = 6000, mod = 998244353, INF = 0x3f3f3f3f;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n), b(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    --a[i];
    --b[i];
  }
  for (auto &x : a) cout << x << endl;
  for (auto &x : b) cout << x << endl;
  vector<long long> ca(n), cb(n);
  for (long long i = 0; i <= n - 1; i++) ++ca[a[i]], ++cb[b[i]];
  long long ans = n * (n - 1) * (n - 2) / 6;
  for (long long i = 0; i <= n - 1; i++) ans -= (ca[a[i]] - 1) * (cb[b[i]] - 1);
  cout << ans << endl;
}
signed main() {
  cout.tie(0)->sync_with_stdio(0);
  long long _;
  for (cin >> _; _--;) solve();
  return 0;
}
