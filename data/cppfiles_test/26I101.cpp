#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;
    int g1 = 0, g2 = 0;
    int ans = 0;
    for (int i = 0; i <= 9; i++) {
      ans++;
      if (s[i] == '1') {
        if (i % 2 == 0)
          g1++;
        else
          g2++;
      } else if (s[i] == '?') {
        if (i % 2 == 0 && g1 >= g2)
          g1++;
        else if (i % 2 != 0 && g2 >= g1)
          g2++;
      }
      if (i % 2 == 0) {
        if (g1 > g2 + (10 - i) / 2 || g2 > g1 + (10 - i - 1) / 2) break;
      } else {
        if (g2 > g1 + (10 - i) / 2 || g1 > g2 + (10 - i - 1) / 2) break;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
