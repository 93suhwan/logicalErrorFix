#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
long long f_pow(long long a, long long b) {
  long long res = 1, temp = a;
  while (b) {
    if (b & 1) res = res * temp % mod;
    temp = temp * temp % mod;
    b >>= 1;
  }
  return res;
}
void solve() {
  long long n, m, k, r, c;
  scanf("%lld %lld %lld %lld %lld", &n, &m, &k, &r, &c);
  long long ax, ay, bx, by;
  scanf("%lld %lld %lld %lld", &ax, &ay, &bx, &by);
  long long x1 = max(ax, bx), x2 = min(ax + r - 1, bx + r - 1);
  long long y1 = max(ay, by), y2 = min(ay + c - 1, by + r - 1);
  printf("%lld\n", f_pow(k, n * m - r * c));
}
int main() {
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
