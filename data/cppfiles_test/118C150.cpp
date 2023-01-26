#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const double pi = acos(-1);
long long qpow(long long a, long long b, long long mod) {
  long long res = 1;
  for (; b; b >>= 1, a = a * a % mod) {
    if (b & 1) res = res * a % mod;
  }
  return res;
}
long long N;
void bit_reverse(long long n, long long* r) {
  for (long long i = 0, j = 0; i < n; i++) {
    if (i > j) swap(r[i], r[j]);
    for (long long l = n >> 1; (j ^= l) < l; l >>= 1)
      ;
  }
}
long long inv3;
long long pow3[(1 << 21) + 5], powinv3[(1 << 21) + 5];
void pre(long long n) {
  inv3 = qpow(3, mod - 2, mod);
  for (long long i = 1; i <= n; i <<= 1) pow3[i] = qpow(3, (mod - 1) / i, mod);
  for (long long i = 1; i <= n; i <<= 1)
    powinv3[i] = qpow(inv3, (mod - 1) / i, mod);
}
void NTT(long long n, long long* r, long long f) {
  bit_reverse(n, r);
  for (long long i = 2; i <= n; i <<= 1) {
    long long m = i >> 1;
    for (long long j = 0; j < n; j += i) {
      long long w = 1, wn = pow3[i];
      if (f == -1) wn = powinv3[i];
      for (long long k = 0; k < m; k++) {
        long long z = r[j + m + k] * w % mod;
        r[j + m + k] = (r[j + k] - z + mod) % mod;
        r[j + k] = (r[j + k] + z) % mod;
        w = w * wn % mod;
      }
    }
  }
  if (f == -1) {
    long long inv = qpow(n, mod - 2, mod);
    for (long long i = 0; i < n; i++) r[i] = r[i] * inv % mod;
  }
}
long long ta[(1 << 18) + 5], tb[(1 << 19) + 5];
long long n;
vector<long long> v[250005];
long long cnt[250005], len;
void dfs(long long x, long long y) {
  long long sum = 0;
  for (auto u : v[x])
    if (u != y) {
      sum++;
      dfs(u, x);
    }
  if (sum) cnt[++len] = sum;
}
vector<long long> get(long long l, long long r) {
  if (l == r) {
    vector<long long> p(2, 0);
    p[0] = 1;
    p[1] = cnt[l];
    return p;
  }
  long long mid = (l + r) >> 1;
  vector<long long> tl = get(l, mid), tr = get(mid + 1, r);
  long long siz = tl.size() + tr.size() - 1;
  vector<long long> p(siz, 0);
  N = 1;
  while (N < siz) N *= 2;
  for (long long i = 0; i < tl.size(); i++) ta[i] = tl[i];
  for (long long i = tl.size(); i < N; i++) ta[i] = 0;
  for (long long i = 0; i < tr.size(); i++) tb[i] = tr[i];
  for (long long i = tr.size(); i < N; i++) tb[i] = 0;
  NTT(N, ta, 1);
  NTT(N, tb, 1);
  for (long long i = 0; i < N; i++) ta[i] = ta[i] * tb[i] % mod;
  NTT(N, ta, -1);
  for (long long i = 0; i < siz; i++) p[i] = ta[i];
  return p;
}
long long f[250005];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  pre(1 << 19);
  for (long long i = 2; i <= n; i++) {
    long long x, y;
    cin >> x >> y;
    v[x].emplace_back(y);
    v[y].emplace_back(x);
  }
  dfs(1, -1);
  f[0] = 1;
  for (long long i = 1; i <= n; i++) f[i] = f[i - 1] * i % mod;
  vector<long long> tv = get(1, len);
  long long ans = 0;
  for (long long i = 0; i < tv.size(); i++) {
    if (i & 1) {
      ans = (ans - f[n - i] * tv[i] % mod + mod) % mod;
    } else
      ans = (ans + f[n - i] * tv[i]) % mod;
  }
  cout << ans;
  return 0;
}
