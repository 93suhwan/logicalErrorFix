#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  int T;
  cin >> T;
  while (T--) {
    int n, m, rb, cb, rd, cd;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    int ans = 0, rc = 1, cc = 1;
    while (rb != rd && cb != cd) {
      if (1 <= rb && n >= rb && 1 <= cb && m >= cb) ans++;
      if (rb + rc > n) rc = -1;
      if (rb + rc < 1) rc = 1;
      if (cb + cc > m) cc = -1;
      if (cb + cc < 1) cc = 1;
      rb += rc;
      cb += cc;
    }
    cout << ans << '\n';
  }
  return 0;
}
