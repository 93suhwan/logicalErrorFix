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
  if (s.length() < 2) return cout << (s == "0"), 0;
  reverse(begin(s), end(s));
  ll ans = 0;
  auto match = [&](string a, string b) {
    ll x = (a[0] == '_' or a[0] == b[0]);
    ll y = (a[1] == '_' or a[1] == b[1]);
    return x & y;
  };
  for (ll i = 0; i < 10; ++i) {
    string t = s;
    for (char &c : t) {
      c = (c == 'X' ? i + '0' : c);
    }
    ll ways = 1;
    if (t.back() == '0') continue;
    for (ll i = 2; i < t.length(); ++i) {
      if (t[i] == '_') ways *= 10;
    }
    if (t.back() == '_') ways = ways * 9 / 10;
    if (match(t.substr(0, 2), "00")) ans += ways;
    if (match(t.substr(0, 2), "52")) ans += ways;
    if (match(t.substr(0, 2), "57")) ans += ways;
    if (match(t.substr(0, 2), "05")) ans += ways;
    if (count(begin(s), end(s), 'X') == 0) break;
  }
  cout << ans << '\n';
  return 0;
}
