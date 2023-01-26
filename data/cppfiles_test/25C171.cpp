#include <bits/stdc++.h>
using namespace std;
const long long N = 100005;
void solve() {
  string s, t, r;
  cin >> s >> t;
  long long i, n = s.size(), m = t.size();
  r = t;
  reverse(r.begin(), r.end());
  for (i = 0; i < n; i++) {
    long long j, l = min(n - i, m);
    for (j = 1; j <= l; j++) {
      string x = s.substr(i, j);
      string y = t.substr(0, j);
      if (x == y) {
        x = s.substr(i + j - 1 - min(m - j, i + j - 1), min(m - j, i + j - 1));
        y = r.substr(0, m - j);
        if (x == y) {
          cout << "Yes"
               << "\n";
          return;
        }
      }
    }
  }
  cout << "No"
       << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
