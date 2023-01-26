#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ll mxn = 1e5 + 7;
void solve() {
  string s, t;
  cin >> s >> t;
  map<char, ll> mp;
  for (ll i = 0; i < 26; i++) mp[s[i]] = i;
  ll ans = 0;
  for (ll i = 1; i < (ll)((t).size()); i++) ans += abs(mp[t[i]] - mp[t[i - 1]]);
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t = 1;
  cin >> t;
  for (ll i = 0; i < t; i++) {
    solve();
  }
}
