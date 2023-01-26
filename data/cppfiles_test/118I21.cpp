#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
const long long mod = 998244353;
const long long linf = 1e18;
const double EPS = 1e-10;
const double pi = acos(-1);
template <class T>
void chmin(T& x, T y) {
  if (x > y) x = y;
}
template <class T>
void chmax(T& x, T y) {
  if (x < y) x = y;
}
template <long long mod, long long pri>
struct NTT {
  long long t = 0;
  vector<long long> mp, mpi;
  long long modpow(long long x, long long y) {
    if (y == 0) return 1;
    long long res = modpow(x, y / 2);
    return res * res % mod * (y & 1 ? x : 1) % mod;
  }
  NTT() {
    while ((mod - 1) % (1 << t) == 0) {
      mp.push_back(modpow(pri, (mod - 1) / (1 << t)));
      mpi.push_back(modpow(mp[t], mod - 2));
      t++;
    }
  }
  vector<long long> ntt(vector<long long> f, bool inv = false) {
    int n = f.size();
    int d = 0;
    while ((1 << d) < n) d++;
    for (int i = 0; i < n; i++) {
      int to = 0;
      for (int j = 0; j < d; j++) to |= ((i >> j) & 1) << (d - j - 1);
      if (i < to) swap(f[i], f[to]);
    }
    int idx = 1;
    for (int b = 1; b < n; b *= 2) {
      long long w = 1;
      for (int j = 0; j < b; j++) {
        for (int k = 0; k < n; k += b * 2) {
          long long s = f[j + k];
          long long t = f[j + k + b] * w % mod;
          f[j + k] = (s + t) % mod;
          f[j + k + b] = (s - t + mod) % mod;
        }
        w = w * (inv ? mp[idx] : mpi[idx]) % mod;
      }
      idx++;
    }
    if (inv) {
      long long n_inv = modpow(n, mod - 2);
      for (int i = 0; i < n; i++) f[i] = (f[i] * n_inv) % mod;
    }
    return f;
  }
  vector<long long> convolve(vector<long long> g, vector<long long> h) {
    int sz = g.size() + h.size() - 1;
    int n = 1;
    while (n < sz) n *= 2;
    g.resize(n);
    h.resize(n);
    g = ntt(g);
    h = ntt(h);
    vector<long long> f(n);
    for (int i = 0; i < n; i++) f[i] = g[i] * h[i] % mod;
    return f;
  }
};
NTT<998244353, 3> ntt1;
int n;
vector<vector<long long>> p;
vector<long long> fac, cnt;
void marge_vec(int l, int r) {
  if (r - l == 1) return;
  int mid = (r + l) / 2;
  marge_vec(l, mid);
  marge_vec(mid, r);
  p[l] = ntt1.convolve(p[l], p[mid]);
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  cin >> n;
  p.resize(n), fac.resize(n + 1, 1), cnt.resize(n, -1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    cnt[u]++, cnt[v]++;
  }
  cnt[0]++;
  for (int i = 0; i < n; i++) {
    fac[i + 1] = fac[i] * (i + 1) % mod;
    p[i].push_back(1);
    p[i].push_back(mod - cnt[i]);
  }
  long long ans = 0;
  marge_vec(0, n);
  for (int i = 0; i < min((int)p[0].size(), n); i++) {
    long long val = p[0][i] * fac[n - i] % mod;
    ans += val;
    ans %= mod;
  }
  cout << ans << '\n';
}
