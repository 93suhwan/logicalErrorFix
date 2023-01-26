#include <bits/stdc++.h>
using namespace std;
const long long P = 1000000007;
long long MOD(long long x) { return (x % P + P) % P; }
long long Time(long long x, long long y) {
  if (x < 0) {
    x = MOD(x);
  }
  long long ans = 1;
  while (y) {
    if (y & 1) {
      ans = ans * x % P;
    }
    x = x * x % P;
    y >>= 1;
  }
  return ans;
}
int main() {
  long long T;
  scanf("%lld", &T);
  while (T--) {
    long long n, m, xa, ya, xb, yb, pro;
    scanf("%lld%lld%lld%lld%lld%lld%lld", &n, &m, &xa, &ya, &xb, &yb, &pro);
    pro = pro * Time(100, P - 2) % P;
    long long sum = 0, cnt = 0;
    long long dx = 1, dy = 1;
    long long x = xa, y = ya;
    bool z = 0;
    while (!z || x != xa || y != ya) {
      if (x == xb || y == yb) {
        cnt++;
      }
      z = 1;
      long long tx = x + dx, ty = y + dy;
      if (tx > n || tx <= 0) {
        dx *= -1;
      }
      if (ty > m || ty <= 0) {
        dy *= -1;
      }
      tx = x + dx;
      ty = y + dy;
      x = tx;
      y = ty;
      sum++;
    }
    long long ans = 0;
    dx = 1;
    dy = 1;
    x = xa;
    y = ya;
    z = 0;
    long long t = 0;
    long long cnt2 = 0;
    while (!z || x != xa || y != ya) {
      if (x == xb || y == yb) {
        long long a = t * Time(1 - pro, cnt2) % P * pro % P;
        long long b = sum * Time(1 - pro, cnt2 + cnt) % P * pro % P;
        long long c = MOD(1 - Time(1 - pro, cnt));
        ans = MOD(ans + (a + b * Time(c, P - 2)) % P * Time(c, P - 2) % P);
        cnt2++;
      }
      z = 1;
      long long tx = x + dx, ty = y + dy;
      if (tx > n || tx <= 0) {
        dx *= -1;
      }
      if (ty > m || ty <= 0) {
        dy *= -1;
      }
      tx = x + dx;
      ty = y + dy;
      x = tx;
      y = ty;
      t++;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
