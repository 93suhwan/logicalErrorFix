#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
template <typename T1, typename T2>
void ckmin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
void ckmax(T1 &a, T2 b) {
  if (a < b) a = b;
}
int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template <typename T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
void print(T x, char let) {
  print(x), putchar(let);
}
const int mlen = 1 << 20;
const int N = mlen + 5;
const int mod = 998244353;
unsigned long long omgs[N];
int rev[N];
int qpow(int a, int b = mod - 2) {
  int res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return res;
}
const int G = qpow(3, (mod - 1) / mlen);
void setup() {
  omgs[mlen / 2] = 1;
  for (int i = mlen / 2 + 1; i < mlen; i++) omgs[i] = G * omgs[i - 1] % mod;
  for (int i = mlen / 2 - 1; i > 0; i--) omgs[i] = omgs[i << 1];
}
int getR(int len) {
  int lim = 1, L = 0;
  while (lim <= len) lim <<= 1, L++;
  for (int i = 0; i < lim; i++)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << L - 1);
  return lim;
}
inline void dft(vector<int> &a, int lim) {
  a.resize(lim);
  static unsigned long long A[N];
  for (int i = 0; i < lim; i++) A[rev[i]] = a[i];
  for (int mid = 1; mid < lim; mid <<= 1) {
    for (int i = 0; i < lim; i += mid << 1) {
      unsigned long long *W = omgs + mid;
      for (int j = 0; j < mid; j++) {
        unsigned long long tmp = *(W++) * A[i + j + mid] % mod;
        A[i + j + mid] = A[i + j] + mod - tmp;
        A[i + j] += tmp;
      }
    }
  }
  for (int i = 0; i < lim; i++) a[i] = A[i] % mod;
}
inline void idft(vector<int> &a, int lim) {
  a.resize(lim);
  dft(a, lim), reverse(a.begin() + 1, a.end());
  int linv = mod - (mod - 1) / lim;
  for (int i = 0; i < lim; i++) a[i] = 1ll * a[i] * linv % mod;
}
vector<int> operator*(vector<int> a, vector<int> b) {
  int len = (int(a.size())) + (int(b.size())) - 1, lim = getR(len);
  if (len <= 300) {
    vector<int> c(len);
    for (int i = 0; i <= (int(a.size())) - 1; i++) {
      for (int j = 0; j <= (int(b.size())) - 1; j++) {
        c[i + j] = (c[i + j] + 1ull * a[i] * b[j]) % mod;
      }
    }
    return c;
  }
  dft(a, lim), dft(b, lim);
  for (int i = 0; i < lim; i++) a[i] = 1ll * a[i] * b[i] % mod;
  idft(a, lim), a.resize(len);
  return a;
}
vector<int> adj[N];
int n;
int son[N];
void dfs1(int u, int fa) {
  for (auto v : adj[u]) {
    if (v == fa) continue;
    son[u]++;
    dfs1(v, u);
  }
}
int fac[N], ifac[N];
inline int C(int n, int m) {
  return 1ll * fac[n] * ifac[n - m] % mod * ifac[m] % mod;
}
int main() {
  setup();
  n = read();
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[n] = qpow(fac[n]);
  for (int i = n; i >= 1; i--) ifac[i - 1] = 1ll * ifac[i] * i % mod;
  for (int i = 1; i <= n - 1; i++) {
    int u = read(), v = read();
    adj[u].push_back(v), adj[v].push_back(u);
  }
  dfs1(1, 0);
  vector<int> f = {1};
  sort(son + 1, son + n + 1, greater<int>());
  for (int i = 1; i <= n; i++) {
    int j = i;
    while (j < n && son[i] == son[j + 1]) j++;
    int up = j - i + 1;
    vector<int> g(up + 1);
    int cf = 1;
    for (int i = 0; i <= up; i++) {
      int coef = 1ll * C(up, i) * cf % mod;
      g[i] = coef;
      cf = 1ll * cf * (mod - son[j]) % mod;
    }
    f = f * g;
    i = j;
  }
  int ans = 0;
  for (int i = 0; i <= n - 1; i++) ans = (ans + 1ll * fac[n - i] * f[i]) % mod;
  print(ans, '\n');
  return 0;
}
