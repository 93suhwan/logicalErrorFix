#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s[n - 2];
    for (int i = 0; i < n - 2; i++) {
      cin >> s[i];
    }
    if (n == 3) {
      cout << "b" << s[0] << endl;
      continue;
    }
    string ans = "";
    bool fl = 0;
    for (int i = 0; i < n - 3; i++) {
      if (i == 0)
        ans += s[i];
      else
        ans += s[i][1];
      if (s[i][1] != s[i + 1][0]) {
        ans += s[i + 1][0];
        fl = 1;
      }
    }
    ans += s[n - 3][1];
    if (!fl) ans += s[n - 3][1];
    cout << ans << endl;
  }
}
