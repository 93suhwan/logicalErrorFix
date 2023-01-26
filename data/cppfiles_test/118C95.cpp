#include <bits/stdc++.h>
using namespace std;
const int MAXN = (1 << 19) + 5;
template <typename T>
inline void read(T &WOW) {
  T x = 0, flag = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  WOW = flag * x;
}
namespace ModCalculator {
const int MOD = 998244353;
inline void Inc(int &x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}
inline void Dec(int &x, int y) {
  x -= y;
  if (x < 0) x += MOD;
}
inline int Add(int x, int y) {
  Inc(x, y);
  return x;
}
inline int Sub(int x, int y) {
  Dec(x, y);
  return x;
}
inline int Mul(int x, int y) { return 1LL * x * y % MOD; }
inline int Ksm(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = Mul(ret, x);
    x = Mul(x, x);
  }
  return ret;
}
inline int Inv(int x) { return Ksm(x, MOD - 2); }
}  // namespace ModCalculator
using namespace ModCalculator;
int len, rev[MAXN], w1[MAXN], w2[MAXN], fac[MAXN];
void NTT_init(int n) {
  for (len = 1; len < n; len <<= 1)
    ;
  fac[0] = 1;
  for (int i = 1; i <= len; ++i) {
    fac[i] = Mul(fac[i - 1], i);
  }
  int Gi = 3, Gv = Inv(Gi);
  for (int i = 1; i < len; i <<= 1) {
    int wk1 = Ksm(Gi, (MOD - 1) / (i << 1)), wnk1 = 1;
    int wk2 = Ksm(Gv, (MOD - 1) / (i << 1)), wnk2 = 1;
    for (int k = 0; k < i; ++k) {
      w1[i + k] = wnk1;
      wnk1 = Mul(wnk1, wk1);
      w2[i + k] = wnk2;
      wnk2 = Mul(wnk2, wk2);
    }
  }
}
void GetRev(int n) {
  int bit = -1;
  for (len = 1; len < n; len <<= 1) ++bit;
  for (int i = 0; i < len; ++i) {
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << bit);
  }
}
void NTT(vector<int> &a, int type) {
  a.resize(len);
  int *w = (type == 1 ? w1 : w2);
  for (int i = 0; i < len; ++i) {
    if (i < rev[i]) {
      swap(a[i], a[rev[i]]);
    }
  }
  for (int i = 1; i < len; i <<= 1) {
    for (int j = 0; j < len; j += (i << 1)) {
      for (int k = 0; k < i; ++k) {
        int x = a[j + k], y = Mul(a[j + k + i], w[i + k]);
        a[j + k] = Add(x, y);
        a[j + k + i] = Sub(x, y);
      }
    }
  }
  if (type == 1) return;
  int lenv = Inv(len);
  for (int i = 0; i < len; ++i) {
    a[i] = Mul(a[i], lenv);
  }
}
vector<int> Poly_Mul(vector<int> F, vector<int> G) {
  int deg = F.size() + G.size() - 1;
  if (deg <= 100) {
    vector<int> H(deg, 0);
    int n = F.size(), m = G.size();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        Inc(H[i + j], Mul(F[i], G[j]));
      }
    }
    return H;
  }
  GetRev(deg);
  NTT(F, 1);
  NTT(G, 1);
  for (int i = 0; i < len; ++i) {
    F[i] = Mul(F[i], G[i]);
  }
  NTT(F, -1);
  F.resize(deg);
  return F;
}
int n, deg[MAXN], node[MAXN], tot;
vector<int> Poly_Prod(int l, int r) {
  if (l == r) {
    vector<int> F;
    F.push_back(1);
    F.push_back(node[l]);
    return F;
  }
  int mid = (l + r) >> 1;
  return Poly_Mul(Poly_Prod(l, mid), Poly_Prod(mid + 1, r));
}
void solve() {
  read(n);
  NTT_init((n + 1) << 1);
  for (int i = 1, u, v; i < n; ++i) {
    read(u);
    read(v);
    ++deg[u];
    ++deg[v];
  }
  for (int i = 1; i <= n; ++i) {
    int x = deg[i] - (i > 1);
    if (x) node[++tot] = x;
  }
  vector<int> F = Poly_Prod(1, tot);
  int ans = 0;
  for (int i = 0; i < n && i < F.size(); ++i) {
    int tmp = Mul(F[i], fac[n - i]);
    (i & 1) ? Dec(ans, tmp) : Inc(ans, tmp);
  }
  printf("%d\n", ans);
}
int main() {
  solve();
  return 0;
}
