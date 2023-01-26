#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long s = 0, w = 1, ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    s = (s << 3) + (s << 1) + ch - 48;
    ch = getchar();
  }
  return s * w;
}
const long long maxn = 1e5 + 50, maxk = 17, inf = 1e16;
long long n, K, T, f[maxk][maxn];
long long phi[maxn], pri[maxn], tot, notp[maxn], sum[maxn];
void sieve() {
  notp[0] = notp[1] = 1;
  phi[1] = 1;
  for (long long i = 2; i < maxn; i++) {
    if (notp[i] == 0) {
      pri[++tot] = i;
      phi[i] = i - 1;
    }
    for (long long j = 1; pri[j] * i < maxn; j++) {
      notp[i * pri[j]] = 1;
      if (i % pri[j] == 0) {
        phi[i * pri[j]] = phi[i] * pri[j];
        break;
      }
      phi[i * pri[j]] = phi[i] * phi[pri[j]];
    }
  }
  for (long long i = 1; i < maxn; i++) sum[i] = sum[i - 1] + phi[i];
}
long long w(long long i, long long j) {
  long long res = 0;
  for (long long l = i, r = 0; l <= j; l = r + 1) {
    r = j / (j / l);
    r = min(r, j);
    res += (r - l + 1) * sum[j / l];
  }
  return res;
}
void solve(long long k, long long l, long long r, long long x, long long y) {
  if (l > r) return;
  long long mid = (l + r) >> 1, c = w(x + 1, mid), res = inf, pos = 0;
  for (long long i = x; i <= y && i <= mid; i++) {
    if (res > f[k - 1][i] + c) res = f[k - 1][i] + c, pos = i;
    c -= sum[mid / (i + 1)];
  }
  f[k][mid] = res;
  solve(k, l, mid - 1, x, pos);
  solve(k, mid + 1, r, pos, y);
}
signed main() {
  sieve();
  n = 100000;
  K = 16;
  for (long long i = 1; i <= n; i++) f[1][i] = i * (i + 1) / 2;
  for (long long k = 2; k <= K; k++) solve(k, 1, n, 1, n);
  T = read();
  while (T--) {
    n = read();
    K = read();
    if (K >= 17)
      printf("%lld\n", n);
    else
      printf("%lld\n", f[K][n]);
  }
  return 0;
}
