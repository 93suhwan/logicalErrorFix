#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    if (s[0] != s[n - 1]) {
      int cnt = 0, cntlast = n - 1;
      while (s[cnt] == s[0]) {
        ++cnt;
      }
      while (s[cntlast] == s[n - 1]) {
        --cntlast;
      }
      if (cnt + 1 < n - cntlast) {
        for (int i = 0; i < n; ++i) {
          if (i < cnt)
            cout << s[n - 1];
          else
            cout << s[i];
        }
      } else {
        for (int i = 0; i < n; ++i) {
          if (i > cntlast)
            cout << s[0];
          else
            cout << s[i];
        }
      }
      cout << endl;
    } else {
      cout << s << endl;
    }
  }
}
