#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long m = 1;
    int ans = INT_MAX, flag = 1;
    string s, p;
    cin >> s;
    if (s.empty()) {
      cout << 1 << endl;
      continue;
    }
    for (long long x = 1; x <= 1e12; x += x) {
      p = to_string(x);
      if (s == p) {
        ans = 0, flag = 0;
      } else {
        int i, j;
        for (i = 0, j = 0; i < max(p.size(), s.size()); i++) {
          if (s[i] == p[j]) j++;
        }
        ans = min(ans, (int)(s.size() + p.size() - 2 * j));
      }
    }
    if (flag && !ans) ans++;
    cout << ans << endl;
  }
  return 0;
}
