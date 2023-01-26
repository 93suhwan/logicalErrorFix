#include <bits/stdc++.h>
using namespace std;
vector<long long> a[300010];
long long pre[300010], nxt[300010];
bool vis[300010];
vector<long long> pack;
const long long mod = 998244353;
inline long long fastpow(long long a, long long n) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans = ans * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return ans;
}
inline long long inv(long long x) { return fastpow(x, mod - 2); }
const long long g = 3, ig = inv(g);
long long r[2000000];
inline void getr(long long lim, long long n) {
  for (long long i = 0; i < lim; i++)
    r[i] = (r[i >> 1] >> 1) | ((i & 1) << (n - 1));
}
inline void NTT(long long *a, long long n, long long op) {
  for (long long i = 0; i < n; i++)
    if (i < r[i]) swap(a[i], a[r[i]]);
  for (long long i = 1; i < n; i <<= 1) {
    long long wn = fastpow(op == 1 ? g : ig, (mod - 1) / (i << 1));
    for (long long j = 0; j < n; j += (i << 1)) {
      long long w = 1;
      for (long long k = 0; k < i; k++, w = w * wn % mod) {
        long long x = a[j + k], y = w * a[j + k + i] % mod;
        a[j + k] = (x + y) % mod;
        a[j + k + i] = (x - y + mod) % mod;
      }
    }
  }
  if (op == -1) {
    long long il = inv(n);
    for (long long i = 0; i < n; i++) a[i] = a[i] * il % mod;
  }
}
long long A[2000000], B[2000000];
void work(long long *a, long long *b, long long n, long long cnt) {
  static long long tmp[2000000];
  if (n == 1) {
    b[0] = inv(a[0]);
    return;
  }
  work(a, b, n >> 1, cnt - 1);
  long long lim = n << 1;
  for (long long i = 0; i < n; i++) tmp[i] = a[i];
  for (long long i = n; i < lim; i++) tmp[i] = 0;
  getr(lim, cnt + 1);
  NTT(tmp, lim, 1);
  NTT(b, lim, 1);
  for (long long i = 0; i < lim; i++)
    b[i] = b[i] * (2 - tmp[i] * b[i] % mod + mod) % mod;
  NTT(b, lim, -1);
  for (long long i = n; i < lim; i++) b[i] = 0;
}
signed main() {
  long long n, m, k;
  scanf("%lld %lld %lld", &n, &m, &k);
  for (long long i = 1; i <= n; i++) {
    long long t;
    scanf("%lld", &t);
    while (t--) {
      long long x;
      scanf("%lld", &x);
      a[i].push_back(x);
    }
  }
  for (long long i = 1; i <= n; i++) {
    long long len = a[i].size();
    for (long long j = 0; j < len; j++) {
      if (j != 0) {
        if (pre[a[i][j]] != 0 && pre[a[i][j]] != a[i][j - 1])
          pre[a[i][j]] = -1;
        else
          pre[a[i][j]] = a[i][j - 1];
      }
      if (j != len - 1) {
        if (nxt[a[i][j]] != 0 && nxt[a[i][j]] != a[i][j + 1])
          nxt[a[i][j]] = -1;
        else
          nxt[a[i][j]] = a[i][j + 1];
      }
    }
  }
  for (long long i = 1; i <= k; i++)
    if (!pre[i] && !vis[i]) {
      long long tot = 0, u = i;
      bool flag = true;
      while (u) {
        tot++;
        if (vis[u] || pre[u] == -1 || nxt[u] == -1) {
          flag = false;
          break;
        }
        vis[u] = true;
        u = nxt[u];
      }
      if (flag) pack.push_back(tot);
    }
  A[0] = mod - 1;
  for (auto x : pack) A[x]++;
  long long lim = 1, cnt = 0;
  while (lim <= max(k, m)) lim <<= 1, cnt++;
  work(A, B, lim, cnt);
  printf("%lld\n", (mod - B[m]) % mod);
  return 0;
}
