#include <bits/stdc++.h>
using namespace std;
const long long SZ = 3e5 + 4;
const long long inf = 2e9;
const long long root = 646;
const long long mod = 998244353;
const long long lg = 20;
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
vector<long long> fft(vector<long long> a, long long k) {
  if (!k) {
    return a;
  }
  long long L = (1 << k);
  vector<long long> a0, a1;
  for (long long i = 0; i < a.size(); ++i) {
    (i & 1 ? a1 : a0).push_back(a[i]);
  }
  a0 = fft(a0, k - 1);
  a1 = fft(a1, k - 1);
  for (long long i = 0; i < L; ++i) {
    long long w = roots[i << (lg - k)];
    a[i] = (a0[i % (L >> 1)] + w * a1[i % (L >> 1)]) % mod;
  }
  return a;
}
vector<long long> invert(vector<long long> a, long long k) {
  a = fft(a, k);
  for (long long& i : a) {
    i *= binpow(1 << k, mod - 2);
    i %= mod;
  }
  reverse(a.begin() + 1, a.end());
  return a;
}
vector<long long> mult(vector<long long> a, vector<long long> b) {
  long long sz1 = (long long)a.size();
  long long sz2 = (long long)b.size();
  long long k = 0;
  while ((1 << k) < sz1 + sz2 - 1) ++k;
  long long L = (1 << k);
  while (a.size() < L) a.push_back(0);
  while (b.size() < L) b.push_back(0);
  a = fft(a, k);
  b = fft(b, k);
  for (long long i = 0; i < L; ++i) {
    a[i] *= b[i];
    a[i] %= mod;
  }
  a = invert(a, k);
  while (a.back() == 0) {
    a.pop_back();
  }
  return a;
}
vector<long long> go(long long l, long long r) {
  if (r == l) return {1, cnt[l]};
  long long m = l + ((r - l) >> 1);
  vector<long long> x = go(l, m);
  vector<long long> y = go(m + 1, r);
  return mult(x, y);
}
long long f[SZ];
void solve() {
  roots.push_back(1);
  for (long long i = 0; i < len; ++i) {
    roots.push_back(roots.back() * root % mod);
  }
  f[0] = 1;
  for (long long i = 1; i <= n; ++i) {
    f[i] = f[i - 1] * i;
    f[i] %= mod;
  }
  long long ans = 0;
  vector<long long> res = go(0, n - 1);
  for (long long i = 0; i < res.size(); ++i) {
    long long tmp = res[i] * f[n - i];
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
