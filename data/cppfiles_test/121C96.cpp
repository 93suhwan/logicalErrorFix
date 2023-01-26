#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int z = 1; z <= t; z++) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int d1 = 0, d0 = 0;
    int e1 = 0, e0 = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == '1') {
        if (a[i] != b[i])
          d1++;
        else
          e1++;
      } else {
        if (a[i] != b[i])
          d0++;
        else
          e0++;
      }
    }
    int res = 1e9;
    if (0 <= d1 - d0 && d1 - d0 <= 1 && (d1 + d0) % 2 == 0) {
      res = min(res, d1 + d0);
    }
    if (0 <= e1 - e0 && e1 - e0 <= 1 && (e1 + e0) % 2 == 1) {
      res = min(res, e1 + e0);
    }
    if (res == 1e9)
      cout << -1 << "\n";
    else
      cout << res << "\n";
  }
  return 0;
}
