#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
long long powik(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b % 2) res = res * a % mod;
    b /= 2;
    a = a * a % mod;
  }
  return res;
}
long long inv(long long a) { return powik(a, mod - 2); }
vector<long long> fac;
long long cnk(long long n, long long k) {
  return fac[n] * inv(fac[k]) % mod * inv(fac[n - k]) % mod;
}
signed main() {
  fac.assign(3e5 + 5, 1);
  for (long long i = 1; i < fac.size(); ++i) {
    fac[i] = i * fac[i - 1];
    fac[i] %= mod;
  }
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  long long bl = 0, wh = 0, fwp = 0, swp = 0;
  cin >> n;
  long long mayb = 1;
  long long bw = 0, wb = 0, wpwp = 0;
  for (long long i = 0; i < n; ++i) {
    string st;
    cin >> st;
    if (st[0] == st[1] and st[0] != '?') mayb = 0;
    if (st[0] == 'B' or st[1] == 'W')
      bw++;
    else if (st[0] == 'W' or st[1] == 'B')
      wb++;
    else
      wpwp++;
    if (st[0] == 'B')
      bl++;
    else if (st[0] == 'W')
      wh++;
    else
      fwp++;
    if (st[1] == 'B')
      wh--;
    else if (st[1] == 'W')
      bl--;
    else
      swp++;
  }
  long long res = 0;
  for (long long fbl = 0; fbl <= fwp; ++fbl) {
    long long bl2 = bl + fbl, wh2 = wh + (fwp - fbl);
    if (bl2 + wh2 != swp) exit(1);
    if (bl2 >= 0 and wh2 >= 0) {
      res += cnk(fwp, fbl) * cnk(swp, bl2);
      res %= mod;
    }
  }
  if (mayb) {
    for (long long i = 0; i <= wpwp; ++i) {
      if (i + bw != 0 and wpwp - i + wb != 0) res -= cnk(wpwp, i);
    }
    res %= mod;
    res += mod;
    res %= mod;
  }
  cout << res;
}
