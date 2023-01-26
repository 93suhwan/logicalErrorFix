#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return x * f;
}
int n, a[266666], c[266666], dp[2][2][266666], fac[266666];
const int mod = 998244353;
int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = 1LL * ans * a % mod;
    a = 1LL * a * a % mod;
    b >>= 1;
  }
  return ans;
}
namespace Poly {
const int G = 3;
const int invG = qpow(G, mod - 2);
int tr[266666], GG[2][21][266666], inv[266666];
void Init(const int t) {
  for (int p = 1; p <= t; ++p) {
    int buf1 = qpow(G, (mod - 1) / (1 << p));
    int buf0 = qpow(invG, (mod - 1) / (1 << p));
    GG[0][p][0] = GG[1][p][0] = 1;
    for (int i = 1; i < (1 << p); ++i) {
      GG[0][p][i] = 1LL * GG[0][p][i - 1] * buf0 % mod;
      GG[1][p][i] = 1LL * GG[1][p][i - 1] * buf1 % mod;
    }
  }
  inv[1] = 1;
  for (int i = 2; i <= (1 << t); ++i) {
    inv[i] = 1LL * inv[mod % i] * (mod - mod / i) % mod;
  }
}
int NTT_init(int n) {
  int lim = 1;
  while (lim < n) lim <<= 1;
  for (int i = 0; i < lim; ++i) {
    tr[i] = ((tr[i >> 1] >> 1) | (i & 1 ? lim >> 1 : 0));
  }
  return lim;
}
void NTT(vector<int> &f, int flag, int n) {
  f.resize(n);
  for (int i = 0; i < n; ++i) {
    if (i < tr[i]) swap(f[i], f[tr[i]]);
  }
  for (int p = 2, j = 1; p <= n; p <<= 1, ++j) {
    int len = p >> 1;
    for (int k = 0; k < n; k += p) {
      int *buf = GG[flag][j];
      for (int i = k; i < k + len; ++i, ++buf) {
        int tmp = 1LL * (*buf) * f[i + len] % mod;
        f[i + len] = (f[i] - tmp + mod >= mod ? f[i] - tmp + mod - mod
                                              : f[i] - tmp + mod);
        f[i] = (f[i] + tmp >= mod ? f[i] + tmp - mod : f[i] + tmp);
      }
    }
  }
  if (!flag) {
    for (int i = 0; i < n; ++i) {
      f[i] = 1LL * f[i] * inv[n] % mod;
    }
  }
}
vector<int> Rshift(vector<int> A, int x) {
  A.resize(A.size() + x);
  for (int i = (int)A.size() - 1; i >= x; --i) {
    A[i] = A[i - x];
  }
  for (int i = 0; i < x; ++i) A[i] = 0;
  return A;
}
vector<int> Lshift(vector<int> A, int x) {
  if ((int)A.size() <= x) return vector<int>(1, 0);
  for (int i = 0; i < (int)A.size() - x; ++i) {
    A[i] = A[i + x];
  }
  return A;
}
vector<int> Plus(vector<int> A, vector<int> B) {
  int n = max(A.size(), B.size());
  A.resize(n), B.resize(n);
  for (int i = 0; i < n; ++i) {
    A[i] = (A[i] + B[i]) % mod;
  }
  return A;
}
vector<int> Mul(vector<int> A, vector<int> B) {
  int n = A.size() + B.size() - 1;
  int lim = NTT_init(n);
  vector<int> C(lim);
  NTT(A, 1, lim), NTT(B, 1, lim);
  for (int i = 0; i < lim; ++i) {
    C[i] = 1LL * A[i] * B[i] % mod;
  }
  NTT(C, 0, lim);
  C.resize(n);
  return C;
}
vector<int> Inv(vector<int> &f, int m) {
  if (m == 1) {
    return vector<int>(1, qpow(f[0], mod - 2));
  }
  vector<int> A(f.begin(), f.begin() + m);
  vector<int> B = Inv(f, (m + 1) >> 1);
  int lim = NTT_init(m << 1);
  NTT(A, 1, lim), NTT(B, 1, lim);
  for (int i = 0; i < lim; ++i) {
    A[i] = B[i] * (2 - 1LL * A[i] * B[i] % mod + mod) % mod;
  }
  NTT(A, 0, lim);
  A.resize(m);
  return A;
}
vector<int> WeiF(vector<int> f) {
  int n = f.size();
  if (n == 1) return f[0] = 0, f;
  for (int i = 1; i < n; ++i) f[i - 1] = 1LL * f[i] * i % mod;
  return f.resize(n - 1), f;
}
vector<int> JiF(vector<int> f) {
  int n = f.size();
  for (int i = n - 1; i; --i) f[i] = 1LL * f[i - 1] * inv[i] % mod;
  return f[0] = 0, f;
}
vector<int> Ln(vector<int> f, int n) {
  f.resize(n);
  vector<int> A = JiF(Mul(WeiF(f), Inv(f, n)));
  return A.resize(n), A;
}
vector<int> Exp(vector<int> &f, int m) {
  if (m == 1) {
    return vector<int>(1, 1);
  }
  vector<int> B = Exp(f, (m + 1) >> 1);
  vector<int> lnB = Ln(B, m);
  for (int i = 0; i < m; ++i) {
    lnB[i] = (f[i] - lnB[i] + mod >= mod ? f[i] - lnB[i] + mod - mod
                                         : f[i] - lnB[i] + mod);
  }
  int lim = NTT_init(m << 1);
  NTT(B, 1, lim), NTT(lnB, 1, lim);
  for (int i = 0; i < lim; ++i) {
    B[i] = 1LL * B[i] * (1 + lnB[i]) % mod;
  }
  NTT(B, 0, lim);
  B.resize(m);
  return B;
}
vector<int> Sqrt(vector<int> &f, int m) {
  if (m == 1) {
    return vector<int>(1, 1);
  }
  vector<int> A(f.begin(), f.begin() + m);
  vector<int> B = Sqrt(f, (m + 1) >> 1);
  vector<int> iB = Inv(B, m);
  int lim = NTT_init(m << 1);
  NTT(A, 1, lim), NTT(iB, 1, lim);
  for (int i = 0; i < lim; ++i) {
    A[i] = 1LL * A[i] * iB[i] % mod;
  }
  NTT(A, 0, lim);
  for (int i = 0; i < m; ++i) {
    A[i] = 1LL * (A[i] + B[i]) * inv[2] % mod;
  }
  A.resize(m);
  return A;
}
vector<int> Pow(vector<int> f, int k) {
  f = Ln(f, f.size());
  for (auto &x : f) x = 1LL * x * k % mod;
  return Exp(f, f.size());
}
vector<int> MulT(vector<int> A, vector<int> &B, int n) {
  int lim = A.size();
  NTT_init(lim);
  for (int i = 0; i < lim; ++i) {
    A[i] = 1LL * A[i] * B[i] % mod;
  }
  NTT(A, 1, lim);
  A.resize(n);
  return A;
}
vector<int> nd[266666 << 2];
void build(int u, int l, int r, vector<int> &f) {
  if (l + 1 == r) {
    nd[u] = vector<int>({1, mod - f[l]});
    return;
  }
  int mid = (l + r + 1) >> 1;
  build(u << 1, l, mid, f), build(u << 1 | 1, mid, r, f);
  int lim = NTT_init(r - l + 1);
  NTT(nd[u << 1], 1, lim), NTT(nd[u << 1 | 1], 1, lim);
  nd[u].resize(lim);
  for (int i = 0; i < lim; ++i) {
    nd[u][i] = 1LL * nd[u << 1][i] * nd[u << 1 | 1][i] % mod;
  }
  NTT(nd[u], 0, lim);
}
void work(int u, int l, int r, vector<int> f, vector<int> &g) {
  if (l + 1 == r) {
    g[l] = f[0];
    return;
  }
  int mid = (l + r + 1) >> 1;
  int lim = NTT_init(r - l + 1);
  NTT(f, 0, lim);
  work(u << 1, l, mid, MulT(f, nd[u << 1 | 1], mid - l), g);
  work(u << 1 | 1, mid, r, MulT(f, nd[u << 1], r - mid), g);
}
vector<int> Evaluate(vector<int> f, vector<int> x) {
  int n = f.size(), m = x.size();
  n = max(n, m);
  f.resize(n), x.resize(n);
  build(1, 0, n, x);
  nd[1] = Inv(nd[1], n);
  int lim = NTT_init(2 * n - 1);
  NTT(nd[1], 1, lim);
  NTT(f, 0, lim);
  vector<int> g(n);
  work(1, 0, n, MulT(f, nd[1], n), g);
  g.resize(m);
  return g;
}
}  // namespace Poly
using Poly::Mul;
using Poly::Plus;
using Poly::vector<int>;
struct Matrix {
  vector<int> g[2][2];
  friend Matrix operator*(const Matrix &a, const Matrix &b) {
    Matrix c;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        c.g[i][j] = Plus(Mul(a.g[i][0], b.g[0][j]), Mul(a.g[i][1], b.g[1][j]));
      }
    }
    return c;
  }
};
Matrix Solve(int L, int R) {
  Matrix ans;
  if (L == R) {
    if (a[L] == 1) {
      ans.g[0][0] = ans.g[1][0] = vector<int>({0, 1});
      ans.g[0][1] = vector<int>({2}), ans.g[1][1] = vector<int>({1});
    } else {
      ans.g[0][0] = ans.g[1][0] = vector<int>({0});
      ans.g[0][1] = vector<int>({2, 2}), ans.g[1][1] = vector<int>({1, 2});
    }
    return ans;
  }
  int mid = (L + R) >> 1;
  ans = Solve(L, mid) * Solve(mid + 1, R);
  return ans;
}
int main() {
  Poly::Init(18);
  n = read();
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) {
    c[i] = read();
    fac[i] = 1LL * fac[i - 1] * i % mod;
  }
  int _n = 0;
  for (int i = 1; i <= n;) {
    a[++_n] = c[i];
    if (i + c[i] > n + 1) {
      return !printf("0\n");
    }
    int x = c[i], tmp = c[i];
    while (x--) {
      if (c[i++] ^ tmp) {
        return !printf("0\n");
      }
    }
  }
  n = _n;
  Matrix A;
  if (a[1] == 1)
    A.g[0][0] = vector<int>({0, 1});
  else
    A.g[0][1] = vector<int>({0, 2});
  if (n > 1) A = A * Solve(2, n);
  A.g[0][0].resize(n + 1);
  A.g[0][1].resize(n + 1);
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans = (ans + 1LL * ((n - i) & 1 ? mod - fac[i] : fac[i]) *
                     (A.g[0][0][i] + A.g[0][1][i])) %
          mod;
  }
  printf("%d\n", ans);
  return 0;
}
