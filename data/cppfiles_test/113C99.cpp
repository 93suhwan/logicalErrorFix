#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using dbl = double;
using namespace std;
const int N = int(2e5) + 501;
const int MOD = 998244353;
void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto& t : a) cin >> t;
  sort(a.begin(), a.end());
  ll sm = 0;
  for (auto t : a) sm += t;
  int q;
  cin >> q;
  while (q--) {
    ll x, y;
    cin >> x >> y;
    ll who;
    if (lower_bound(a.begin(), a.end(), x) == a.end())
      who = a.back();
    else {
      who = lower_bound(a.begin(), a.end(), x) - a.begin();
      who = a[who];
    }
    ll who2;
    ll ans1 = 1e18;
    if (lower_bound(a.begin(), a.end(), x) != a.begin()) {
      who2 = lower_bound(a.begin(), a.end(), x) - a.begin();
      if (lower_bound(a.begin(), a.end(), x) == a.end())
        who2 -= 2;
      else
        who2--;
      who2 = max(0ll, who2);
      ans1 = 0;
      who2 = a[who2];
      ll need1 = max(0ll, x - who2);
      who2 += need1;
      ans1 += need1;
      ans1 += max(0ll, y - ((sm + need1) - who2));
    }
    ll ans = 0;
    ll need = max(0ll, x - who);
    who += need;
    ans += need;
    ans += max(0ll, y - ((sm + need) - who));
    cout << min(ans, ans1) << '\n';
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int skok = 1;
  for (int t = 1; t <= skok; t++) {
    solve();
  }
}
