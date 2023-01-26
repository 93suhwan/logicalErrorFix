#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s.length() & 1) {
      cout << "NO"
           << "\n";
      continue;
    }
    bool ok = true;
    long long i = 0, j = s.length() / 2;
    while (j < s.length()) {
      if (s[i] != s[j]) {
        ok = false;
        break;
      }
      i++, j++;
    }
    cout << ((ok) ? "YES" : "NO") << "\n";
  }
  return 0;
}
