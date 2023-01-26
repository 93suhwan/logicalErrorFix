#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cin.ignore();
    string s;
    getline(cin, s);
    int l = s.length();
    string ans = "";
    map<char, bool> m;
    for (int i = 0; i < l; i++) {
      if (s[i] != ' ') {
        if (i == 0 || i == 1 || i == l - 1 || i == l - 2) {
          ans += s[i];
          m[s[i]] = 1;
        } else if (s[i + 1] != ' ') {
          if (m[s[i]] == 1) {
            ans += s[i + 1];
            m[s[i + 1]] = 1;
          } else {
            ans += s[i];
            m[s[i]] = 1;
          }
        }
      }
    }
    while (ans.length() < n) ans += 'a';
    cout << ans << endl;
  }
  return 0;
}
