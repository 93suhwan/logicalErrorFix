#include <bits/stdc++.h>
using namespace std;
int t, l;
string s, ans;
int main() {
  cin >> t;
  while (t--) {
    cin >> s;
    l = s.length();
    if (l % 2 == 1)
      cout << "NO" << endl;
    else {
      bool p = false;
      for (int i = 0; i < l / 2; i++) {
        if (s[l / 2 + i] != s[i]) {
          p = true;
        }
      }
      if (p)
        ans = "NO";
      else
        ans = "YES";
      cout << ans << endl;
    }
  }
  return 0;
}
