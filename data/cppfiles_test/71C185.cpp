#include <bits/stdc++.h>
using namespace std;
const int MAXN = 40000;
const int MOD = 1e6;
string str;
string solve() {
  int k;
  cin >> str >> k;
  if (k == 1) {
    if (string(str.size(), str[0]) >= str)
      return string(str.size(), str[0]);
    else
      return string(str.size(), str[0] + 1);
  } else {
    char ch1 = str[0];
    bool fg;
    string ans, res = string(str.size(), '9');
    for (char ch2 = '0'; ch2 <= '9'; ++ch2) {
      fg = 0;
      ans.clear();
      ans += ch1;
      char mi = min(ch2, ch1), ma = max(ch2, ch1);
      int i;
      for (i = 1; i < str.size(); ++i) {
        if (mi > str[i]) {
          ans += string(str.size() - i, mi);
          fg = 1;
          break;
        } else if (mi == str[i]) {
          ans += mi;
        } else {
          if (ma > str[i]) {
            ans += ma;
            ans += string(str.size() - i - 1, mi);
            fg = 1;
            break;
          } else if (ma == str[i]) {
            ans += ma;
          } else {
            if (ma == mi)
              break;
            else if (i == 1) {
              break;
            } else {
              ans += string(str.size() - i, mi);
              for (int j = i - 1; j >= 1; --j) {
                if (ans[j] == mi) {
                  ans[j] = ma;
                  fg = 1;
                  break;
                } else
                  ans[j] = mi;
              }
              break;
            }
          }
        }
      }
      if ((fg || i == str.size()) && ans < res) res = ans;
    }
    return res;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << solve() << '\n';
  }
  return 0;
}
