#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s, t;
  cin >> s >> t;
  int64_t n = s.size(), m = t.size();
  int64_t prv = -1, j = m - 1;
  for (int64_t i = n - 1; i >= 0; --i) {
    if (j == m - 1 && (n - 1 - i) % 2 != 0) continue;
    if (s[i] == t[j] && (prv == -1 || (prv - i) % 2 == 0)) {
      if (--j < 0) {
        cout << "YES\n";
        return;
      }
      prv = i - 1;
    }
  }
  cout << "NO\n";
}
signed main() {
  int64_t tc = 1;
  cin >> tc;
  for (int64_t i = 1; i <= tc; ++i) {
    solve();
  }
}
