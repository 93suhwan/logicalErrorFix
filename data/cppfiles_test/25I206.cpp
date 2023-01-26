#include <bits/stdc++.h>
using namespace std;
long long int M = 1e9 + 7;
long long int solve() {
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < s.length(); i++) {
    string d = t;
    int sindex = i, tindex = 0;
    while (sindex < s.length() && tindex < t.length() &&
           s[sindex] == t[tindex]) {
      d[tindex] = '0';
      sindex++;
      tindex++;
    }
    sindex -= 2;
    while (sindex >= 0 && tindex < t.length() && s[sindex] == t[tindex]) {
      d[tindex] = '0';
      sindex--;
      tindex++;
    }
    bool msn = true;
    for (int j = 0; j < d.length(); j++) {
      if (d[j] != '0') msn = false;
    }
    if (msn) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
}
int main() {
  long long int tc = 1;
  cin >> tc;
  while (tc--) solve();
}
