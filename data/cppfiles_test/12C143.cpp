#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long inf = 2e18;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int domino = (n * m) / 2;
    int extra_hori = 0, extra_ver = 0;
    if (n % 2 == 1) {
      extra_hori = m / 2;
    }
    if (m % 2 == 1) {
      extra_ver = n / 2;
    }
    if (extra_hori > k) {
      cout << "NO" << endl;
      continue;
    }
    int remain = domino - extra_hori - extra_ver;
    k -= extra_hori;
    bool f = false;
    if (k % 2 == 0 and (k <= remain)) {
      f = true;
    }
    cout << (f ? "YES" : "NO") << endl;
    ;
  }
}
