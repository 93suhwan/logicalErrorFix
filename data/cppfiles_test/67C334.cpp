#include <bits/stdc++.h>
using namespace std;
const long long MX = 1e5 + 5;
void io_file() {}
void solve() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long diff = abs(a - b);
  long long cric = 2 * diff;
  bool flag = 1;
  long long ans = 0;
  if (max(a, b) <= cric) {
    if (c <= cric) {
      if (c + diff <= cric) {
        ans = c + diff;
      } else if ((c - diff) > 0) {
        ans = c - diff;
      } else {
        flag = 0;
      }
    } else {
      flag = 0;
    }
  } else {
    flag = 0;
  }
  if (!flag) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  io_file();
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
