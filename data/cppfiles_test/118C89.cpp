#include <bits/stdc++.h>
using namespace std;
const int N = 8e5 + 5, P = 998244353, G = 3;
int A[N], rev[N], mod, inv[N], fact[N], infact[N];
int lim = 1, len = 0, W[20][N];
int inline power(int a, int b, int Mod = P) {
  int res = 1;
  while (b) {
    if (b & 1) res = (long long)res * a % Mod;
    a = (long long)a * a % Mod;
    b >>= 1;
  }
  return res;
}
namespace Red {
int MOD, I;
struct Num {
  int x, y;
};
Num operator*(const Num a, const Num b) {
  return (Num){(int)(((long long)a.x * b.x + (long long)I * a.y % P * b.y) % P),
               (int)(((long long)a.x * b.y + (long long)a.y * b.x) % P)};
}
int inline power(int a, int b, int Mod = P) {
  int res = 1;
  while (b) {
    if (b & 1) res = (long long)res * a % Mod;
    a = (long long)a * a % Mod;
    b >>= 1;
  }
  return res;
}
Num inline power(Num a, int b) {
  Num res = (Num){1, 0};
  while (b) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
int inline EulerCri(int x) { return power(x, (MOD - 1) >> 1, MOD); }
int inline Sqrt(int n, int o) {
  MOD = o;
  if (n == 0) return 0;
  if (EulerCri(n) == P - 1) return -1;
  int a = rand() % P, t;
  while (EulerCri(t = ((long long)a * a + MOD - n) % P) != MOD - 1)
    a = rand() % MOD;
  I = t;
  int x0 = power((Num){a, 1}, (P + 1) >> 1).x;
  return min(x0, P - x0);
}
}  // namespace Red
int Gi = power(G, P - 2, P), inv2 = power(2, P - 2, P);
void inline NTT(int c[], int lim, int o) {
  for (int i = 0; i < lim; i++)
    if (i < rev[i]) swap(c[i], c[rev[i]]);
  for (int k = 1, t = 0; k < lim; k <<= 1, t++) {
    for (int i = 0; i < lim; i += (k << 1)) {
      for (int j = 0; j < k; j++) {
        int u = c[i + j], v = (long long)c[i + k + j] * W[t][j] % P;
        c[i + j] = u + v >= P ? u + v - P : u + v;
        c[i + j + k] = u - v < 0 ? u - v + P : u - v;
      }
    }
  }
  if (o == -1) {
    reverse(c + 1, c + lim);
    int inv = power(lim, P - 2, P);
    for (int i = 0; i < lim; i++) c[i] = (long long)c[i] * inv % P;
  }
}
void inline setN(int n) {
  lim = 1, len = 0;
  while (lim < n) lim <<= 1, len++;
  for (int i = 0; i < lim; i++)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (len - 1));
}
vector<int> inline NTT(vector<int> a, int o) {
  int n = a.size();
  for (int i = 0; i < n; i++) A[i] = a[i];
  NTT(A, lim, o);
  a.clear();
  for (int i = 0; i < lim; i++) a.push_back(A[i]), A[i] = 0;
  return a;
}
vector<int> operator+(const vector<int> a, const vector<int> b) {
  vector<int> c(max(a.size(), b.size()));
  for (int i = 0; i < c.size(); i++) {
    if (i < a.size()) {
      c[i] += a[i];
      if (c[i] >= P) c[i] -= P;
    }
    if (i < b.size()) {
      c[i] += b[i];
      if (c[i] >= P) c[i] -= P;
    }
  }
  return c;
}
vector<int> operator-(const vector<int> a, const vector<int> b) {
  vector<int> c(max(a.size(), b.size()));
  for (int i = 0; i < c.size(); i++) {
    if (i < a.size()) {
      c[i] += a[i];
      if (c[i] >= P) c[i] -= P;
    }
    if (i < b.size()) {
      c[i] -= b[i];
      if (c[i] < 0) c[i] += P;
    }
  }
  return c;
}
vector<int> inline mul(vector<int> a, vector<int> b, int newn = -1) {
  if (newn == -1) newn = a.size() + b.size() - 1;
  setN(a.size() + b.size() - 1);
  vector<int> c = NTT(a, 1), d = NTT(b, 1);
  for (int i = 0; i < lim; i++) c[i] = (long long)c[i] * d[i] % P;
  d = NTT(c, -1);
  d.resize(newn);
  return d;
}
vector<int> inline reverse(vector<int> a) {
  int n = a.size() - 1;
  for (int i = 0; i < n - i; i++) swap(a[i], a[n - i]);
  return a;
}
vector<int> inline dx(vector<int> a) {
  int n = a.size();
  vector<int> b;
  b.resize(n - 1);
  for (int i = 0; i < b.size(); i++) b[i] = a[i + 1] * (i + 1ll) % P;
  return b;
}
vector<int> inline F(vector<int> a) {
  int n = a.size();
  vector<int> b;
  b.resize(n + 1);
  for (int i = 1; i < b.size(); i++) b[i] = (long long)a[i - 1] * inv[i] % P;
  return b;
}
vector<int> polyInv(vector<int> a) {
  int n = a.size();
  if (n == 1) {
    vector<int> b;
    b.push_back(power(a[0], P - 2, P));
    return b;
  }
  vector<int> b = a;
  b.resize((n + 1) >> 1);
  b = polyInv(b);
  setN(2 * n);
  a = NTT(a, 1), b = NTT(b, 1);
  for (int i = 0; i < lim; i++)
    b[i] = (long long)b[i] * (2ll - (long long)a[i] * b[i] % P + P) % P;
  b = NTT(b, -1);
  b.resize(n);
  return b;
}
void inline div(vector<int> a, vector<int> b, vector<int> &Q, vector<int> &R) {
  int n = a.size() - 1, m = b.size() - 1;
  vector<int> ar = reverse(a), br = reverse(b);
  ar.resize(n - m + 1), br.resize(n - m + 1);
  Q = reverse(mul(ar, polyInv(br), n - m + 1));
  R = a - mul(b, Q);
  R.resize(m);
}
vector<int> t(1, 1);
vector<int> sqrt(vector<int> a) {
  int n = a.size();
  if (n == 1) {
    vector<int> k;
    k.resize(1);
    k[0] = Red::Sqrt(a[0], P);
    return k;
  }
  vector<int> b = a;
  b.resize((n + 1) >> 1);
  b = sqrt(b), b.resize(n);
  vector<int> c = polyInv(b);
  setN(2 * n);
  b = NTT(b, 1), c = NTT(c, 1), a = NTT(a, 1);
  for (int i = 0; i < lim; i++)
    b[i] = (long long)inv2 * (b[i] + (long long)a[i] * c[i] % P) % P;
  b = NTT(b, -1);
  b.resize(n);
  return b;
}
vector<int> inline ln(vector<int> a) {
  vector<int> b = F(mul(dx(a), polyInv(a)));
  b.resize(a.size());
  return b;
}
vector<int> exp(vector<int> a) {
  int n = a.size();
  if (n == 1) return t;
  vector<int> b = a;
  b.resize((n + 1) >> 1);
  b = exp(b);
  b.resize(n);
  vector<int> c = a - ln(b);
  (c[0] += 1) %= P;
  b = mul(b, c, a.size());
  return b;
}
void cdq(int l, int r) {
  if (r - l <= 0) return;
  int mid = (l + r) >> 1, len = r - l;
  cdq(l, mid);
  cdq(mid + 1, r);
}
void inline preInv(int n) {
  inv[1] = 1;
  for (int i = 2; i <= n; i++) inv[i] = ((long long)P - P / i) * inv[P % i] % P;
}
bool ok = false;
vector<int> inline power(vector<int> a, int b) {
  int Mul = 1, Cy = 0, n = a.size();
  if (b == 0) {
    vector<int> c(n, 0);
    c[0] = power(a[0], b, P);
    return c;
  }
  if (a[0] == 0) {
    for (Cy = 1; Cy < n; Cy++)
      if (a[Cy]) break;
    if (ok || (long long)Cy * b >= n) {
      vector<int> c(n, 0);
      return c;
    }
    for (int i = 0; i + Cy < n; i++) a[i] = a[i + Cy];
    for (int i = n - Cy; i < n; i++) a[i] = 0;
    Cy *= b;
  }
  if (a[0] != 1) {
    int in = power(a[0], P - 2, P);
    Mul = power(a[0], b, P);
    for (int i = 0; i < n; i++) a[i] = (long long)a[i] * in % P;
  }
  a = ln(a);
  for (int i = 0; i < n; i++) a[i] = (long long)a[i] * b % P;
  a = exp(a);
  if (Mul != 1)
    for (int i = 0; i < n; i++) a[i] = (long long)a[i] * Mul % P;
  if (Cy) {
    for (int i = n - 1; i >= Cy; i--) a[i] = a[i - Cy];
    for (int i = 0; i < Cy; i++) a[i] = 0;
  }
  return a;
}
void inline factPrework(int n) {
  fact[0] = infact[0] = 1;
  for (int i = 1; i <= n; i++) fact[i] = (long long)fact[i - 1] * i % P;
  infact[n] = power(fact[n], P - 2);
  for (int i = n - 1; i; i--) infact[i] = infact[i + 1] * (i + 1ll) % P;
}
void inline init(int n) {
  preInv(n);
  factPrework(n);
  setN(2 * n);
  for (int k = 1, t = 0; k < lim; k <<= 1, t++) {
    int wn = power(G, (P - 1) / (k << 1));
    W[t][0] = 1;
    for (int j = 1; j < k; j++) W[t][j] = (long long)W[t][j - 1] * wn % P;
  }
}
int bx[N], by[N];
vector<int> b[N];
void MpeBuild(int p, int l, int r) {
  if (l == r) {
    b[p].resize(2);
    b[p][0] = P - bx[r], b[p][1] = 1;
    return;
  }
  int mid = (l + r) >> 1;
  MpeBuild(p << 1, l, mid);
  MpeBuild(p << 1 | 1, mid + 1, r);
  b[p] = mul(b[p << 1], b[p << 1 | 1]);
}
void MpeSolve(int p, int l, int r, vector<int> a) {
  vector<int> Q, R;
  if (a.size() >= b[p].size()) div(a, b[p], Q, R), a = R;
  if (l == r) {
    by[r] = a[0];
    return;
  }
  int mid = (l + r) >> 1;
  MpeSolve(p << 1, l, mid, a);
  MpeSolve(p << 1 | 1, mid + 1, r, a);
}
void MpeEva(int n, int m, vector<int> f, int X[], int Y[]) {
  for (int i = 1; i <= m; i++) bx[i] = X[i];
  MpeBuild(1, 1, m);
  MpeSolve(1, 1, m, f);
  for (int i = 1; i <= m; i++) Y[i] = by[i];
}
vector<int> bc[N];
void InterSolve(int p, int l, int r) {
  if (l == r) {
    bc[p].resize(1);
    bc[p][0] = by[r];
    return;
  }
  int mid = (l + r) >> 1;
  InterSolve(p << 1, l, mid);
  InterSolve(p << 1 | 1, mid + 1, r);
  bc[p] = mul(bc[p << 1], b[p << 1 | 1]) + mul(bc[p << 1 | 1], b[p << 1]);
}
vector<int> polyInterpo(int n, int X[], int Y[]) {
  for (int i = 1; i <= n; i++) bx[i] = X[i];
  MpeBuild(1, 1, n);
  vector<int> f = dx(b[1]);
  MpeSolve(1, 1, n, f);
  for (int i = 1; i <= n; i++)
    by[i] = (long long)Y[i] * power(by[i], P - 2) % P;
  InterSolve(1, 1, n);
  return bc[1];
}
int inline LRS(int b, vector<int> f, vector<int> g) {
  int k = g.size() - 1;
  g[0] = 1;
  for (int i = 1; i <= k; i++) g[i] = (P - g[i]) % P;
  vector<int> h = mul(f, g, k);
  while (b) {
    vector<int> g2 = g;
    for (int i = 0; i < g2.size(); i += 2) g2[i] = (P - g2[i]) % P;
    vector<int> t = mul(g2, g);
    g.clear();
    for (int i = 0; i < t.size(); i += 2) g.push_back(t[i]);
    t = mul(g2, h);
    h.clear();
    for (int i = (b & 1); i < t.size(); i += 2) h.push_back(t[i]);
    b >>= 1;
  }
  return (long long)h[0] * power(g[0], P - 2) % P;
}
int sz[N];
int n;
vector<int> g[N];
void dfs(int u, int fa) {
  sz[u] = 0;
  for (int v : g[u]) {
    if (v == fa) continue;
    dfs(v, u);
    sz[u]++;
  }
}
vector<int> solve(int l, int r) {
  if (l == r) {
    vector<int> t;
    t.push_back(1);
    t.push_back(sz[r]);
    return t;
  }
  int mid = (l + r) >> 1;
  return mul(solve(l, mid), solve(mid + 1, r));
}
template <typename T>
void inline read(T &x) {
  int f = 1;
  x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
  x *= f;
}
void inline add(int &x, int y) {
  x += y;
  if (x >= P) x -= P;
}
int main() {
  init(250001);
  read(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    read(u), read(v);
    g[u].push_back(v), g[v].push_back(u);
  }
  dfs(1, 0);
  vector<int> c = solve(1, n);
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    int v = 1ll * c[i] * fact[n - i] % P;
    if (i & 1)
      add(ans, P - v);
    else
      add(ans, v);
  }
  printf("%d\n", ans);
  return 0;
}
