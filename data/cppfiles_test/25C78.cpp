#include <bits/stdc++.h>
using namespace std;
long long int M = 1e9 + 7;
long long int solve() {
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < s.length(); i++) {
    for (int j = i; j < s.length(); j++) {
      int rem = t.length() - (j - i + 1);
      if (j - rem < 0 || rem < 0) continue;
      string k = s.substr(j - rem, rem);
      reverse(k.begin(), k.end());
      if (s.substr(i, j - i + 1) + k == t) {
        cout << "YES\n";
        return 0;
      }
    }
  }
  cout << "NO\n";
}
int main() {
  long long int tc = 1;
  cin >> tc;
  while (tc--) solve();
}
