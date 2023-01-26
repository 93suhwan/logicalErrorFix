#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long fpow(long long x, long long y) {
  if (x == 0) return 0;
  if (y == 0) return 1;
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = res * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return res;
}
long long fac[300005];
long long C(long long x, long long y) {
  return fac[y] * fpow(fac[y - x], mod - 2) % mod * fpow(fac[x], mod - 2) % mod;
}
void solve() {
  long long n;
  cin >> n;
  if (n == 1)
    puts("a");
  else if (n % 2 == 0) {
    for (long long i = 1; i <= n / 2; i++) cout << "a";
    cout << "b";
    for (long long i = 1; i <= n / 2 - 1; i++) cout << "a";
    puts("");
  } else {
    for (long long i = 1; i <= n / 2; i++) cout << "a";
    cout << "bc";
    for (long long i = 1; i <= n / 2 - 1; i++) cout << "a";
    puts("");
  }
}
signed main() {
  long long _ = 1;
  cin >> _;
  while (_--) solve();
  return 0;
}
