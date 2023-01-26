#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s, t;
  cin >> s >> t;
  long long ns = s.size(), nt = t.size();
  for (long long i = 0; i < ns; i++) {
    for (long long j = i; j < ns; j++) {
      string x = s.substr(i, j - i);
      long long len = nt - j + i;
      if (len <= j + 1 && len >= 0) {
        string y = s.substr(j - len + 1, len);
        reverse(y.begin(), y.end());
        if (x + y == t) {
          puts("YES");
          return;
        }
      }
    }
  }
  puts("NO");
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
