#include <bits/stdc++.h>
using namespace std;
int main() {
  (ios_base::sync_with_stdio(false), cin.tie(NULL));
  ;
  int t;
  cin >> t;
  while (t--) {
    string a, s;
    cin >> a >> s;
    int n = a.length();
    int m = s.length();
    string z = "";
    int i = n - 1, j = m - 1;
    int flag = 0;
    for (; j >= 0; j--) {
      if (i < 0) break;
      int c = int(s[j] - '0');
      int d = int(a[i] - '0');
      if (c >= d) {
        if (c - d < 10)
          z.push_back(char(c - d + '0'));
        else {
          flag = 1;
          break;
        }
      } else {
        j--;
        c += int(s[j] - '0') * 10;
        if (c >= d) {
          if (c - d < 10)
            z.push_back(char(c - d + '0'));
          else {
            flag = 1;
            break;
          }
        }
      }
      i--;
      if (j <= 0 && i >= 0) {
        flag = 1;
        break;
      }
    }
    while (j >= 0) {
      z.push_back(s[j]);
      j--;
    }
    if (flag || i >= 0)
      cout << -1 << endl;
    else {
      int k = z.length() - 1;
      while (z[k] == '0') {
        z.pop_back();
        k--;
      }
      reverse(z.begin(), z.end());
      cout << z << endl;
    }
  }
}
