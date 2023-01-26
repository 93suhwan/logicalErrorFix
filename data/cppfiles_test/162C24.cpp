#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
using namespace std;
const long long inf = 1ll << 60;
const long long iinf = 2147483647;
const long long mod = 998244353;
const long long maxn = 505;
const double PI = acos(-1);
long long pw(long long x, long long p, long long m = mod) {
  long long ret = 1;
  while (p > 0) {
    if (p & 1) {
      ret *= x;
      ret %= m;
    }
    x *= x;
    x %= m;
    p >>= 1;
  }
  return ret;
}
long long inv(long long a, long long m = mod) { return pw(a, m - 2, m); }
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> vc(n), add(n);
    for (long long i = (0); i < (n); i++) {
      cin >> vc[i];
    }
    long long l = 1, r = 1e18;
    while (l <= r) {
      if (l == r) {
        cout << l << '\n';
        break;
      }
      long long mid = (l + r + 1) / 2;
      bool gg = false;
      for (long long i = (0); i < (n); i++) add[i] = 0;
      for (long long i = (n)-1; i >= 0; i--) {
        if (i <= 1) {
          if ((add[i] + vc[i]) < mid) {
            gg = 1;
            break;
          }
          continue;
        }
        if (add[i] + vc[i] < mid) {
          gg = 1;
          break;
        }
        long long cn = min(vc[i] / 3, (add[i] + vc[i] - mid) / 3);
        add[i - 2] += cn * 2;
        add[i - 1] += cn;
      }
      if (gg)
        r = mid - 1;
      else
        l = mid;
    }
  }
}
