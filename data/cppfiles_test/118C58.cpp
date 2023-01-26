#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 250050;
vector<int> e[maxn];
const int mod = 998244353;
const int G = 3;
int wn[30], iwn[30];
inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline void inc(int& a, int b) {
  if ((a += b) >= mod) a -= mod;
}
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline void dec(int& a, int b) {
  if ((a -= b) < 0) a += mod;
}
inline int mul(int a, int b) { return a * (ll)b % mod; }
inline int qpow(int x, int n) {
  int ans = 1;
  for (; n; n >>= 1, x = (ll)x * x % mod)
    if (n & 1) ans = (ll)ans * x % mod;
  return ans;
}
inline void init() {
  wn[23] = qpow(G, (mod - 1) / (1 << 23));
  for (int i = 22; i >= 0; i--) wn[i] = wn[i + 1] * (ll)wn[i + 1] % mod;
  iwn[23] = qpow(wn[23], (1 << 23) - 1);
  for (int i = 22; i >= 0; i--) iwn[i] = iwn[i + 1] * (ll)iwn[i + 1] % mod;
}
inline void revbin_permute(int a[], int n) {
  int i = 1, j = n >> 1, k;
  for (; i < n - 1; i++) {
    if (i < j) swap(a[i], a[j]);
    for (k = n >> 1; j >= k;) {
      j -= k;
      k >>= 1;
    }
    if (j < k) j += k;
  }
}
void NTT(int f[], int ldn, int is) {
  int n = (1 << ldn);
  revbin_permute(f, n);
  for (int ldm = 1; ldm <= ldn; ldm++) {
    int m = (1 << ldm), mh = (m >> 1);
    int dw = is > 0 ? wn[ldm] : iwn[ldm], w = 1;
    for (int j = 0; j < mh; j++) {
      for (int r = 0; r < n; r += m) {
        ll u = f[r + j], v = f[r + j + mh] * (ll)w % mod;
        f[r + j] = add(u, v);
        f[r + j + mh] = sub(u, v);
      }
      w = w * (ll)dw % mod;
    }
  }
}
void convolution(int f[], int g[], int n) {
  int ldn;
  for (int i = 21; i >= 0; i--)
    if (n == (1 << i)) ldn = i;
  NTT(f, ldn, 1);
  NTT(g, ldn, 1);
  for (int i = 0; i < n; i++) f[i] = f[i] * (ll)g[i] % mod;
  NTT(f, ldn, -1);
  int inv = qpow(n, mod - 2);
  for (int i = 0; i < n; i++) f[i] = f[i] * (ll)inv % mod;
}
int* p[maxn * 4];
int fac[maxn], cnt[maxn];
int gao(int l, int r, int rt) {
  if (l == r) {
    int* x = (int*)malloc(sizeof(int) * 2);
    x[0] = 1, x[1] = cnt[l];
    p[rt] = x;
    return 2;
  }
  int mid = (l + r) / 2;
  int l1 = gao(l, mid, rt << 1), l2 = gao(mid + 1, r, rt << 1 | 1);
  int L = 2 * max(l1, l2);
  int* x = (int*)malloc(sizeof(int) * L);
  int* y = (int*)malloc(sizeof(int) * L);
  for (int i = 0; i < l1; i++) x[i] = p[rt << 1][i];
  for (int i = l1; i < L; i++) x[i] = 0;
  for (int i = 0; i < l2; i++) y[i] = p[rt << 1 | 1][i];
  for (int i = l2; i < L; i++) y[i] = 0;
  convolution(x, y, L);
  p[rt] = x;
  return L;
}
void dfs(int u, int p) {
  for (auto v : e[u]) {
    if (v == p) continue;
    dfs(v, u);
    cnt[u]++;
  }
}
int main(void) {
  init();
  fac[0] = 1;
  for (int i = 1; i < maxn; i++) fac[i] = (ll)fac[i - 1] * i % mod;
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    e[x].push_back(y);
    e[y].push_back(x);
  }
  dfs(1, 0);
  gao(1, n, 1);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      ans = (ans + fac[n - i] * (ll)p[1][i]) % mod;
    } else {
      ans = (ans - fac[n - i] * (ll)p[1][i] % mod + mod) % mod;
    }
  }
  printf("%d\n", ans);
  return 0;
}
