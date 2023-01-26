#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  long long int n = s.size();
  map<char, long long int> r, g;
  long long int f = 1;
  for (long long int i = 0; i < n; i++) {
    if (f) {
      if (r.count(s[i]) == 0)
        r[s[i]] = 1, f = 0;
      else if (g.count(s[i]) == 0)
        g[s[i]] = 1, f = 1;
    } else {
      if (g.count(s[i]) == 0)
        g[s[i]] = 1, f = 1;
      else if (r.count(s[i]) == 0)
        r[s[i]] = 1, f = 0;
    }
  }
  cout << min(g.size(), r.size()) << "\n";
  return;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long int t = 1;
  cin >> t;
  for (long long int i = 1; i < t + 1; i++) {
    solve();
  }
  return 0;
}
