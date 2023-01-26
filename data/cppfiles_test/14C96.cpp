#include <bits/stdc++.h>
using namespace std;
const int mxn = 2e3 + 5;
const long long MOD = 1e9 + 7;
const int BASE = 100000000;
const int INF = 1e9 + 8;
int f[mxn], a[mxn], g[mxn], n, k;
signed main() {
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> k;
    for (int i = (1); i <= (n); ++i) {
      cin >> a[i];
      a[i] = i - a[i];
    }
    for (int i = (1); i <= (n); ++i) f[i] = 0;
    int res = 0;
    for (int i = (1); i <= (n); ++i) {
      if (a[i] < 0) continue;
      f[i] = 1;
      for (int j = (1); j < (i); ++j)
        if (a[i] >= a[j] && (i - j - 1 >= a[i] - a[j]))
          f[i] = max(f[i], f[j] + 1);
      res = max(res, f[i]);
    }
    if (res < k) {
      cout << "-1\n";
      continue;
    }
    res = INF;
    for (int i = (1); i <= (n); ++i) {
      if (f[i] >= k) res = min(res, a[i]);
    }
    cout << res << endl;
  }
}
