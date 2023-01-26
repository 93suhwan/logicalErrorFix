#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int ans = 9;
    int w0 = 0, w1 = 0;
    for (int i = 0; i < 10; ++i) {
      if (i % 2 == 0) {
        if (s[i] != '0') {
          w0 += 1;
        }
      } else if (s[i] == '1') {
        w1 += 1;
      }
      if (w0 > w1 + (10 - i) / 2) ans = min(ans, i);
      if (w1 > w0 + (9 - i) / 2) ans = min(ans, i);
    }
    w0 = 0;
    w1 = 0;
    for (int i = 0; i < 10; ++i) {
      if (i % 2 == 0)
        w0 += s[i] == '1';
      else
        w1 += s[i] != '0';
      if (w0 > w1 + (10 - i) / 2) ans = min(ans, i);
      if (w1 > w0 + (9 - i) / 2) ans = min(ans, i);
    }
    cout << ans + 1 << '\n';
  }
}
