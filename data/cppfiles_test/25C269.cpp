#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
const long long inf = 4e18;
const long long N = 2e6;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    string s, p;
    cin >> s >> p;
    bool boob = 0;
    for (long long i = 0; i <= p.length(); i++) {
      string k(p, 0, i);
      string k0;
      for (long long j = i; j < p.length(); j++) k0.push_back(p[j]);
      for (long long j = 0; j <= s.length() - i; j++) {
        if (i > s.length() - j) break;
        string l(s, j, i);
        if (l != k || j + i - 1 < p.length() - i) continue;
        string l0;
        for (long long m = j + i - 2;; m--) {
          if (l0.length() == p.length() - i) break;
          l0.push_back(s[m]);
        }
        if (l0 == k0) boob = 1;
      }
    }
    if (boob)
      cout << "yes\n";
    else
      cout << "no\n";
  }
}
