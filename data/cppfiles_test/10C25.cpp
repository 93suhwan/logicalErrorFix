#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long maxN = 300005;
const long long oo = 1e18 + 7;
long long n, a[maxN];
long long x2, y2, x3, y3, z, k;
long long m;
long long r, c;
long long pw(long long num, long long coef) {
  long long res = 1;
  while (coef) {
    if (coef & 1) res = (res * num) % mod;
    num = (num * num) % mod;
    coef >>= 1;
  }
  return res;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> k >> r >> c;
  long long bigg = n * m;
  long long midd = r * c;
  long long smol;
  cin >> x2 >> y2 >> x3 >> y3;
  long long val1 = min(x2 + r, x3 + r) - max(x2, x3);
  long long val2 = min(y2 + c, y3 + c) - max(y2, y3);
  if (val1 < 0 || val2 < 0)
    smol = 0;
  else
    smol = val1 * val2;
  if (x2 == x3 && y2 == y3)
    cout << pw(k, bigg) << "\n";
  else
    cout << pw(k, bigg - midd) << "\n";
}
