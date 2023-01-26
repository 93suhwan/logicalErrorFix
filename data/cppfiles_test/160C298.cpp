#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, r1, c1, r2, c2;
    cin >> n >> m >> r1 >> c1 >> r2 >> c2;
    int ans = 0;
    int dr = 1, dc = 1;
    while (1) {
      if (r1 == r2 || c1 == c2) break;
      if (dr == 1 && r1 == n)
        dr = -1;
      else if (dr == -1 && r1 == 1)
        dr = 1;
      if (dc == 1 && c1 == m)
        dc = -1;
      else if (dc == -1 && c1 == 1)
        dc = 1;
      r1 += dr;
      c1 += dc;
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
