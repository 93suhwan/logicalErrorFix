#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    ll d[n];
    for (auto &i : d) cin >> i;
    vector<pair<ll, ll>> ans;
    ll m1 = max_element(d, d + n) - d, t = d[m1];
    d[m1] = 0;
    ll m2 = max_element(d, d + n) - d;
    d[m1] = t;
    while (d[m2] > 0 && m1 != m2) {
      d[m2]--;
      ans.emplace_back(m2, m1);
      m1 = max_element(d, d + n) - d;
      t = d[m1] - 1;
      d[m1] = 0;
      m2 = max_element(d, d + n) - d;
      d[m1] = t;
    }
    cout << ans.size() << endl;
    for (auto i : ans) cout << i.first + 1 << ' ' << i.second + 1 << endl;
  }
}
