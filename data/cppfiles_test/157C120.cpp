#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long n, k;
long long fac[5010] = {1, 1};
long long inv[5010] = {1, 1};
char s[5010];
vector<long long> v;
long long qpow(long long a, long long b, long long res = 1) {
  for (; b; b >>= 1, (a *= a) %= mod)
    if (b & 1) (res *= a) %= mod;
  return res;
}
void init(void) {
  for (long long i = 2; i <= 5000; i++) fac[i] = fac[i - 1] * i % mod;
  for (long long i = 2; i <= 5000; i++) inv[i] = qpow(fac[i], mod - 2);
  return;
}
long long C(long long a, long long b) {
  return fac[a] * inv[b] % mod * inv[a - b] % mod;
}
void solve(long long res = 0) {
  scanf("%lld %lld %s", &n, &k, s + 1);
  if (!k) {
    puts("1");
    return;
  }
  s[0] = s[n + 1] = '1';
  v.clear();
  for (long long i = 0; i <= n + 1; i++)
    if (s[i] == '1') v.push_back(i);
  if (v.size() - 2 < k) {
    puts("1");
    return;
  }
  res = C(v[k + 1] - 1, k);
  for (long long i = k + 1; i < (long long)v.size() - 1; i++) {
    long long len = v[i + 1] - v[i - k] - 1;
    long long cov = v[i] - v[i - k] - 1;
    (res += C(len, k)) %= mod;
    (res -= C(cov, k - 1)) %= mod;
    (res += mod) %= mod;
  }
  printf("%lld\n", res);
  return;
}
signed main() {
  init();
  solve();
  return 0;
}
