#include <bits/stdc++.h>
const long long mod = 1000000007;
using namespace std;
bool isprime(long long k) {
  for (long long i = 2; i <= sqrt(k); i++)
    if (k % i == 0) return false;
  return true;
}
long long bm(long long a, long long b, long long mod) {
  if (b == 0) return 1;
  long long t = bm(a, b / 2, mod);
  t = t * t % mod;
  return (b % 2 == 1 ? t * a % mod : t);
}
long long inv(long long a, long long mod) { return bm(a, mod - 2, mod); }
void gay(long long TC) { cout << "Case #" << TC << ": "; }
void solve(long long TC) {
  long long n, m, bx, by, cx, cy, p;
  cin >> n >> m >> bx >> by >> cx >> cy >> p;
  long long cnt = 0;
  long long xx = bx, yy = by;
  long long x = 1, y = 1;
  long long nowp = 1, ans = 0;
  long long pclean = p * inv(100, mod) % mod;
  long long pnotclean = (100 - p) * inv(100, mod) % mod;
  while (cnt == 0 || xx != bx || yy != by) {
    if (bx == cx || by == cy) {
      ans += cnt * nowp % mod * pclean % mod;
      nowp *= pnotclean;
      nowp %= mod;
      ans %= mod;
    }
    cnt++;
    if (bx == 1 && x == -1) x = 1;
    if (bx == n && x == 1) x = -1;
    if (by == 1 && y == -1) y = 1;
    if (by == m && y == 1) y = -1;
    bx += x;
    by += y;
  }
  long long aans =
      (nowp * cnt % mod + ans) % mod * inv((mod + 1 - nowp) % mod, mod) % mod;
  cout << aans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) solve(i);
  return 0;
}
