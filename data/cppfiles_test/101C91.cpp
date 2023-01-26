#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
void solve() {
  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> x(n), y(m);
  for (int i = 0; i < n; i++) cin >> x[i];
  for (int i = 0; i < m; i++) cin >> y[i];
  ll ans = 0;
  vector<map<ll, ll>> xm(n);
  vector<map<ll, ll>> ym(m);
  for (int i = 0; i < k; i++) {
    ll xp, yp;
    cin >> xp >> yp;
    auto it = lower_bound(x.begin(), x.end(), xp);
    ll val = *it;
    if (val != xp) {
      ll pos = it - x.begin();
      xm[pos][yp] += 1;
    }
    it = lower_bound(y.begin(), y.end(), yp);
    val = *it;
    if (val != yp) {
      ll pos = it - y.begin();
      ym[pos][xp] += 1;
    }
  }
  for (int i = 0; i < n; i++) {
    ll s = 0;
    for (auto x : xm[i]) {
      ans -= (x.second * (x.second - 1)) / 2;
      s += x.second;
    }
    ans += (s * (s - 1)) / 2;
  }
  for (int i = 0; i < m; i++) {
    ll s = 0;
    for (auto x : ym[i]) {
      ans -= (x.second * (x.second - 1)) / 2;
      s += x.second;
    }
    ans += (s * (s - 1)) / 2;
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
