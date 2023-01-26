#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, s;
    cin >> a >> s;
    int f = 0;
    string ans = "";
    while (a != 0) {
      long long int d = a % 10;
      long long int d1 = s % 10;
      if (d <= d1)
        ans = to_string(d1 - d) + ans;
      else {
        s = s / 10;
        long long int d2 = s % 10;
        if (d2 <= 0) {
          f = 1;
          break;
        } else {
          d1 = d2 * 10 + d1;
          if (d1 - d > 9) {
            f = 1;
            break;
          }
          ans = to_string(d1 - d) + ans;
        }
      }
      a = a / 10;
      s = s / 10;
    }
    while (s > 0) {
      ans = to_string(s % 10) + ans;
      s = s / 10;
    }
    string fa = "";
    int tt = 0;
    for (auto k : ans) {
      if (k == '0' && tt == 0)
        continue;
      else {
        tt = 1;
        fa += k;
      }
    }
    if (fa == "") fa = "0";
    if (f == 1)
      cout << -1 << endl;
    else
      cout << fa << endl;
  }
  return 0;
}
