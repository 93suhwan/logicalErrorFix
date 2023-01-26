#include <bits/stdc++.h>
using namespace std;
string s;
int stk[30], tp;
string to_str(int x) {
  string res = "";
  while (x) stk[++tp] = x % 10, x /= 10;
  while (tp) res += stk[tp] ^ '0', tp--;
  return res;
}
int main() {
  cin >> s;
  int n = s.size();
  int b = 1;
  for (int i = 1; i < n; ++i) b *= 10;
  int ans = 0;
  if (s == "0" || s == "_" || s == "X") {
    cout << 1;
    return 0;
  }
  for (int i = b; i < b * 10; i += 25) {
    string res = to_str(i);
    int X = -1;
    bool flag = 1;
    for (int j = 0; j <= n; ++j) {
      if (s[j] != res[j]) {
        if (s[j] == '_')
          continue;
        else if (s[j] == 'X') {
          if (X == -1) {
            X = res[j];
            continue;
          } else {
            if (X == res[j])
              continue;
            else {
              flag = 0;
              break;
            }
          }
        } else {
          flag = 0;
          break;
        }
      }
    }
    ans += flag;
  }
  cout << ans;
  return 0;
}
