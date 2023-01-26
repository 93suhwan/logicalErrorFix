#include <bits/stdc++.h>
using namespace std;
long long bpow(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = (ret * a) % 1000000007;
    a = (a * a) % 1000000007;
    b >>= 1;
  }
  return ret;
}
bool inside(long long x, long long y, long long xl, long long xr, long long yl,
            long long yr) {
  return xl <= x && x <= xr && yl <= y && y <= yr;
}
long long k;
long long get(long long n, long long m, long long axl, long long ayl,
              long long bxl, long long byl, long long r, long long c) {
  if (axl == bxl && ayl == byl) {
    return bpow(k, n * m);
  }
  long long axr = axl + r - 1, ayr = ayl + c - 1;
  long long bxr = bxl + r - 1, byr = byl + c - 1;
  long long ans = 1;
  long long free_area = n * m - 2 * r * c;
  long long ixl = max(axl, bxl);
  long long ixr = min(axr, bxr);
  long long iyl = max(ayl, byl);
  long long iyr = min(ayr, byr);
  if (ixl <= ixr && iyl <= iyr) {
    long long ir = ixr - ixl + 1;
    long long ic = iyr - iyl + 1;
    ans *= get(r, c, 1, 1, r - ir + 1, c - ic + 1, ir, ic);
    ans %= 1000000007;
    free_area += ir * ic;
  } else {
    ans *= bpow(k, r * c);
    ans %= 1000000007;
  }
  ans *= bpow(k, free_area);
  ans %= 1000000007;
  return ans;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  srand(chrono::steady_clock::now().time_since_epoch().count());
  cout << fixed << setprecision(15);
  long long n, m, axl, ayl, bxl, byl, r, c;
  cin >> n >> m >> k >> r >> c;
  cin >> axl >> ayl >> bxl >> byl;
  cout << get(n, m, axl, ayl, bxl, byl, r, c);
}
