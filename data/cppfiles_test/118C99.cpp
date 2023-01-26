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
const int mod = 998244353;
const int G = 3, Gi = 332748118;
void uad(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
int add(int x, int y) {
  if ((x += y) >= mod) x -= mod;
  return x;
}
int sub(int x, int y) {
  if ((x -= y) < 0) x += mod;
  return x;
}
int qpow(int a, int b = mod - 2) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return res;
}
namespace Module {
using namespace std;
const int N = 1 << 19, P = 998244353;
int Pow(long long x, int y = P - 2) {
  int ans = 1;
  for (; y; y >>= 1, x = x * x % P)
    if (y & 1) ans = ans * x % P;
  return ans;
}
int w[N];
unsigned long long F[N];
struct init {
  init() {
    for (int i = 1; i < N; i <<= 1) {
      w[i] = 1;
      int t = Pow(3, (P - 1) / i / 2);
      for (int j = 1; j < i; ++j) w[i + j] = (long long)w[i + j - 1] * t % P;
    }
  }
} foo;
int Get(int x) {
  int n = 1;
  while (n <= x) n <<= 1;
  return n;
}
void DFT(vector<int> &f, int n) {
  if ((int)f.size() != n) f.resize(n);
  for (int i = 0, j = 0; i < n; ++i) {
    F[i] = f[j];
    for (int k = n >> 1; (j ^= k) < k; k >>= 1)
      ;
  }
  for (int i = 1; i < n; i <<= 1)
    for (int j = 0; j < n; j += i << 1) {
      int *W = w + i;
      unsigned long long *F0 = F + j, *F1 = F + j + i;
      for (int k = j; k < j + i; ++k, ++W, ++F0, ++F1) {
        unsigned long long t = (*F1) * *W % P;
        (*F1) = *F0 + P - t, (*F0) += t;
      }
    }
  for (int i = 0; i < n; ++i) f[i] = F[i] % P;
}
void IDFT(vector<int> &f, int n) {
  f.resize(n), reverse(f.begin() + 1, f.end()), DFT(f, n);
  int I = 1;
  for (int i = 1; i < n; i <<= 1) I = (long long)I * (P + 1) / 2 % P;
  for (int i = 0; i < n; ++i) f[i] = (long long)f[i] * I % P;
}
vector<int> operator+(const vector<int> &f, const vector<int> &g) {
  vector<int> ans = f;
  ans.resize(max(f.size(), g.size()));
  for (int i = 0; i < (int)g.size(); ++i) (ans[i] += g[i]) %= P;
  return ans;
}
vector<int> operator*(const vector<int> &f, const vector<int> &g) {
  vector<int> F, G;
  int len = (int(f.size())) + (int(g.size())) - 1;
  if (len <= 1000) {
    vector<int> c(len);
    for (int i = 0; i <= (int(f.size())) - 1; i++) {
      for (int j = 0; j <= (int(g.size())) - 1; j++) {
        c[i + j] = (c[i + j] + 1ull * f[i] * g[j]) % mod;
      }
    }
    return c;
  }
  F = f, G = g;
  int p = Get(f.size() + g.size() - 2);
  DFT(F, p), DFT(G, p);
  for (int i = 0; i < p; ++i) F[i] = (long long)F[i] * G[i] % P;
  IDFT(F, p);
  return F.resize(f.size() + g.size() - 1), F;
}
vector<int> Inv(const vector<int> &f, int n = -1) {
  if (n == -1) n = f.size();
  if (n == 1) return {Pow(f[0])};
  vector<int> ans = Inv(f, (n + 1) / 2), tmp(f.begin(), f.begin() + n);
  int p = Get(n * 2 - 2);
  DFT(tmp, p), DFT(ans, p);
  for (int i = 0; i < p; ++i)
    ans[i] = (2 - (long long)ans[i] * tmp[i] % P + P) * ans[i] % P;
  IDFT(ans, p);
  return ans.resize(n), ans;
}
vector<int> Mod(const vector<int> &a, const vector<int> &b) {
  if (b.size() > a.size()) return a;
  vector<int> A = a, B = b, iB;
  int n = a.size(), m = b.size();
  reverse(A.begin(), A.end()), reverse(B.begin(), B.end());
  B.resize(n - m + 1), iB = Inv(B, n - m + 1);
  vector<int> d = A * iB;
  d.resize(n - m + 1), reverse(d.begin(), d.end());
  vector<int> r = b * d;
  r.resize(m - 1);
  for (int i = 0; i < m - 1; ++i) r[i] = (a[i] - r[i] + P) % P;
  return r;
}
vector<int> Prod(const vector<int> &a, const vector<int> &b) { return a * b; }
void wf(vector<int> &a) {
  int n = a.size();
  for (int i = 0; i < n; i++) a[i] = 1ll * (i + 1) * a[i + 1] % mod;
  a[n - 1] = 0;
}
void jf(vector<int> &a) {
  int n = a.size();
  for (int i = n - 1; i >= 1; i--) a[i] = 1ll * a[i - 1] * qpow(i) % mod;
  a[0] = 0;
}
vector<int> Ln(vector<int> a) {
  vector<int> ta = a;
  wf(ta);
  int len = a.size();
  a = ta * Inv(a), jf(a);
  a.resize(len);
  return a;
}
vector<int> Exp(vector<int> a) {
  if ((int(a.size())) == 1) return vector<int>(1, 1);
  int len = a.size();
  vector<int> ta = a;
  ta.resize((len + 1) / 2);
  vector<int> tb = Exp(ta);
  tb.resize(len);
  vector<int> Lnb = Ln(tb);
  assert(Lnb.size() == len);
  for (int i = 0; i < len; i++) Lnb[i] = (a[i] - Lnb[i] + mod) % mod;
  Lnb[0] = (Lnb[0] + 1) % mod;
  tb = tb * Lnb;
  tb.resize(len);
  return tb;
}
}  // namespace Module
using Module::operator*;
const int N = 250005;
const int B = 30;
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
int two[N], len;
vector<int> solve(int l, int r) {
  if (l > r) return {1};
  if (l == r) return {1, mod - two[l]};
  int mid = l + r >> 1;
  return solve(l, mid) * solve(mid + 1, r);
}
int fac[N], inv[N];
int fuck[N];
int main() {
  n = read();
  inv[1] = 1;
  for (int i = 2; i <= n; i++)
    inv[i] = 1ull * (mod - mod / i) * inv[mod % i] % mod;
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ull * fac[i - 1] * i % mod;
  for (int i = 1; i <= n - 1; i++) {
    int u = read(), v = read();
    adj[u].push_back(v), adj[v].push_back(u);
  }
  dfs1(1, 0);
  vector<int> ONE(n + 1);
  for (int i = 1; i <= n; i++) {
    if (son[i] > B) {
      two[++len] = son[i];
    } else {
      fuck[son[i]]++;
    }
  }
  for (int i = 1; i <= B; i++) {
    int coef = 1;
    for (int j = 1; j <= n; j++) {
      coef = 1ull * coef * i % mod;
      ONE[j] = sub(ONE[j], 1ull * fuck[i] * coef % mod * inv[j] % mod);
    }
  }
  ONE = Module::Exp(ONE);
  vector<int> TWO = solve(1, len);
  vector<int> f = ONE * TWO;
  int ans = 0;
  for (int i = 0; i <= n - 1; i++) ans = (ans + 1ll * fac[n - i] * f[i]) % mod;
  print(ans, '\n');
  return 0;
}
