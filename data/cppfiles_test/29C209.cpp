#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
const int MOD = 998244353;
void solve() {
  int n;
  cin >> n;
  vector<ll> v(n);
  int cnt0 = 0, cnt1 = 0;
  for (auto &x : v) {
    cin >> x;
    if (x == 0) cnt0++;
    if (x == 1) cnt1++;
  }
  ll ans = cnt1 * (1LL << cnt0);
  cout << ans << "\n";
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
