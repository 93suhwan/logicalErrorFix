#include <bits/stdc++.h>
const int N = 262144;
const int mod = 998244353, G = 3;
const int inv2 = mod + 1 >> 1;
int min(const int a, const int b) { return a < b ? a : b; }
int max(const int a, const int b) { return a > b ? a : b; }
void bmod(int& x) { x += x >> 31 & mod; }
int norm(const int x) { return x < 0 ? x + mod : x; }
void swap(int& a, int& b) { a ^= b ^= a ^= b; }
void reverse(int* st, int* ed) {
  while (st < --ed) swap(*st++, *ed);
}
int inv(int x, int k = mod - 2) {
  int r = 1;
  while (k) {
    if (k & 1) r = (long long)x * r % mod;
    x = (long long)x * x % mod;
    k >>= 1;
  }
  return r;
}
int f[N], g[N];
int lim, last = -1, rev[N], rt[N];
void prework(int n) {
  if (n == last) return;
  last = n, lim = 1;
  while (lim <= n) lim <<= 1;
  for (int i = 0; i < lim; ++i) {
    rev[i] = rev[i >> 1] >> 1 | (i & 1 ? lim >> 1 : 0);
  }
  for (int k = 2, i; k <= lim; k <<= 1) {
    rt[i = k >> 1] = 1;
    long long v = inv(G, (mod - 1) / k);
    for (int j = i + 1; j < k; ++j) {
      rt[j] = rt[j - 1] * v % mod;
    }
  }
}
void NTT(int* f, bool flag = true) {
  if (!flag) reverse(f + 1, f + lim);
  int x, *bf, i, j, k, len;
  for (i = 0; i < lim; ++i) {
    if (i < rev[i]) {
      swap(f[i], f[rev[i]]);
    }
  }
  for (k = 2; k <= lim; k <<= 1) {
    for (len = k >> 1, i = 0; i < lim; i += k) {
      for (j = i, bf = rt + len; j < i + len; ++j, ++bf) {
        x = (long long)f[len + j] * *bf % mod;
        bmod(f[len + j] = f[j] - x);
        bmod(f[j] += x - mod);
      }
    }
  }
  if (flag) return;
  long long v = inv(lim);
  for (i = 0; i < lim; ++i) {
    f[i] = f[i] * v % mod;
  }
}
struct Poly : std::vector<int> {
  Poly() { clear(); }
  Poly(int sz) { resize(sz); }
};
Poly operator+(const Poly& a, const Poly& b) {
  static Poly c;
  c.resize(max(a.size(), b.size()));
  for (int i = 0; i < a.size() || i < b.size(); ++i) {
    bmod(c[i] = (i < a.size() ? a[i] : 0) + (i < b.size() ? b[i] : 0) - mod);
  }
  return c;
}
Poly operator*(const Poly& a, const Poly& b) {
  static Poly c;
  if (!a.size() || !b.size()) return Poly();
  c.resize(a.size() + b.size() - 1);
  for (int i = 0; i < a.size(); ++i) f[i] = a[i];
  for (int i = 0; i < b.size(); ++i) g[i] = b[i];
  prework(c.size());
  NTT(f), NTT(g);
  for (int i = 0; i < lim; ++i) {
    f[i] = (long long)f[i] * g[i] % mod;
  }
  NTT(f, false);
  for (int i = 0; i < c.size(); ++i) c[i] = f[i];
  memset(f, 0, lim << 2);
  memset(g, 0, lim << 2);
  return c;
}
struct Matrix {
  Poly a[4];
  Matrix(){};
  Matrix(Poly b[]) {
    a[0] = b[0];
    a[1] = b[1];
    a[2] = b[2];
    a[3] = b[3];
  }
  Poly& operator[](const int x) { return a[x]; }
  Poly operator[](const int x) const { return a[x]; }
} mat[N];
Matrix operator*(const Matrix& a, const Matrix& b) {
  static Matrix c;
  c[0] = a[0] * b[0] + a[1] * b[2];
  c[1] = a[0] * b[1] + a[1] * b[3];
  c[2] = a[2] * b[0] + a[3] * b[2];
  c[3] = a[2] * b[1] + a[3] * b[3];
  return c;
}
Matrix calc(int l, int r) {
  if (l == r) return mat[r];
  int mid = l + r >> 1;
  return calc(l, mid) * calc(mid + 1, r);
}
int n, a[N];
int fact[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fact[i] = (long long)fact[i - 1] * i % mod;
  }
  int k = 0;
  for (int i = 1, j; i <= n;) {
    j = i;
    while (j - i + 1 <= a[i] && a[j] == a[i]) ++j;
    if (j - i < a[i]) return puts("0"), 0;
    if (++k == 1) {
      if (a[i] == 1) {
        mat[1][0].push_back(0), mat[1][0].push_back(1);
      } else {
        mat[1][1].push_back(0), mat[1][1].push_back(2);
      }
    } else {
      if (a[i] == 1) {
        mat[k][0].push_back(0), mat[k][0].push_back(1);
        mat[k][1].push_back(2);
        mat[k][2] = mat[k][0];
        mat[k][3].push_back(1);
      } else {
        mat[k][1].push_back(2), mat[k][1].push_back(2);
        mat[k][3].push_back(1), mat[k][3].push_back(2);
      }
    }
    i = j;
  }
  if (k > 1) mat[1] = mat[1] * calc(2, k);
  Poly res = mat[1][0] + mat[1][1];
  res.resize(k + 1);
  int ans = 0;
  for (int i = 1; i <= k; ++i) {
    if (k - i & 1) {
      ans = (ans - (long long)fact[i] * res[i]) % mod;
    } else {
      ans = (ans + (long long)fact[i] * res[i]) % mod;
    }
  }
  printf("%d\n", norm(ans));
  return 0;
}
