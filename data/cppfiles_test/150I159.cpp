#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long N = 500003;
vector<long long> prec(N);
struct Bit {
  vector<long long> s;
  long long n;
  Bit(long long n) {
    s.resize(n + 1, 0);
    this->n = n;
  }
  long long query(long long x) {
    long long sum = 0;
    while (x > 0) {
      sum += s[x];
      x -= x & -x;
    }
    return sum;
  }
  void updat(long long x) {
    while (x <= n) {
      s[x]++;
      x += x & -x;
    }
  }
};
void fun(long long &x, long long n, long long d) {
  if (d * n > x) {
    if (x % d == 0)
      x = 0;
    else
      x %= d;
  } else
    x -= n * d;
}
inline void solve() {
  long long n, ans = 1e9;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  long long x = a[n - 1] / 3;
  x -= 3;
  if (x < 1) x = 1;
  long long t[7] = {0, x, x + 1, x + 2, x + 3, x + 4, x + 5};
  long long s[5] = {0, 1, 2, 3, 4};
  long long f[5] = {0, 1, 2, 3, 4};
  for (long long i = 0; i < 7; ++i) {
    for (long long j = 0; j < 5; ++j) {
      for (long long k = 0; k < 5; ++k) {
        bool ok = true;
        for (long long c = 0; c < n; ++c) {
          long long x = a[c];
          fun(x, t[i], 3);
          if (t[i] > 0 && x % 2) {
            if (s[j] * 2 >= x + 3) {
              x = 0;
            }
          }
          fun(x, s[j], 2);
          fun(x, f[k], 1);
          if (x) {
            ok = false;
            break;
          }
        }
        long long tot = t[i] + s[j] + f[k];
        if (ok && tot < ans) {
          ans = tot;
        }
      }
    }
  }
  cout << ans << endl;
}
signed main() {
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
