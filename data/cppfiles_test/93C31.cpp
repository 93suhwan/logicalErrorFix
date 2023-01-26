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
  for (long long i = 1; i <= x; i++) {
    mf[i] = (i * mf[i - 1]) % mod;
  }
  mi[x] = MI(mf[x], mod);
  for (long long i = x - 1; i >= 0; i--) {
    mi[i] = ((i + 1) * mi[i + 1]) % mod;
  }
  return;
}
long long C(long long x, long long y, long long mod = 1000000007) {
  if (x < y) return 0;
  long long n1 = mf[x];
  long long n2 = mi[y];
  long long n3 = mi[x - y];
  long long res = (n1 * n2) % mod;
  res = (res * n3) % mod;
  return res;
}
long long bpow(long long x, long long y, long long mod = 1000000007) {
  x %= mod;
  long long res = 1;
  while (y > 0) {
    if (y & 1) {
      res = res * x % mod;
    }
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
    long long a, b;
    cin >> a >> b;
    long long ans = a;
    long long d = a % 4;
    long long x = 0;
    a--;
    while (d--) {
      x = (x ^ (a));
      a--;
    }
    if (x == b) {
      cout << ans << '\n';
    } else {
      if ((x ^ b) == ans) {
        cout << ans + 2 << '\n';
      } else {
        cout << ans + 1 << '\n';
      }
    }
  }
}
