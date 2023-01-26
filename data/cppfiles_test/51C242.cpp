#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;
const long long lnf = 2e18;
const int maxn = 1e6 + 10;
const int maxm = 1e7 + 20;
const int mod = 998244353;
long long qpow(long long a, int n, long long c = 1) {
  for (; n; n >>= 1, a = a * a % mod)
    if (n & 1) c = c * a % mod;
  return c;
}
int T;
long long n, m;
void solve() {
  scanf("%lld", &n);
  if (n > 0) {
    printf("%lld %lld\n", -n + 1, n);
  } else if (n < 0) {
    printf("%lld %lld\n", n, -n - 1);
  } else {
    puts("-1 1");
  }
}
int main() {
  scanf("%d", &T);
  while (T--) {
    solve();
  }
  return 0;
}
