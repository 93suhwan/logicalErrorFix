#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    string s, s1;
    cin >> s >> s1;
    bool flag = false, flag1 = true;
    int n = s.size(), n1 = s1.size();
    for (int i = 0; i < n; i++) {
      if (s[i] == s1[0]) {
        flag = true;
        int j, t = 0;
        for (j = 0; j < n1;) {
          if (s[++i] != s1[++j])
            break;
          else
            t++;
        }
        i--, j--;
        int k, l, x = i, y = j;
        while (1) {
          l = y, k = x;
          flag1 = true;
          for (; l < n1 - 1 && k >= 0;) {
            if (s[--k] != s1[++l]) {
              flag1 = false;
              break;
            }
          }
          if (l != n1 - 1) flag1 = false;
          if (flag1)
            break;
          else if (!flag1 && t) {
            t--, y--, x--;
          } else if (!flag1 && t == 0)
            break;
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
