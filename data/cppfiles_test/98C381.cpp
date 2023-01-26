#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pl = pair<ll, ll>;
void solve() {
  string s;
  cin >> s;
  map<char, ll> m;
  for (ll i = 0; i <= 25; i++) {
    m[s[i]] = i + 1;
  }
  string d;
  cin >> d;
  ll ans = 0;
  for (ll i = 1; i <= d.length() - 1; i++) {
    ans += abs(m[d[i]] - m[d[i - 1]]);
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
}
