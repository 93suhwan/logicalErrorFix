#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353, _G = 3, N = 1 << 20;
inline int qpow(int x, int y = mod - 2) {
  int res = 1;
  for (; y; x = (long long)x * x % mod, y >>= 1)
    if (y & 1) res = (long long)res * x % mod;
  return res;
}
int rt[N], mg[N], Lim;
int fac[N], ifac[N], inv[N];
void init(int x) {
  fac[0] = ifac[0] = inv[1] = 1;
  for (int i = (2); i <= (x); ++i)
    inv[i] = (long long)(mod - mod / i) * inv[mod % i] % mod;
  for (int i = (1); i <= (x); ++i)
    fac[i] = (long long)fac[i - 1] * i % mod,
    ifac[i] = (long long)ifac[i - 1] * inv[i] % mod;
}
int C(int x, int y) {
  return x < y || y < 0 ? 0
                        : (long long)fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
void Pinit(int x) {
  for (Lim = 1; Lim <= x; Lim <<= 1)
    ;
  int w = qpow(_G, (mod - 1) / Lim);
  mg[0] = 1;
  for (int i = (1); i <= (Lim - 1); ++i) mg[i] = (long long)mg[i - 1] * w % mod;
  for (int i = 1; i < Lim; i <<= 1) {
    int sG = qpow(_G, (mod - 1) / (i << 1));
    rt[i] = 1;
    for (int j = (i + 1); j <= (i * 2 - 1); ++j)
      rt[j] = (long long)rt[j - 1] * sG % mod;
  }
}
int rev[N], a[N], b[N];
void dft(int *a, int n, int op) {
  for (int i = (0); i <= (n - 1); ++i)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (n >> 1));
  for (int i = (0); i <= (n - 1); ++i)
    if (i < rev[i]) a[i] ^= a[rev[i]] ^= a[i] ^= a[rev[i]];
  for (int i = 2; i <= n; i <<= 1)
    for (int j = 0, l = (i >> 1); j < n; j += i)
      for (int k = 0, *w = rt + l; k < l; k++, w++) {
        int pa = a[j + k], pb = (long long)a[j + k + l] * *w % mod;
        a[j + k] = (pa + pb >= mod ? pa + pb - mod : pa + pb),
              a[j + k + l] = (pa < pb ? pa - pb + mod : pa - pb);
      }
  if (op != 1) {
    reverse(a + 1, a + n);
    for (int i = 0, iv = qpow(n); i < n; i++) a[i] = (long long)a[i] * iv % mod;
  }
}
inline void dif(vector<int> &a) {
  int n = ((int)(a).size());
  for (int l = n >> 1; l >= 1; l >>= 1)
    for (int j = 0; j < n; j += l << 1)
      for (int k = 0, *w = rt + l; k < l; k++, w++) {
        int x = a[j + k], y = a[j + k + l];
        a[j + k] = (x + y >= mod ? x + y - mod : x + y);
        a[j + k + l] = (long long)*w * (x < y ? x - y + mod : x - y) % mod;
      }
}
inline void dit(vector<int> &a) {
  int n = ((int)(a).size());
  for (int i = 2; i <= n; i <<= 1)
    for (int j = 0, l = (i >> 1); j < n; j += i)
      for (int k = 0, *w = rt + l; k < l; k++, w++) {
        int pa = a[j + k], pb = (long long)a[j + k + l] * *w % mod;
        a[j + k] = (pa + pb >= mod ? pa + pb - mod : pa + pb),
              a[j + k + l] = (pa < pb ? pa - pb + mod : pa - pb);
      }
  reverse(a.begin() + 1, a.end());
  for (int i = 0, iv = qpow(n); i < n; i++) a[i] = (long long)a[i] * iv % mod;
}
int n, B, deg[N], cnt[N], ns, x, y, all;
vector<int> mul(vector<int> a, vector<int> b) {
  int lim = 1, n = ((int)(a).size()) + ((int)(b).size()) - 1;
  for (; lim <= n; lim <<= 1)
    ;
  a.resize(lim), b.resize(lim);
  dif(a), dif(b);
  for (int i = (0); i <= (((int)(a).size()) - 1); ++i)
    a[i] = (long long)a[i] * b[i] % mod;
  dit(a), a.resize(n);
  return a;
}
vector<int> divi(int L, int R) {
  if (L == R) {
    vector<int> v(cnt[L] + 1);
    for (int i = (0); i <= (cnt[L]); ++i)
      v[i] = (long long)C(cnt[L], i) * qpow(L, cnt[L] - i) % mod;
    return v;
  }
  int mid = (L + R) >> 1;
  return mul(divi(L, mid), divi(mid + 1, R));
}
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n, B = min(n - 1, 60), deg[1] = 1;
  init(n);
  for (int i = (1); i <= (n - 1); ++i) cin >> x >> y, deg[x] += 1, deg[y] += 1;
  for (int i = (1); i <= (n); ++i)
    if (deg[i] > 1) cnt[deg[i] - 1] += 1, all += 1;
  Pinit(all);
  for (int i = (0); i <= (Lim - 1); ++i) a[i] = 1;
  for (int i = (1); i <= (B); ++i)
    if (cnt[i])
      for (int j = 0, *w = mg; j < Lim; j++, w++)
        a[j] = (long long)a[j] * qpow(*w + i, cnt[i]) % mod;
  vector<int> ret = divi(B + 1, n);
  for (int i = (0); i <= (((int)(ret).size()) - 1); ++i) b[i] = ret[i];
  dft(b, Lim, 1);
  for (int i = (0); i <= (Lim - 1); ++i) a[i] = (long long)a[i] * b[i] % mod;
  dft(a, Lim, -1);
  for (int i = (0); i <= (all); ++i)
    (ns += (long long)fac[n - i] * a[all - i] % mod * ((i & 1) ? mod - 1 : 1) %
           mod) %= mod;
  cout << ns << '\n';
  return 0;
}
