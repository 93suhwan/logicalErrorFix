#include <bits/stdc++.h>
using namespace std;
const long long N = 4e5 + 5;
void solve() {
  string s, t;
  cin >> s >> t;
  long long n = s.size();
  long long m = t.size();
  for (long long i = 0; i < n; i++) {
    string l;
    l.push_back(s[i]);
    for (long long j = i; j < n; j++) {
      if (j != i) l.push_back(s[j]);
      string p = l;
      for (long long k = j; k >= 0; k--) {
        if (k != j) p.push_back(s[k]);
        if (p.length() == m && p == t) {
          cout << "YES"
               << "\n";
          return;
        }
      }
    }
  }
  cout << "NO"
       << "\n";
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
