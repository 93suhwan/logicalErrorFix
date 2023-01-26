#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s[0] == 'a') {
      bool flag = false;
      for (int i = 1; i < s.size(); i++) {
        if (s[i] == 'b') flag = true;
        if (s[i] == 'a') flag = false;
      }
      if (flag = true) {
        s[s.size() - 1] = 'a';
      }
    } else {
      bool flag = false;
      for (int i = 1; i < s.size(); i++) {
        if (s[i] == 'a') flag = true;
        if (s[i] == 'b') flag = false;
      }
      if (flag = true) {
        s[s.size() - 1] = 'b';
      }
    }
    cout << s << endl;
  }
  return 0;
}
