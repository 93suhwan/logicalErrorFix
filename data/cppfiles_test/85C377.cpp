#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int ans = 0;
    int p = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '0') {
        if (p == 0) p = 1;
      } else {
        if (p == 1) {
          p = 0;
          ans++;
        }
      }
    }
    if (p == 1) {
      ans++;
    }
    cout << min(ans, 2) << endl;
  }
}
