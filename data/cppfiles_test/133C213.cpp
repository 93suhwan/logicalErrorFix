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
    for (int i = 0; i < l; i++) {
      if (s[i] != ' ') {
        if (i == 0 || i == 1) {
          ans += s[i];
        } else if (s[i + 1] != ' ' && i != l - 1) {
          if (s[i] == ans.back()) {
            ans += s[i + 1];
          } else {
            ans += s[i];
            ans += s[i + 1];
          }
        }
      }
    }
    while (ans.length() < n) ans += 'a';
    cout << ans << endl;
  }
  return 0;
}
