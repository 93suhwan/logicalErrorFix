#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7, N = 1e5 + 10;
const ll MX = 1e8;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  ll ans = 0;
  for (ll i = 0; i < MX; i += 25) {
    string k = to_string(i);
    if (k.length() != s.length()) continue;
    set<ll> se;
    ll bad = 1;
    for (ll j = 0; j < k.length(); j++) {
      if (s[j] == '_') continue;
      if (s[j] == 'X') se.insert(k[j] - '0');
      if (s[j] != k[j]) bad = 0;
    }
    ans += (se.size() <= 1 and bad);
  }
  cout << ans << '\n';
  return 0;
}
