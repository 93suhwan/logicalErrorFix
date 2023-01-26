#include <bits/stdc++.h>
using namespace std;
int t;
int n;
string s[200], ans;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    ans = "";
    bool check = false;
    for (int i = 1; i <= n - 2; ++i) {
      cin >> s[i];
      if (i > 1) {
        if (s[i][0] != s[i - 1][1]) check = true;
      }
    }
    if (n == 3) {
      if (s[1][0] == 'a')
        cout << 'b' << s[1] << endl;
      else
        cout << 'a' << s[1] << endl;
      continue;
    }
    if (check == false) {
      int w = 0;
      ans += s[1];
      for (int i = 2; i <= n - 2; ++i) {
        ans += s[i][1];
      }
      if (s[n - 2][1] == 'a')
        ans += 'b';
      else
        ans += 'a';
      cout << ans << endl;
      continue;
    }
    ans += s[1];
    int w = 0;
    for (int i = 2; i <= n - 2; ++i) {
      if (w == 0 && s[i][0] == s[i][1] && s[i][0] == s[i - 1][1] &&
          s[i][1] == s[i + 1][0]) {
        ans += s[i + 1];
        i++;
      } else if (s[i - 1][1] == s[i][0])
        ans += s[i][0];
      else {
        ans += s[i];
      }
    }
    cout << ans << endl;
  }
  return 0;
}
