#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
void setIO(string name = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (int((name).size())) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}
void solve() {
  string s;
  cin >> s;
  if (s[0] != s[int((s).size()) - 1]) {
    s[0] = s[int((s).size()) - 1];
  }
  cout << s << '\n';
}
signed main() {
  setIO();
  int t;
  t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
