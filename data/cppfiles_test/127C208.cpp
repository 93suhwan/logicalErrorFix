#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i, j;
  cin >> t;
  while (t--) {
    string s, t;
    cin >> s >> t;
    if (t != "abc") {
      sort(s.begin(), s.end());
      cout << s << endl;
    } else {
      int a[26] = {0};
      for (i = 0; i < s.size(); i++) a[s[i] - 'a']++;
      if (a[0] > 0 && a[1] > 0 && a[2] > 0) {
        string ans = "";
        for (i = 0; i < 26; i++) {
          if (i == 1) {
            for (j = 0; j < a[2]; j++) ans += 'c';
            for (j = 0; j < a[1]; j++) ans += 'b';
            i++;
          } else {
            for (j = 0; j < a[i]; j++) ans += ('a' + i);
          }
        }
        cout << ans << endl;
      } else {
        sort(s.begin(), s.end());
        cout << s << endl;
      }
    }
  }
}
