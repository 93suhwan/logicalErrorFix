#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  string s[101];
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n - 2; i++) {
      cin >> s[i];
    }
    if (n - 2 == 1) {
      cout << s[0] + "a"
           << "\n";
    } else {
      string ans = s[0];
      for (int i = 0; i < n - 3; i++) {
        if (s[i][1] == s[i + 1][0]) {
          ans += s[i + 1][1];
        } else {
          ans += s[i + 1];
        }
      }
      if (ans.length() == n)
        cout << ans << "\n";
      else
        cout << ans + "a"
             << "\n";
    }
  }
  return 0;
}
