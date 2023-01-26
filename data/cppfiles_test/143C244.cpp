#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  ll n;
  cin >> n;
  ll a[n];
  map<ll, ll> m;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    m[a[i]]++;
  }
  sort(a, a + n);
  if (a[0] == 0)
    cout << m[0] << " ";
  else
    cout << "0 ";
  ll x = m[0];
  ll e = 0;
  ll ne = 0;
  vector<pair<ll, ll>> v;
  if (m[0] > 1) v.push_back({0, m[0] - 1});
  for (ll i = 1; i <= n; i++) {
    if (i > x) {
      while (i <= n) {
        cout << "-1 ";
        i++;
      }
      cout << endl;
      return;
    }
    if (m[i] > 1) v.push_back({i, m[i] - 1});
    cout << m[i] + e << " ";
    if (m[i] == 0) {
      ll it = v.size() - 1;
      if (it != -1) {
        ll x = v[it].first;
        e = e + i - x;
        v[it].second--;
        if (v[it].second == 0) v.pop_back();
      }
    }
    x = x + m[i];
  }
  cout << endl;
  return;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
