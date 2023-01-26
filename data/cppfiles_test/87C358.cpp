#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 998244353;
long long t, n, m, k, tmp;
long long a[N];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    long long res = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      res = max(res, a[i] - i);
    }
    cout << res << "\n";
  }
  return 0;
}
