#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
const ll RANDOM =
    chrono::high_resolution_clock::now().time_since_epoch().count();
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void file() {
  {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
  };
  if (fopen(""
            ".inp",
            "r")) {
    freopen(
        ""
        ".inp",
        "r", stdin);
    freopen(
        ""
        ".out",
        "w", stdout);
  }
}
void solve() {
  string s;
  cin >> s;
  int n = s.size();
  s = ' ' + s;
  int rem1 = 5, rem2 = 5;
  int score1 = 0, score2 = 0;
  int ans = 10;
  for (int i = 1; i <= n; ++i) {
    if (score2 > score1 + rem1 || score1 > score2 + rem2) {
      ans = min(ans, 10 - rem1 - rem2);
      break;
    }
    if (i % 2) {
      if (s[i] == '1') ++score1;
      if (s[i] == '?') ++score1;
      --rem1;
    } else {
      if (s[i] == '1') ++score2;
      --rem2;
    }
  }
  score1 = score2 = 0, rem1 = rem2 = 5;
  for (int i = 1; i <= n; ++i) {
    if (score2 > score1 + rem1 || score1 > score2 + rem2) {
      ans = min(ans, 10 - rem1 - rem2);
      break;
    }
    if (i % 2) {
      if (s[i] == '1') ++score1;
      --rem1;
    } else {
      if (s[i] == '1' || s[i] == '?') ++score2;
      --rem2;
    }
  }
  cout << ans << '\n';
}
int main() {
  file();
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
