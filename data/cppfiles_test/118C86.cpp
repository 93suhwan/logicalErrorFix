#include <bits/stdc++.h>
using namespace std;
const int N = 550010;
const int mod = 998244353, gn = 3;
const int inf = 2147483647;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10ll + ch - '0', ch = getchar();
  return x * f;
}
void up(int& x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
int Pow(int x, int y) {
  if (!y) return 1;
  int t = Pow(x, y >> 1);
  t = (long long)t * t % mod;
  if (y & 1) t = (long long)t * x % mod;
  return t;
}
struct Poly {
  int pw[2][N], rev[N];
  void pre() {
    for (int i = 1; i < N; i++)
      pw[0][i] = Pow(gn, (mod - 1) / (i << 1)),
      pw[1][i] = Pow(gn, mod - 1 - (mod - 1) / (i << 1));
  }
  void init(int n) {
    rev[0] = 0;
    for (int i = 1; i < n; i++)
      rev[i] = ((rev[i >> 1] >> 1) | ((i & 1) * (n >> 1)));
  }
  void print(vector<int> a) {
    for (int x : a) printf("%d ", x);
    puts("");
  }
  void NTT(vector<int>& a, int n, int o) {
    for (int i = 0; i < n; i++)
      if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int i = 1; i < n; i <<= 1) {
      int wn;
      if (o == 1)
        wn = pw[0][i];
      else
        wn = pw[1][i];
      for (int j = 0; j < n; j += (i << 1)) {
        int w = 1;
        for (int k = 0; k < i; k++) {
          int t = (long long)w * a[i + j + k] % mod;
          w = (long long)w * wn % mod;
          a[i + j + k] = (a[j + k] - t + mod) % mod;
          a[j + k] = (a[j + k] + t) % mod;
        }
      }
    }
    if (o == -1) {
      int INV = Pow(n, mod - 2);
      for (int i = 0; i <= n; i++) a[i] = (long long)a[i] * INV % mod;
    }
  }
  vector<int> Mul(vector<int> a, vector<int> b) {
    int len = a.size() + b.size() - 1, n = 1;
    while (n <= len) n <<= 1;
    init(n);
    a.resize(n), b.resize(n);
    NTT(a, n, 1), NTT(b, n, 1);
    for (int i = 0; i <= n; i++) a[i] = (long long)a[i] * b[i] % mod;
    NTT(a, n, -1);
    a.resize(len);
    return a;
  }
  vector<int> Inv(vector<int> a, int deg) {
    if (deg == 1) {
      vector<int> b(1);
      b[0] = Pow(a[0], mod - 2);
      return b;
    }
    vector<int> b = Inv(a, (deg + 1) >> 1);
    int n = 1;
    while (n <= (deg << 1)) n <<= 1;
    init(n);
    a.resize(n), b.resize(n);
    vector<int> c(n);
    for (int i = 0; i < n; i++) c[i] = (i < deg ? a[i] : 0);
    NTT(b, n, 1), NTT(c, n, 1);
    for (int i = 0; i < n; i++)
      b[i] = (2ll - (long long)c[i] * b[i] % mod + mod) % mod * b[i] % mod;
    NTT(b, n, -1);
    b.resize(deg);
    return b;
  }
  void Div(vector<int> F, vector<int> G, vector<int>& Q, vector<int>& R) {
    if (F.size() < G.size()) {
      Q.resize(1);
      Q[0] = 0;
      R = F;
      return;
    }
    vector<int> FR = F, GR = G;
    reverse(FR.begin(), FR.end()), reverse(GR.begin(), GR.end());
    vector<int> invGR = Inv(GR, F.size() - G.size() + 1);
    Q = Mul(FR, invGR), Q.resize(F.size() - G.size() + 1),
    reverse(Q.begin(), Q.end());
    vector<int> tmp = Mul(Q, G);
    R.resize(G.size() - 1);
    for (int i = 0; i < R.size(); i++) R[i] = (F[i] - tmp[i] + mod) % mod;
  }
  vector<int> Power(vector<int> a, vector<int> b, int y) {
    vector<int> t(1), tmp(1);
    t[0] = 1;
    while (y) {
      if (y & 1) Div(Mul(t, a), b, tmp, t);
      Div(Mul(a, a), b, tmp, a);
      y >>= 1;
    }
    return t;
  }
  vector<int> Derivative(vector<int> a) {
    int len = a.size();
    for (int i = 0; i < len - 1; i++)
      a[i] = (long long)a[i + 1] * (i + 1) % mod;
    a.resize(len - 1);
    return a;
  }
  int Linear_Recurrence(vector<int> a, vector<int> f, int k, int n) {
    vector<int> A(2), B(k + 1);
    A[0] = 0;
    A[1] = 1;
    for (int i = 0; i < k; i++) B[i] = (mod - f[k - i]) % mod;
    B[k] = 1;
    A = Power(A, B, n);
    int res = 0;
    for (int i = 0; i < k; i++)
      res = (res + (long long)a[i] * A[i] % mod) % mod;
    return res;
  }
} Poly;
int son[N];
vector<int> G[N];
void dfs(int x, int f) {
  for (int y : G[x]) {
    if (y == f) continue;
    son[x]++;
    dfs(y, x);
  }
}
vector<int> solve(int l, int r) {
  if (l == r) {
    vector<int> a;
    a.resize(2);
    a[0] = 1, a[1] = son[l];
    return a;
  }
  int mid = l + r >> 1;
  return Poly.Mul(solve(l, mid), solve(mid + 1, r));
}
vector<int> ans;
int fac[N];
int main() {
  Poly.pre();
  int n = read();
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = (long long)fac[i - 1] * i % mod;
  for (int i = 1; i < n; i++) {
    int x = read(), y = read();
    G[x].push_back(y), G[y].push_back(x);
  }
  dfs(1, 0);
  ans = solve(1, n);
  int Ans = 0;
  for (int i = 0; i < ans.size(); i++) {
    if (!(i & 1))
      up(Ans, (long long)fac[n - i] * ans[i] % mod);
    else
      up(Ans, mod - (long long)fac[n - i] * ans[i] % mod);
  }
  printf("%d\n", Ans);
  return 0;
}
