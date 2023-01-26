#include <bits/stdc++.h>
const int mxn = 1 << 19, mod = 998244353;
inline int qpow(int x, int n) {
  int ans = 1;
  for (; n; n >>= 1, x = 1LL * x * x % mod)
    if (n & 1) ans = 1LL * ans * x % mod;
  return ans;
}
int r[mxn], w[mxn];
void fft_init(int n) {
  for (int i = 1; i < n - 1; ++i) r[i] = r[i >> 1] >> 1 | (i & 1 ? n >> 1 : 0);
  for (int h = 1; h < n; h <<= 1) {
    int temp = qpow(3, (mod - 1) / (h << 1));
    for (int i = 0; i < (int)(h); ++i)
      w[h + i] = i ? 1LL * temp * w[h + i - 1] % mod : 1;
  }
}
void fft(int a[], int n, bool flag = false) {
  fft_init(n);
  for (int i = 1; i < n - 1; ++i)
    if (i < r[i]) std::swap(a[i], a[r[i]]);
  for (int h = 1; h < n; h <<= 1)
    for (int i = 0; i < n; i += h << 1)
      for (int j = 0; j < h; ++j) {
        int v = 1LL * a[i + h + j] * w[h + j] % mod;
        a[i + h + j] = a[i + j] - v >= 0 ? a[i + j] - v : a[i + j] + mod - v;
        a[i + j] = a[i + j] + v < mod ? a[i + j] + v : a[i + j] + v - mod;
      }
  if (flag) {
    std::reverse(a + 1, a + n);
    int in = qpow(n, mod - 2);
    for (int i = 0; i < (int)(n); ++i) a[i] = 1LL * a[i] * in % mod;
  }
}
struct poly : std::vector<int> {
  poly(int n, int x = 0) { assign(n, x); }
  poly(std::initializer_list<int> l) {
    clear();
    for (int x : l) push_back(x);
  }
  friend inline poly operator*(const poly &a, const poly &b) {
    int sz = 1;
    while (sz < (int)a.size() + (int)b.size() - 1) sz <<= 1;
    static int A[mxn], B[mxn];
    for (int i = 0; i < (int)(sz); ++i) A[i] = i < (int)a.size() ? a[i] : 0;
    for (int i = 0; i < (int)(sz); ++i) B[i] = i < (int)b.size() ? b[i] : 0;
    fft(A, sz), fft(B, sz);
    for (int i = 0; i < (int)(sz); ++i) A[i] = 1LL * A[i] * B[i] % mod;
    fft(A, sz, true);
    poly c(a.size() + b.size() - 1);
    for (int i = 0; i < (int)(c.size()); ++i) c[i] = A[i];
    return c;
  }
};
int n;
int deg[mxn];
int fac[mxn];
poly calc(int l, int r) {
  if (l + 1 == r) return {1, deg[l]};
  int m = (l + r) >> 1;
  return calc(l, m) * calc(m, r);
}
int main() {
  for (int i = 0; i < (int)(mxn); ++i)
    fac[i] = i ? 1LL * i * fac[i - 1] % mod : 1;
  scanf("%d", &n);
  for (int i = 0; i < (int)(n - 1); ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    ++deg[u];
    ++deg[v];
  }
  for (int i = 0; i < (int)(n); ++i)
    if (i) --deg[i];
  poly p = calc(0, n);
  int ans = 0;
  for (int i = 0; i < (int)(p.size()); ++i) {
    int cur = 1LL * p[i] * fac[n - i] % mod;
    if (i & 1)
      ans = (ans + mod - cur) % mod;
    else
      ans = (ans + cur) % mod;
  }
  printf("%d\n", ans);
  return 0;
}
