#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
long long n;
long long a[300000];
long long phi[300000], p[300000], pr[300000], cnt;
const long long N = 1e5 + 100;
const long long mod = 1e9 + 7;
long long q[300000], tot = 0, Sqrt = 0;
long long num[100010];
long long c[100010][3], g[1000][1000];
long long val = N;
bool f[100010];
inline long long gcd(const long long x, const long long y) {
  long long ret = 1, v = y, tmp;
  for (long long i = 0; i < 3; i++) {
    if (c[x][i] > val)
      tmp = v % c[x][i] ? 1 : c[x][i];
    else
      tmp = g[c[x][i]][v % c[x][i]];
    v /= tmp, ret *= tmp;
  }
  return ret;
}
inline long long solve() {
  if (tot <= Sqrt) {
    long long res = 0;
    for (long long i = 1; i <= tot; i++) {
      for (long long j = 1; j <= tot; j++) {
        res += gcd(q[i], q[j]);
      }
    }
    return res % mod;
  }
  memset(num, 0, sizeof(num));
  long long lim = 0;
  for (long long i = 1; i <= tot; i++) num[q[i]]++, lim = max(lim, q[i]);
  long long ans = 0;
  for (long long t = 1; t <= lim; t++) {
    long long res = 0;
    for (long long i = t; i <= lim; i += t) {
      res += num[i];
    }
    long long RES = res % mod;
    ans += (RES * RES) % mod * phi[t];
    ans %= mod;
  }
  return ans;
}
signed main() {
  ios::sync_with_stdio(false);
  phi[1] = 1;
  for (long long i = 2; i <= N; i++) {
    if (pr[i] == 0) p[++cnt] = i, phi[i] = i - 1;
    for (long long j = 1; j <= cnt && p[j] * i <= N; j++) {
      pr[i * p[j]] = 1;
      if (i % p[j] == 0) {
        phi[i * p[j]] = phi[i] * p[j];
        break;
      }
      phi[i * p[j]] = phi[i] * phi[p[j]];
    }
  }
  c[1][0] = c[1][1] = c[1][2] = 1;
  long long tmp;
  for (long long i = 2; i <= val; i++) {
    if (!f[i]) p[++cnt] = i, c[i][0] = c[i][1] = 1, c[i][2] = i;
    for (long long j = 1; j <= cnt && i * p[j] <= val; j++) {
      tmp = i * p[j];
      f[tmp] = true;
      c[tmp][0] = c[i][0] * p[j];
      c[tmp][1] = c[i][1];
      c[tmp][2] = c[i][2];
      if (c[tmp][0] > c[tmp][1])
        c[tmp][0] ^= c[tmp][1] ^= c[tmp][0] ^= c[tmp][1];
      if (c[tmp][1] > c[tmp][2])
        c[tmp][1] ^= c[tmp][2] ^= c[tmp][1] ^= c[tmp][2];
      if (!(i % p[j])) break;
    }
  }
  val = (long long)ceill(sqrtl((long double)val));
  for (long long i = 1; i <= val; i++) g[i][0] = g[0][i] = i;
  for (long long i = 1; i <= val; i++)
    for (long long j = 1; j <= i; j++)
      g[i][j] = g[j][i] = (i >= j << 1) ? g[i - j][j] : g[j][i - j];
  cin >> n;
  Sqrt = ceil(sqrt(n));
  for (long long i = 1; i <= n; i++) cin >> a[i];
  long long ans = 0;
  for (long long t = 1; t <= n; t++) {
    tot = 0;
    for (long long i = t; i <= n; i += t) {
      q[++tot] = a[i];
    }
    ans += solve() % mod * phi[t] % mod;
  }
  cout << ans % mod << endl;
}
