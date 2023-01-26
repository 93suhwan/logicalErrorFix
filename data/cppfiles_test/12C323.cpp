#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
const int M = 2e5 + 7;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int maxn = 1e6 + 7;
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  int t;
  cin >> t;
  ;
  while (t--) {
    int m, n, k;
    cin >> n >> m >> k;
    if (n % 2 == 0) {
      if (k % 2 == 0 && (m % 2 == 0 || 2 * k <= n * (m - 1))) {
        cout << "YES" << '\n';
      } else {
        cout << "NO" << '\n';
      }
    } else {
      if (k >= m / 2 && (k - (m / 2)) % 2 == 0) {
        cout << "YES" << '\n';
      } else {
        cout << "NO" << '\n';
      }
    }
  }
  return 0;
}
