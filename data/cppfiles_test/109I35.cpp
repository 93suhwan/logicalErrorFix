#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
long long inv(long long x, long long m) { return binpow(x, m - 2, m); }
long long fac[200000 + 20];
unsigned long long nCrModPFermat(unsigned long long n, long long r,
                                 long long p) {
  if (n < r) return 0;
  if (r == 0) return 1;
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
  return (fac[n] * inv(fac[r], p) % p * inv(fac[n - r], p) % p) % p;
}
long long f(long long n, long long m, long long r) {
  return nCrModPFermat(n + m, m - r, 998244353ll);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  fac[0] = 1;
  for (long long i = 1; i <= 200000 + 19; i++)
    fac[i] = fac[i - 1] * i % 998244353ll;
  long long n;
  cin >> n;
  long long del = 0, w = 0, b = 0, s = 0, one = false, wb = 0, bw = 0;
  for (long long i = 1; i <= n; i++) {
    string str;
    cin >> str;
    if (str == "??")
      s++, bw++, wb++;
    else if (str == "WW")
      del++, one = true, w += 2;
    else if (str == "BB")
      del--, one = true, b += 2;
    else if (str == "?W")
      w++, bw++;
    else if (str == "W?")
      w++, wb++;
    else if (str == "B?")
      b++, bw++;
    else if (str == "?B")
      b++, wb++;
  }
  long long ans = nCrModPFermat(2 * n - w - b, n - w, 998244353ll);
  if (!one) {
    ans -= binpow(2, s, 998244353ll);
    if (wb == n) ans++;
    if (bw == n) ans++;
  }
  ans += 998244353ll;
  ans %= 998244353ll;
  cout << ans;
  return 0;
}
