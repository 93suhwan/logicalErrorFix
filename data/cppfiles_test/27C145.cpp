#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s, t;
  cin >> s >> t;
  reverse(s.begin(), s.end());
  reverse(t.begin(), t.end());
  long long x = 0;
  for (long long i = 0; i < t.size(); i++) {
    while (x < s.size() && s[x] != t[i]) x += 2;
    if (x >= s.size()) {
      cout << "NO" << endl;
      return;
    }
    s.erase(s.begin() + x);
  }
  cout << "YES" << endl;
  return;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
