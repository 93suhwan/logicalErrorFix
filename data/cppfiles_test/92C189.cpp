#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
void solve() {
  string s;
  cin >> s;
  int n = s.length();
  if (s[0] == s[n - 1]) {
    cout << s << "\n";
    return;
  } else if (s[0] == 'a') {
    s[0] = 'b';
    cout << s << "\n";
    return;
  } else {
    s[0] = 'a';
    cout << s << "\n";
    return;
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int _t = 1;
  cin >> _t;
  for (int t = 1; t <= _t; t++) {
    solve();
  }
  return 0;
}
