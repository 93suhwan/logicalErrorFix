#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s.size() % 2 == 1)
      cout << "NO"
           << "\n";
    else {
      bool nl = true;
      for (long long i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() / 2 + i]) {
          nl = false;
          break;
        }
      }
      if (nl)
        cout << "YES"
             << "\n";
      else
        cout << "NO"
             << "\n";
    }
  }
  return 0;
}
