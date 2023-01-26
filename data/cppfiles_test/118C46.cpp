#include <bits/stdc++.h>
using namespace std;
const long long SZ = 3e5 + 4;
const long long inf = 2e9;
long long root = -1;
const long long mod = 998244353;
const long long lg = 18;
const long long len = (1 << lg);
long long n;
vector<long long> g[SZ];
long long cnt[SZ];
void read() {
  cin >> n;
  for (long long i = 1; i < n; ++i) {
    long long u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  cnt[0] = (long long)g[0].size();
  for (long long i = 1; i < n; ++i) {
    cnt[i] = (long long)g[i].size() - 1;
  }
}
vector<long long> roots;
long long rev[SZ];
long long f[SZ];
void init() {
  rev[0] = 0;
  long long k = 0;
  for (long long mask = 1; mask < len; mask++) {
    if (mask >> (k + 1)) {
      ++k;
    }
    rev[mask] = rev[mask ^ (1 << k)] ^ (1 << (lg - 1 - k));
  }
  for (long long x = 2;; x++) {
    long long y = x;
    for (long long i = 1; i < lg; i++) {
      y = y * y % mod;
    }
    if (y == mod - 1) {
      root = x;
      break;
    }
  }
  roots.push_back(1);
  for (long long i = 0; i < len; ++i) {
    roots.push_back(roots.back() * root % mod);
  }
  f[0] = 1;
  for (long long i = 1; i <= n; ++i) {
    f[i] = f[i - 1] * i;
    f[i] %= mod;
  }
}
long long binpow(long long a, long long b) {
  long long ans = 1;
  long long tmp = a;
  while (b) {
    if (b & 1) {
      ans *= tmp;
      ans %= mod;
    }
    tmp *= tmp;
    tmp %= mod;
    b >>= 1;
  }
  return ans;
}
long long F[2][SZ];
void fft(vector<long long>& a, long long k) {
  long long L = 1 << k;
  for (long long mask = 0; mask < L; mask++) {
    F[0][rev[mask] >> (lg - k)] = a[mask];
  }
  long long t = 0, nt = 1;
  for (long long lvl = 0; lvl < k; lvl++) {
    long long len = 1 << lvl;
    for (long long st = 0; st < L; st += (len << 1)) {
      for (long long i = 0; i < len; i++) {
        long long w = F[t][st + len + i] * roots[i << (lg - 1 - lvl)] % mod;
        F[nt][st + i] = (F[t][st + i] + w) % mod;
        F[nt][st + len + i] = (F[t][st + i] - w + mod) % mod;
      }
    }
    swap(t, nt);
  }
  for (long long i = 0; i < L; i++) {
    a[i] = F[t][i];
  }
}
void invert(vector<long long>& a, long long k) {
  fft(a, k);
  for (long long& i : a) {
    i *= binpow(1 << k, mod - 2);
    i %= mod;
  }
  reverse(a.begin() + 1, a.end());
}
void mult(vector<long long>& a, vector<long long>& b) {
  long long sz1 = (long long)a.size();
  long long sz2 = (long long)b.size();
  long long k = 0;
  while ((1 << k) < sz1 + sz2 - 1) ++k;
  long long L = (1 << k);
  while (a.size() < L) a.push_back(0);
  while (b.size() < L) b.push_back(0);
  fft(a, k);
  fft(b, k);
  for (long long i = 0; i < L; ++i) {
    a[i] *= b[i];
    a[i] %= mod;
  }
  invert(a, k);
  while (a.back() == 0) {
    a.pop_back();
  }
}
vector<long long>* go(long long l, long long r) {
  if (r == l) return new vector<long long>{1, cnt[l]};
  long long m = l + ((r - l) >> 1);
  auto* x = go(l, m);
  auto* y = go(m + 1, r);
  mult(*x, *y);
  return x;
}
void solve() {
  init();
  long long ans = 0;
  vector<long long> res = *go(0, n - 1);
  for (long long i = 0; i < res.size(); ++i) {
    long long tmp = res[i] * f[n - i] % mod;
    if (i & 1) {
      ans -= tmp;
      ans += mod;
      ans %= mod;
    } else {
      ans += tmp;
      ans %= mod;
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  read();
  solve();
  return 0;
}
