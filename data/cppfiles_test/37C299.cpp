#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    vector<long long> ok(n, 0);
    for (long long i = 0; i < m; i++) {
      long long a, b, c;
      cin >> a >> b >> c;
      b--;
      ok[b] = 1;
    }
    long long res = 0;
    for (long long i = 1; i <= n; i++) {
      if (!ok[i - 1]) {
        res = i;
      }
    }
    for (long long i = 1; i <= n; i++) {
      if (i != res) {
        cout << res << " " << i << "\n";
      }
    }
  }
  return 0;
}
