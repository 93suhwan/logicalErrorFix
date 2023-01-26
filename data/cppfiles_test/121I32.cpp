#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  int64_t q;
  cin >> q;
  while (q--) {
    int64_t n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int64_t cnt = 0;
    bool ok = 0;
    for (int64_t i = 0; i < n; ++i) {
      if (a[i] != '0') {
        ok = 1;
      }
      cnt += (a[i] != b[i]);
    }
    if (!ok) {
      cout << -1 << endl;
    } else {
      cout << min(cnt, n - cnt) << endl;
    }
  }
}
