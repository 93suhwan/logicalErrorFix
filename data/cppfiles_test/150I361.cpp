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
  long long n, ans = 1e9, mx = 0;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  long long x = mx / 3;
  x -= 5;
  if (x < 1) x = 1;
  for (long long i = -1; i <= 10; ++i) {
    long long X = x + i;
    if (i == -1) X = 0;
    for (long long j = 0; j < 10; ++j) {
      for (long long k = 0; k < 10; ++k) {
        bool ok = true;
        for (long long c = 0; c < n; ++c) {
          long long x = a[c];
          fun(x, X, 3);
          if ((X > 0) && (x & 1)) {
            if (j * 2 >= x + 3) {
              x = 0;
              continue;
            }
          }
          fun(x, j, 2);
          fun(x, k, 1);
          if (x) {
            ok = false;
            break;
          }
        }
        long long tot = X + j + k;
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
