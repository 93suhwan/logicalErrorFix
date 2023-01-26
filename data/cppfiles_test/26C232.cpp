#include <bits/stdc++.h>
using namespace std;
long long fac[200010];
long long p = 1e9 + 7;
long long po(long long x, long long y) {
  long long b = 1;
  while (y) {
    if (y & 1) b = b * x % p;
    y /= 2;
    x = x * x % p;
  }
  return b;
}
long long k;
void init() {
  long long i;
  fac[0] = 1;
  for (i = 1; i <= 200000; i++) fac[i] = fac[i - 1] * i % p;
  k = po(2, p - 2);
}
void solve() {
  long long n, i, j, x, y, ans = 0, sum;
  cin >> n;
  printf("%lld\n", fac[2 * n] * k % p);
}
int main(void) {
  int T = 1;
  init();
  cin >> T;
  while (T--) {
    solve();
  }
}
