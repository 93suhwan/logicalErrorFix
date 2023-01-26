#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string n;
void solve1() {
  ll len = n.size();
  for (char c = '1'; c <= '9'; ++c) {
    string ans = "";
    for (ll i = 1; i <= len; ++i) ans += c;
    if (ans >= n) {
      cout << ans << '\n';
      return;
    }
  }
}
void solve2() {
  ll len = n.size();
  string res;
  for (char c = '1'; c <= '9'; ++c) {
    string ans = "";
    for (ll i = 1; i <= len; ++i) ans += c;
    if (ans >= n) {
      res = ans;
      break;
    }
  }
  for (char a = '0'; a <= '9'; ++a) {
    for (char b = a + 1; b <= '9'; ++b) {
      bool ok = 1;
      for (ll i = 0; i < len; ++i) {
        if (n[i] < b) {
          string ans = n;
          if (n[i] < a)
            ans[i] = a;
          else
            ans[i] = b;
          for (ll j = i + 1; j < len; j++) ans[j] = a;
          if (ans < res) res = ans;
        }
        if (n[i] != a && n[i] != b) {
          ok = 0;
          break;
        }
      }
      if (ok) {
        cout << n << '\n';
        return;
      }
    }
  }
  cout << res << '\n';
  return;
}
void solve() {
  ll k;
  cin >> n;
  cin >> k;
  if (k == 1)
    solve1();
  else
    solve2();
}
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ll t;
  cin >> t;
  while (t--) solve();
}
