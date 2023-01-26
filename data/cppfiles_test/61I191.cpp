#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
const int N = 10000, M = 6000, mod = 998244353, INF = 0x3f3f3f3f;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto &x : a) cin >> x, --x;
  for (auto &x : b) cin >> x, --x;
  vector<int> ca(n), cb(n);
  for (int i = 0; i <= n - 1; i++) ++ca[a[i]], ++cb[b[i]];
  long long ans = 1ll * n * (n - 1) * (n - 2) / 6;
  for (int i = 0; i <= n - 1; i++) ans -= 1ll * (ca[a[i]] - 1) * (cb[b[i]] - 1);
  cout << ans << endl;
}
signed main() {
  cout.tie(0)->sync_with_stdio(0);
  int _;
  for (cin >> _; _--;) solve();
  return 0;
}
