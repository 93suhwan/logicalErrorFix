#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    string s, s1;
    cin >> s >> s1;
    bool flag = false, flag1 = false;
    int n = s.size(), n1 = s1.size();
    for (int i = 0; i < n; i++) {
      if (s[i] == s1[0]) {
        int pos = 0;
        flag = true;
        for (int j = i; j < n && pos < n1; j++, pos++) {
          if (s[j] != s1[pos]) break;
          for (int k = pos, l = j; k < n1 && l >= 0; k++, l--) {
            if (k == n1 - 1 && s1[k] == s[l]) {
              flag1 = true;
              break;
            }
            if (s1[k] != s[l]) break;
          }
          if (flag && flag1) break;
        }
      }
      if (flag && flag1) break;
    }
    if (flag && flag1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
