#include <bits/stdc++.h>
template <typename _Tp>
void read(_Tp &x) {
  char ch(getchar());
  bool f(false);
  while (!isdigit(ch)) f |= ch == 45, ch = getchar();
  x = ch & 15, ch = getchar();
  while (isdigit(ch)) x = x * 10 + (ch & 15), ch = getchar();
  if (f) x = -x;
}
template <typename _Tp, typename... Args>
void read(_Tp &t, Args &...args) {
  read(t);
  read(args...);
}
const int max_len = 1 << 18, N = max_len + 5, mod = 998244353,
          inv2 = (mod + 1) / 2;
template <typename _Tp1, typename _Tp2>
inline void add(_Tp1 &a, _Tp2 b) {
  (a += b) >= mod && (a -= mod);
}
template <typename _Tp1, typename _Tp2>
inline void sub(_Tp1 &a, _Tp2 b) {
  (a -= b) < 0 && (a += mod);
}
template <typename _Tp>
inline _Tp _sub(_Tp a, const _Tp &b) {
  (a += mod - b) >= mod && (a -= mod);
  return a;
}
long long ksm(long long a, long long b = mod - 2) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod, b >>= 1;
  }
  return res;
}
void print(const std::vector<int> &a) {
  for (auto it : a) printf("%d ", it);
  printf("\n");
}
inline std::vector<int> operator<<(std::vector<int> a, unsigned int b) {
  return a.insert(a.begin(), b, 0), a;
}
inline std::vector<int> operator<<=(std::vector<int> &a, unsigned int b) {
  return a.insert(a.begin(), b, 0), a;
}
inline std::vector<int> operator>>(const std::vector<int> &a, unsigned int b) {
  return b >= a.size() ? std::vector<int>()
                       : std::vector<int>{a.begin() + b, a.end()};
}
inline std::vector<int> operator>>=(std::vector<int> &a, unsigned int b) {
  return a = b >= a.size() ? std::vector<int>()
                           : std::vector<int>{a.begin() + b, a.end()};
}
std::vector<int> operator+=(std::vector<int> &a, const std::vector<int> &b) {
  if (b.size() > a.size()) a.resize(b.size());
  for (unsigned int i = 0; i < b.size(); ++i) add(a[i], b[i]);
  return a;
}
inline std::vector<int> operator+(const std::vector<int> &a,
                                  const std::vector<int> &b) {
  std::vector<int> tmp(a);
  tmp += b;
  return tmp;
}
std::vector<int> operator-=(std::vector<int> &a, const std::vector<int> &b) {
  if (b.size() > a.size()) a.resize(b.size());
  for (unsigned int i = 0; i < b.size(); ++i) sub(a[i], b[i]);
  return a;
}
inline std::vector<int> operator-(const std::vector<int> &a,
                                  const std::vector<int> &b) {
  std::vector<int> tmp(a);
  tmp -= b;
  return tmp;
}
const unsigned long long Omg = ksm(3, (mod - 1) / max_len);
unsigned long long Omgs[N];
void setup() {
  Omgs[max_len / 2] = 1;
  for (int i = max_len / 2 + 1; i < max_len; ++i)
    Omgs[i] = Omgs[i - 1] * Omg % mod;
  for (int i = max_len / 2 - 1; i > 0; --i) Omgs[i] = Omgs[i << 1];
}
unsigned int rev[N];
unsigned int getlen(unsigned int len) {
  unsigned int limit = 1;
  while (limit < len) limit <<= 1;
  for (unsigned int i = 0; i < limit; ++i)
    rev[i] = (rev[i >> 1] >> 1) | (i & 1 ? limit >> 1 : 0);
  return limit;
}
void dft(unsigned long long *A, unsigned int limit) {
  for (unsigned int i = 0; i < limit; ++i)
    if (i < rev[i]) std::swap(A[i], A[rev[i]]);
  for (unsigned int len = 1; len < limit; len <<= 1) {
    if (len == 262144u)
      for (unsigned int i = 0; i < limit; ++i) A[i] %= mod;
    for (unsigned int i = 0; i < limit; i += len << 1) {
      unsigned long long *p = A + i, *q = A + i + len, *w = Omgs + len;
      for (unsigned int j = 0; j < len; ++j, ++p, ++q, ++w) {
        const unsigned long long tp = *q * *w % mod;
        *q = *p + mod - tp, *p += tp;
      }
    }
  }
  for (unsigned int i = 0; i < limit; ++i) A[i] %= mod;
}
void idft(unsigned long long *A, unsigned int limit) {
  std::reverse(A + 1, A + limit), dft(A, limit);
  unsigned long long inv = mod - (mod - 1) / limit;
  for (unsigned int i = 0; i < limit; ++i) A[i] = A[i] * inv % mod;
}
unsigned long long _f[N], _g[N], _tp[N];
std::vector<int> operator*(const std::vector<int> &a,
                           const std::vector<int> &b) {
  if (a.empty() || b.empty()) return {};
  unsigned int len = a.size() + b.size() - 1;
  if (a.size() <= 64u || b.size() <= 64u) {
    memset(_tp, 0, len << 3);
    unsigned int r = 0;
    for (unsigned int i = 0; i < a.size(); ++i) {
      for (unsigned int j = 0; j < b.size(); ++j)
        _tp[i + j] += 1ULL * a[i] * b[j];
      if (++r == 18) {
        r = 0;
        for (unsigned int j = i - 17; j < i + b.size(); ++j) _tp[j] %= mod;
      }
    }
    if (r)
      for (unsigned int j = 0; j < len; ++j) _tp[j] %= mod;
    std::vector<int> c(len);
    for (unsigned int i = 0; i < len; ++i) c[i] = _tp[i];
    return c;
  }
  unsigned int limit = getlen(len);
  memset(_f + a.size(), 0, (limit - a.size()) << 3);
  for (unsigned int i = 0; i < a.size(); ++i) _f[i] = a[i];
  memset(_g + b.size(), 0, (limit - b.size()) << 3);
  for (unsigned int i = 0; i < b.size(); ++i) _g[i] = b[i];
  dft(_f, limit), dft(_g, limit);
  for (unsigned int i = 0; i < limit; ++i) _f[i] = _f[i] * _g[i] % mod;
  idft(_f, limit);
  std::vector<int> ans(len);
  for (unsigned int i = 0; i < len; ++i) ans[i] = _f[i];
  return ans;
}
std::vector<int> mul(const std::vector<int> &a, const std::vector<int> &b,
                     unsigned int len, bool need = true) {
  if (a.size() <= 64u || b.size() <= 64u) {
    memset(_tp, 0, len << 3);
    unsigned int r = 0;
    for (unsigned int i = 0; i < a.size(); ++i) {
      for (unsigned int j = 0; j < b.size() && i + j < len; ++j)
        _tp[i + j] += 1ULL * a[i] * b[j];
      if (++r == 18) {
        r = 0;
        for (unsigned int j = i - 17; j < len && j < i + b.size(); ++j)
          _tp[j] %= mod;
      }
    }
    if (r)
      for (unsigned int j = 0; j < len; ++j) _tp[j] %= mod;
    std::vector<int> c(len);
    for (unsigned int i = 0; i < len; ++i) c[i] = _tp[i];
    return c;
  }
  int limit = getlen(len);
  memset(_f + a.size(), 0, (limit - a.size()) << 3);
  for (unsigned int i = 0; i < a.size(); ++i) _f[i] = a[i];
  dft(_f, limit);
  if (need) {
    memset(_g + b.size(), 0, (limit - b.size()) << 3);
    for (unsigned int i = 0; i < b.size(); ++i) _g[i] = b[i];
    dft(_g, limit);
  }
  for (int i = 0; i < limit; ++i) _f[i] = 1ULL * _f[i] * _g[i] % mod;
  idft(_f, limit);
  std::vector<int> ans(len);
  for (unsigned int i = 0; i < len; ++i) ans[i] = _f[i];
  return ans;
}
inline std::vector<int> operator*=(std::vector<int> &a,
                                   const std::vector<int> &b) {
  return a = a * b;
}
template <typename _Tp>
inline std::vector<int> operator*=(std::vector<int> &a, const _Tp &b) {
  for (auto &&it : a) it = 1ULL * it * b % mod;
  return a;
}
template <typename _Tp>
inline std::vector<int> operator*(std::vector<int> a, const _Tp &b) {
  return a *= b;
}
template <typename _Tp>
inline std::vector<int> operator*(const _Tp &b, std::vector<int> a) {
  return a *= b;
}
template <typename _Tp>
inline std::vector<int> operator/=(std::vector<int> &a, const _Tp &b) {
  unsigned long long inv = ksm(b);
  for (auto &&it : a) it = 1ULL * it * inv % mod;
  return a;
}
template <typename _Tp>
inline std::vector<int> operator/(std::vector<int> a, const _Tp &b) {
  return a /= b;
}
int a[N], b[N], c[N];
long long fac[N];
struct mat {
  std::vector<int> a[2][2];
  mat operator*(const mat &o) const {
    mat ans;
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j)
        for (int k = 0; k < 2; ++k) ans.a[i][j] += a[i][k] * o.a[k][j];
    return ans;
  }
} M[N];
mat solve(int l, int r) {
  if (l == r) return M[l];
  int mid = (l + r) >> 1;
  return solve(mid + 1, r) * solve(l, mid);
}
int main() {
  fac[0] = 1;
  for (int i = 1; i < N; ++i) fac[i] = fac[i - 1] * i % mod;
  setup();
  int n;
  read(n);
  for (int i = 1; i <= n; ++i) read(a[i]);
  int m = 0;
  for (int i = 1; i <= n; i += a[i]) {
    for (int j = 0; j < a[i]; ++j)
      if (a[i + j] != a[i]) return puts("0"), 0;
    b[m++] = a[i];
  }
  for (int i = 0; i < m; ++i) {
    if (i) M[i].a[1][0] = {mod - 2}, M[i].a[1][1] = {mod - 1};
    if (b[i] == 1)
      M[i].a[0][0] = {0, 1}, M[i].a[0][1] = {0, 1};
    else
      M[i].a[1][0] += {0, 2}, M[i].a[1][1] += {0, 2};
  }
  mat ans = solve(0, m - 1);
  int res = 0;
  for (int a = 0; a < 2; ++a)
    for (int i = 0; i < ((int)ans.a[a][1].size()); ++i)
      add(res, 1LL * ans.a[a][1][i] * fac[i] % mod);
  printf("%d\n", res);
  return 0;
}
