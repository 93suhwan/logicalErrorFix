#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
long long read() {
  long long x;
  scanf("%lld", &x);
  return x;
}
const long long mod = 1000000007;
const long long N = 100010, p = 100000, K = 150;
long long n, a[N], c[N], w[N], mu[N], pr[N], tot, q[N], ans;
bool vis[N];
inline long long gcd(long long x, long long y) {
  return y == 0 ? x : gcd(y, x % y);
}
long long calc() {
  long long ret = 0;
  for (long long i = 1; i <= p; ++i) {
    long long sum = 0;
    for (long long j = i; j <= p; j += i) sum += c[j];
    sum *= sum;
    ret += sum % mod * w[i] % mod;
  }
  return ret % mod;
}
int main() {
  n = read();
  for (long long i = (long long)(1); i <= (long long)(n); ++i) a[i] = read();
  mu[1] = 1;
  for (long long i = 2; i <= p; ++i) {
    if (!vis[i]) {
      pr[++tot] = i;
      mu[i] = -1;
    }
    for (long long j = 1; j <= tot; ++j) {
      if (i * pr[j] > p) break;
      vis[i * pr[j]] = 1;
      if (i % pr[j] == 0)
        mu[i * pr[j]] = 0;
      else
        mu[i * pr[j]] = -mu[i];
      if (i % pr[j] == 0) break;
    }
  }
  for (long long i = 1; i <= p; ++i) {
    for (long long j = 1; i * j <= p; ++j) {
      w[i * j] += mu[i] * j;
    }
  }
  for (long long i = (long long)(1); i <= (long long)(n); ++i) {
    long long m = 0;
    for (long long j = i; j <= n; j += i) {
      q[++m] = a[j];
    }
    if (m <= K) {
      long long sum = 0;
      for (long long x = 1; x <= m; ++x)
        for (long long y = 1; y <= m; ++y) sum += gcd(q[x], q[y]);
      ans += sum % mod * w[i] % mod;
    } else {
      memset(c, 0, sizeof c);
      for (long long x = 1; x <= m; ++x) ++c[q[x]];
      ans += calc() * w[i] % mod;
    }
  }
  printf("%lld\n", (ans % mod + mod) % mod);
  return 0;
}
