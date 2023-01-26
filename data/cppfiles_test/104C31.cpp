#include <bits/stdc++.h>
using namespace std;
bool debug_cerr = false;
vector<long long> mf, mi;
long long POW(long long x, long long y);
long long MI(long long x, long long mod);
void facts(long long x, long long mod);
long long C(long long x, long long y, long long mod);
long long bpow(long long x, long long y, long long mod);
long long POW(long long x, long long y) { return bpow(x, y, (long long)1e18); }
long long MI(long long x, long long mod = 1000000007) {
  return bpow(x, mod - 2, mod);
}
void facts(long long x, long long mod = 1000000007) {
  mf = mi = vector<long long>(x + 1);
  mf[0] = 1;
  for (long long i = 1; i <= x; i++) mf[i] = i * mf[i - 1] % mod;
  mi[x] = MI(mf[x], mod);
  for (long long i = x - 1; i >= 0; i--) mi[i] = (i + 1) * mi[i + 1] % mod;
  return;
}
long long C(long long x, long long y, long long mod = 1000000007) {
  if (x < y) return 0;
  long long res = mf[x] * mi[y] % mod;
  res = res * mi[x - y] % mod;
  return res;
}
long long bpow(long long x, long long y, long long mod = 1000000007) {
  x %= mod;
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = res * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return res;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long q;
  cin >> q;
  for (long long _ = 1; _ <= q; _++) {
    long long n, m;
    cin >> n >> m;
    long long a[n], b[n], c[n], oa[n], ob[n];
    long long total = -(n * m);
    long long sa = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
      oa[i] = a[i];
      ob[i] = b[i];
      total += (a[i] + b[i]);
      a[i] -= max(0LL, m - b[i]);
      c[i] = m - max(0LL, m - b[i]);
      sa += a[i];
    }
    total /= 2;
    if (sa > total) {
      for (long long i = 0; i < n; i++) {
        long long d = min(c[i], a[i]);
        if (sa - total >= d) {
          a[i] -= d;
          c[i] -= d;
          b[i] -= c[i];
          sa -= d;
        } else if (sa >= total) {
          long long dif = sa - total;
          a[i] -= dif;
          c[i] -= dif;
          b[i] -= c[i];
          sa -= dif;
        }
      }
    } else {
      for (long long i = 0; i < n; i++) {
        b[i] -= c[i];
      }
    }
    long long A = 0, B = 0;
    for (long long i = 0; i < n; i++) {
      A += a[i];
      B += b[i];
    }
    cout << abs(A - B) << '\n';
    for (long long i = 0; i < n; i++) {
      cout << oa[i] - a[i] << ' ' << ob[i] - b[i] << '\n';
    }
  }
}
