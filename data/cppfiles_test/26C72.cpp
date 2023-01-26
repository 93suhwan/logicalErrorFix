#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(0)->sync_with_stdio(false);
  cout << setprecision(10) << fixed;
  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    int n = (int)str.size();
    int c1 = 0, c2 = 0, ans = n;
    for (int i = 1; i <= n; ++i) {
      if (i & 1) {
        c1 += (str[i - 1] == '0' ? 0 : 1);
      } else
        c2 += (str[i - 1] == '1' ? 1 : 0);
      int left = n - i;
      int oleft = left + (left & 1);
      if (c1 > c2 + (oleft / 2)) ans = min(ans, i);
    }
    c1 = 0, c2 = 0;
    for (int i = 1; i <= n; ++i) {
      if (i & 1) {
        c1 += (str[i - 1] == '1' ? 1 : 0);
      } else
        c2 += (str[i - 1] == '0' ? 0 : 1);
      int left = n - i;
      if (c2 > c1 + (left / 2)) ans = min(ans, i);
    }
    cout << ans << '\n';
  }
  return 0;
}
