#include <bits/stdc++.h>
using namespace std;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <class T>
void _W(const T &x) {
  cout << x;
}
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.first);
  putchar(' ');
  _W(x.second);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++))
    if (i != x.cbegin()) putchar(' ');
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
int MOD = 998244353;
void ADD(long long &x, long long v) {
  x = (x + v) % MOD;
  if (x < 0) x += MOD;
}
const int SIZE = 1 << 20;
long long mypow(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x % MOD;
    y >>= 1;
    x = x * x % MOD;
  }
  return res;
}
void add(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += MOD;
}
int mult(int a, int b) { return (long long)a * b % MOD; }
const int inv2 = (MOD + 1) / 2;
namespace NTT {
using T = int;
const int MAXB = 21;
const int MAXN = 1 << MAXB;
int rev[MAXN];
void ntt(T *a, int K, bool inv) {
  const int n = 1 << K;
  rev[0] = 0;
  for (int i = (1); i < (n); ++i) {
    rev[i] = (rev[i >> 1] >> 1) ^ ((i & 1) << (K - 1));
  }
  for (int i = 0; i < (n); ++i) {
    if (i < rev[i]) {
      swap(a[i], a[rev[i]]);
    }
  }
  for (int len = 1; len < n; len *= 2) {
    vector<T> roots(len);
    roots[0] = 1;
    if (len > 1) {
      roots[1] = mypow(3, (MOD - 1) / (2 * len));
    }
    for (int i = (2); i < (len); ++i) {
      roots[i] = mult(roots[i >> 1], roots[(i + 1) >> 1]);
    }
    for (int i = 0; i < n; i += len * 2) {
      for (int j = 0; j < (len); ++j) {
        const auto &w = roots[j];
        const auto x = a[i + j];
        const auto y = mult(a[i + len + j], w);
        a[i + j] = x;
        add(a[i + j], y);
        a[i + len + j] = x;
        sub(a[i + len + j], y);
        if (inv) {
          a[i + j] = mult(a[i + j], inv2);
          a[i + len + j] = mult(a[i + j + len], inv2);
        }
      }
    }
  }
  if (inv) {
    reverse(a + 1, a + n);
  }
}
vector<int> brut_mult(const vector<int> &a, const vector<int> &b) {
  vector<int> c(((int)(a).size()) + ((int)(b).size()));
  for (int i = 0; i < (((int)(a).size())); ++i) {
    for (int j = 0; j < (((int)(b).size())); ++j) {
      add(c[i + j], ::mult(a[i], b[j]));
    }
  }
  return c;
}
vector<int> powr(const vector<int> &a, int m) {
  if (!m) return {1};
  int K = 0;
  while ((1 << K) < ((int)(a).size()) * m) {
    ++K;
  }
  ++K;
  vector<T> A(1 << K);
  for (int i = 0; i < (((int)(a).size())); ++i) {
    A[i] = a[i];
  }
  ntt(A.data(), K, false);
  for (int i = 0; i < (((int)(A).size())); ++i) {
    A[i] = mypow(A[i], m);
  }
  ntt(A.data(), K, true);
  vector<int> res(((int)(A).size()));
  for (int i = 0; i < (((int)(res).size())); ++i) {
    res[i] = A[i];
  }
  int len = ((int)(res).size());
  while (len > 1 && res[len - 1] == 0) len--;
  res.resize(len);
  return res;
}
vector<int> mult(const vector<int> &a, const vector<int> &b) {
  int K = 0;
  while ((1 << K) < max(((int)(a).size()), ((int)(b).size()))) {
    ++K;
  }
  ++K;
  vector<T> A(1 << K);
  vector<T> B(1 << K);
  for (int i = 0; i < (((int)(a).size())); ++i) {
    A[i] = a[i];
  }
  for (int i = 0; i < (((int)(b).size())); ++i) {
    B[i] = b[i];
  }
  ntt(A.data(), K, false);
  ntt(B.data(), K, false);
  for (int i = 0; i < (((int)(A).size())); ++i) {
    A[i] = ::mult(A[i], B[i]);
  }
  ntt(A.data(), K, true);
  vector<int> res(((int)(A).size()));
  for (int i = 0; i < (((int)(A).size())); ++i) {
    res[i] = A[i];
  }
  int len = ((int)(res).size());
  while (len > 1 && res[len - 1] == 0) len--;
  res.resize(len);
  return res;
}
};  // namespace NTT
int n;
vector<int> e[SIZE];
vector<int> gg;
vector<int> AA;
void dfs(int x, int lt) {
  int deg = 0;
  for (int y : e[x]) {
    if (y == lt) continue;
    dfs(y, x);
    deg++;
  }
  if (deg) AA.push_back(deg);
}
vector<int> poly[SIZE];
void build(int L, int R, int id) {
  if (L == R) {
    poly[id] = {1, AA[L]};
    return;
  }
  int mm = (L + R) / 2;
  build(L, mm, id * 2);
  build(mm + 1, R, id * 2 + 1);
  poly[id] = NTT::mult(poly[id * 2], poly[id * 2 + 1]);
}
const int COMBINATION_SIZE = 1 << 21;
long long mypow(long long x, long long y, long long mod = MOD) {
  long long res = 1;
  while (y) {
    if (y & 1) {
      res = res * x % mod;
    }
    y >>= 1;
    x = x * x % mod;
  }
  return res;
}
long long fac[SIZE];
void solve() {
  dfs(1, 1);
  build(0, ((int)(AA).size()) - 1, 1);
  long long an = 0;
  int ng = 1;
  for (int i = 0; i < (((int)(poly[1]).size())); ++i) {
    ADD(an, ng * (long long)poly[1][i] * fac[n - i]);
    ng = -ng;
  }
  W(an);
}
void input() {
  R(n);
  fac[0] = 1;
  for (int i = (1); i <= (n); ++i) fac[i] = fac[i - 1] * i % MOD;
  for (int i = (1); i < (n); ++i) {
    int x, y;
    R(x, y);
    e[x].push_back(y);
    e[y].push_back(x);
  }
}
int main() {
  input();
  solve();
  return 0;
}
