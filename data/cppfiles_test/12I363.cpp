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
    cin >> m >> n >> k;
    if (m % 2 && n % 2) {
      cout << "NO" << '\n';
      continue;
    }
    if (n % 2) {
      if (k % 2)
        cout << "NO" << '\n';
      else
        cout << "YES" << '\n';
      continue;
    }
    if (m % 2) {
      if (k < n / 2)
        cout << "NO" << '\n';
      else {
        k -= n / 2;
        if (k % 2)
          cout << "NO" << '\n';
        else
          cout << "YES" << '\n';
      }
      continue;
    }
    if (k % 2)
      cout << "NO" << '\n';
    else
      cout << "YES" << '\n';
  }
  return 0;
}
