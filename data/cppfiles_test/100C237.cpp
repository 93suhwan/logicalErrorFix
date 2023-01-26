#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
long long mod = 998244353;
long long a[maxn];
long long fac[maxn];
map<long long, long long> mp;
long long qpow(long long a, long long n) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans = ans * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return ans;
}
long long c(long long m, long long n) {
  return fac[m] * qpow(fac[n] * fac[m - n] % mod, mod - 2) % mod;
}
int main() {
  int t;
  cin >> t;
  fac[0] = 1;
  for (int i = 1; i < maxn; i++) fac[i] = fac[i - 1] * i % mod;
  while (t--) {
    int n;
    mp.clear();
    cin >> n;
    long long ma = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
      scanf("%lld", &a[i]), mp[a[i]]++, ma = max(ma, a[i]);
    int sum = 0;
    if (mp[ma] >= 2)
      printf("%lld\n", fac[n]);
    else if (mp[ma] == 1) {
      if (mp[ma - 1] == 0) {
        printf("0\n");
      } else {
        long long sum = 0;
        for (int i = mp[ma - 1]; i <= n - 1; i++) {
          sum += fac[i] * fac[n - i - 1] % mod *
                 c(n - mp[ma - 1] - 1, i - mp[ma - 1]) % mod;
          sum %= mod;
        }
        long long ans = (fac[n] - sum) % mod + mod;
        printf("%lld\n", ans % mod);
      }
    }
  }
  return 0;
}
