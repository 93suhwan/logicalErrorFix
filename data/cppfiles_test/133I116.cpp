#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    char s[n - 1][2];
    string ans;
    if (n == 3) {
      cin >> ans;
      cout << ans << ans.back() << '\n';
      ans.clear();
      continue;
    }
    int m = -1;
    for (int i = 0; i < n - 2; i++) {
      cin >> s[i];
      if (i == 0) {
        ans.push_back(s[0][0]);
        continue;
      }
      if (s[i][0] != s[i - 1][1]) {
        ans.push_back(s[i - 1][1]);
        ans.push_back(s[i][0]);
        m = i;
      }
      if (i == (n - 3)) {
        if (m == i) {
          ans.push_back(s[i][1]);
        } else {
          ans.push_back(s[i][0]);
          ans.push_back(s[i][1]);
        }
        break;
      }
      if (s[i][0] == s[i - 1][1]) ans.push_back(s[i][0]);
      continue;
    }
    if (m == -1) {
      cout << ans << ans.back() << '\n';
      ans.clear();
      continue;
    }
    cout << ans << "\n";
    ans.clear();
  }
  return 0;
}
