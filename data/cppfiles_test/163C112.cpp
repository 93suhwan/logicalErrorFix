#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long bin_exp(long long a, long long x) {
  long long res = 1;
  while (x > 0) {
    if (x % 2) res = res * a % mod;
    a = a * a % mod;
    x /= 2;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t, i100 = bin_exp(100, mod - 2);
  cin >> t;
  while (t--) {
    long long n, m, rb, cb, rd, cd, x = 0, C = 1, p, sth = 0, dr, dc;
    cin >> n >> m >> rb >> cb >> rd >> cd >> p;
    long long r = rb, c = cb, idr = dr = (r == n ? -1 : 1),
              idc = dc = (c == m ? -1 : 1);
    do {
      if (r == rd || c == cd) {
        sth = (sth + x * p % mod * i100 % mod * C) % mod;
        C = C * (100 - p) % mod * i100 % mod;
      }
      ++x;
      r += dr;
      c += dc;
      if (r == n)
        dr = -1;
      else if (r == 1)
        dr = 1;
      if (c == m)
        dc = -1;
      else if (c == 1)
        dc = 1;
    } while (r != rb || c != cb || dr != idr || dc != idc);
    long long ans = (C * x + sth) % mod * bin_exp(1 - C + mod, mod - 2) % mod;
    cout << ans << "\n";
  }
  return 0;
}
