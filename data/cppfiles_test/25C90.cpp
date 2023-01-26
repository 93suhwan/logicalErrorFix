#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int t;
  cin >> t;
resume:
  while (t--) {
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < s.size(); i++) {
      for (int j = i; j - i < t.size() && j < s.size(); j++) {
        if (i == 2) {
        }
        if (s[j] != t[(j - i)]) break;
        int cnt = (j - i) + 1;
        if (cnt == t.size()) {
          cout << "YES"
               << "\n";
          goto resume;
        }
        for (int k = j - 1; cnt < t.size() && k >= 0; k--) {
          if (t[cnt] != s[k]) break;
          cnt++;
          if (cnt == t.size()) {
            cout << "YES"
                 << "\n";
            goto resume;
          }
        }
      }
    }
    cout << "NO"
         << "\n";
  }
  return 0;
}
