#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int M = 2e6 + 10;
int a[M], b[M], c[M], d[M], e[M], f[M], g[M], h[M];
vector<int> T[M];
struct NTT {
  static const int G = 3, P = 998244353;
  int N, na, nb, w[2][M], rev[M], inv2 = (P + 1) / 2;
  long long kpow(long long a, int b) {
    long long c = 1;
    for (; b; b >>= 1, a = a * a % P)
      if (b & 1) c = c * a % P;
    return c;
  }
  void FFT(int *a, int f) {
    for (int i = (0); i < (N); i++)
      if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int i = 1; i < N; i <<= 1)
      for (int j = 0, t = N / (i << 1); j < N; j += i << 1)
        for (int k = 0, l = 0, x, y; k < i; k++, l += t)
          x = (long long)w[f][l] * a[j + k + i] % P, y = a[j + k],
          a[j + k] = (y + x) % P, a[j + k + i] = (y - x + P) % P;
    if (f)
      for (int i = 0, x = kpow(N, P - 2); i < N; i++)
        a[i] = (long long)a[i] * x % P;
  }
  void work() {
    int d = __builtin_ctz(N);
    w[0][0] = w[1][0] = 1;
    for (int i = 1, x = kpow(G, (P - 1) / N), y = kpow(x, P - 2); i < N; i++) {
      rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (d - 1));
      w[0][i] = (long long)x * w[0][i - 1] % P,
      w[1][i] = (long long)y * w[1][i - 1] % P;
    }
  }
  void doit(int *a, int *b, int na, int nb) {
    for (N = 1; N < na + nb - 1; N <<= 1)
      ;
    for (int i = (na); i < (N); i++) a[i] = 0;
    for (int i = (nb); i < (N); i++) b[i] = 0;
    work(), FFT(a, 0), FFT(b, 0);
    for (int i = (0); i < (N); i++) a[i] = (long long)a[i] * b[i] % P;
    FFT(a, 1);
  }
  void get_inv(int *a, int *b, int na) {
    if (na == 1) {
      b[0] = kpow(a[0], P - 2);
      return;
    }
    get_inv(a, b, (na + 1) >> 1);
    for (N = 1; N < (na << 1); N <<= 1)
      ;
    work();
    for (int i = (0); i < (na); i++) c[i] = a[i];
    for (int i = (na); i < (N); i++) c[i] = 0;
    FFT(c, 0), FFT(b, 0);
    for (int i = (0); i < (N); i++)
      b[i] = 1ll * (2 - 1ll * c[i] * b[i] % P + P) % P * b[i] % P;
    FFT(b, 1);
    for (int i = (na); i < (N); i++) b[i] = 0;
  }
  void get_ln(int *a, int *b, int na) {
    for (int i = (0); i < (na - 1); i++)
      d[i] = (long long)(a[i + 1]) * (i + 1) % P;
    for (N = 1; N < (na << 1); N <<= 1)
      ;
    for (int i = (na); i < (N); i++) d[i] = 0;
    d[na - 1] = 0;
    get_inv(a, b, na);
    doit(b, d, na, na);
    for (int i = (na)-1; i >= (1); i--)
      b[i] = (long long)b[i - 1] * kpow(i, P - 2) % P;
    b[0] = 0;
  }
  void get_exp(int *a, int *b, int na) {
    if (na == 1) {
      b[0] = 1;
      return;
    }
    get_exp(a, b, (na + 1) >> 1);
    for (int i = 0; i < (na << 1); i++) f[i] = 0;
    get_ln(b, f, na);
    for (N = 1; N < (na << 1); N <<= 1)
      ;
    work();
    f[0] = ((long long)a[0] + 1 - f[0] + P) % P;
    for (int i = (1); i < (na); i++) f[i] = ((long long)a[i] - f[i] + P) % P;
    FFT(f, 0);
    FFT(b, 0);
    for (int i = (0); i < (N); i++) b[i] = (long long)b[i] * f[i] % P;
    FFT(b, 1);
    for (int i = (na); i < (N); i++) b[i] = f[i] = 0;
  }
  void get_sqrt(int *a, int *b, int na) {
    if (na == 1) {
      b[0] = 1;
      return;
    }
    get_sqrt(a, b, (na + 1) >> 1);
    for (int i = 0; i < (na << 1); i++) g[i] = 0;
    get_inv(b, g, na);
    for (N = 1; N < (na << 1); N <<= 1)
      ;
    work();
    for (int i = (0); i < (na); i++) h[i] = a[i];
    for (int i = (na); i < (N); i++) h[i] = 0;
    FFT(h, 0);
    FFT(b, 0);
    FFT(g, 0);
    for (int i = (0); i < (N); i++)
      b[i] = (b[i] + (long long)h[i] * g[i] % P) % P * inv2 % P;
    FFT(b, 1);
    for (int i = (na); i < (N); i++) b[i] = 0;
    for (int i = (0); i < (N); i++) h[i] = g[i] = 0;
  }
  void get_pow(int *a, int *b, int na, int k) {
    get_ln(a, e, na);
    for (int i = (0); i < (na); i++) e[i] = (long long)e[i] * k % P;
    get_exp(e, b, na);
  }
  void fast_pow(int *a, int *b, int na, int k, int maxn) {
    for (N = 1; N < max(((maxn + 1) << 1), (na << 1)); N <<= 1)
      ;
    for (int i = (na); i < (N); i++) a[i] = 0;
    for (int i = (0); i < (N); i++) b[i] = 0;
    b[0] = 1;
    work();
    while (k) {
      FFT(a, 0);
      if (k & 1) {
        FFT(b, 0);
        for (int i = (0); i < (N); i++) b[i] = (long long)a[i] * b[i] % P;
        FFT(b, 1);
        for (int i = (max(na, maxn + 1)); i < (N); i++) b[i] = 0;
      }
      for (int i = (0); i < (N); i++) a[i] = (long long)a[i] * a[i] % P;
      FFT(a, 1);
      for (int i = (max(na, maxn + 1)); i < (N); i++) a[i] = 0;
      k >>= 1;
    }
  }
  priority_queue<pair<int, int> > H;
  void Merge(int m) {
    while (!H.empty()) H.pop();
    for (int i = (1); i < (m + 1); i++) H.emplace(make_pair(-T[i].size(), i));
    while (H.size() >= 2) {
      int x = H.top().second;
      H.pop();
      int y = H.top().second;
      H.pop();
      for (int i = (0); i < (T[x].size()); i++) a[i] = T[x][i];
      for (int i = (0); i < (T[y].size()); i++) b[i] = T[y][i];
      doit(a, b, T[x].size(), T[y].size());
      int na = T[x].size() + T[y].size() + 1;
      T[x].clear();
      T[y].clear();
      for (int i = (0); i < (na); i++) T[x].push_back(a[i]);
      H.emplace(-T[x].size(), x);
    }
  }
} ntt;
const int mod = 998244353;
vector<int> v[N];
int fac[N];
int mul(int a, int b) { return 1ll * a * b % mod; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  scanf("%d", &n);
  fac[0] = 1;
  for (int i = 1; i <= n; i++) {
    fac[i] = mul(fac[i - 1], i);
  }
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    T[i].push_back(1);
    T[i].push_back(v[i].size() - (i != 1));
  }
  ntt.Merge(n);
  int id = ntt.H.top().second;
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    if (i & 1) {
      ans -= 1ll * fac[n - i] * T[id][i] % mod;
    } else {
      ans += 1ll * fac[n - i] * T[id][i] % mod;
    }
    ans %= mod;
    ans += mod;
    ans %= mod;
  }
  printf("%d", ans);
  return 0;
}
