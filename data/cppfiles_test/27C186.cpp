#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  string s, t;
  cin >> q;
  while (q--) {
    cin >> s;
    cin >> t;
    int flag = 0, i, j;
    for (i = s.size() - 1, j = t.size() - 1; i >= 0;) {
      if (s[i] == t[j]) {
        i--;
        j--;
      } else {
        i -= 2;
      }
      if (j == -1) {
        flag = 1;
        break;
      }
    }
    if (flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
