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
const int max_len = 1 << 17, N = max_len + 5, mod = 998244353;
template <typename _Tp1, typename _Tp2>
inline void add(_Tp1 &a, _Tp2 b) {
  (a += b) >= mod && (a -= mod);
}
template <typename _Tp1, typename _Tp2>
inline void sub(_Tp1 &a, _Tp2 b) {
  (a -= b) < 0 && (a += mod);
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
unsigned long long Omgs[N];
int r[N];
const unsigned long long Omg = ksm(3, (mod - 1) / max_len);
int getlen(int len) {
  int limit = 1;
  while (limit < len) limit <<= 1;
  for (int i = 0; i < limit; ++i)
    r[i] = (r[i >> 1] >> 1) | (i & 1 ? limit >> 1 : 0);
  return limit;
}
void setup() {
  Omgs[max_len >> 1] = 1;
  for (int i = (max_len >> 1) + 1; i < max_len; ++i)
    Omgs[i] = Omgs[i - 1] * Omg % mod;
  for (int i = (max_len >> 1) - 1; i > 0; --i) Omgs[i] = Omgs[i << 1];
}
void dft(unsigned long long *A, int limit) {
  for (int i = 0; i < limit; ++i)
    if (i < r[i]) std::swap(A[i], A[r[i]]);
  for (int len = 1; len < limit; len <<= 1) {
    if (len == 262144)
      for (int i = 0; i < limit; ++i) A[i] %= mod;
    for (int i = 0; i < limit; i += len << 1) {
      unsigned long long *p = A + i, *q = A + i + len, *w = Omgs + len;
      for (int _ = 0; _ < len; ++_, ++p, ++q, ++w) {
        unsigned long long tmp = *q * *w % mod;
        *q = *p + mod - tmp, *p += tmp;
      }
    }
  }
  for (int i = 0; i < limit; ++i) A[i] %= mod;
}
void idft(unsigned long long *A, int limit) {
  std::reverse(A + 1, A + limit), dft(A, limit);
  unsigned long long inv = mod - (mod - 1) / limit;
  for (int i = 0; i < limit; ++i) A[i] = inv * A[i] % mod;
}
unsigned long long _f[N], _g[N], _tp[N];
std::vector<int> operator*(const std::vector<int> &a,
                           const std::vector<int> &b) {
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
  int limit = getlen(len);
  memset(_f, 0, limit << 3);
  for (unsigned int i = 0; i < a.size(); ++i) _f[i] = a[i];
  memset(_g, 0, limit << 3);
  for (unsigned int i = 0; i < b.size(); ++i) _g[i] = b[i];
  dft(_f, limit), dft(_g, limit);
  for (int i = 0; i < limit; ++i) _f[i] = 1ULL * _f[i] * _g[i] % mod;
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
  memset(_f, 0, limit << 3);
  for (unsigned int i = 0; i < a.size(); ++i) _f[i] = a[i];
  dft(_f, limit);
  if (need) {
    memset(_g, 0, limit << 3);
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
std::vector<int> Inv(const std::vector<int> &F) {
  if (F.size() == 1u) return {(int)ksm(F[0])};
  unsigned int len = F.size(), l = (len + 1) >> 1;
  std::vector<int> H(Inv({F.begin(), F.begin() + l})), tmp(mul(F, H, len)),
      ans(H);
  memset(tmp.data(), 0, l << 2), tmp = mul(tmp, H, len, false), ans.resize(len);
  for (unsigned int i = l; i < len; ++i) tmp[i] && (ans[i] = mod - tmp[i]);
  return ans;
}
int n, ans;
std::vector<int> solve(int m) {
  if (!m) {
    std::vector<int> f(n + 1);
    f[0] = 1;
    return f;
  }
  std::vector<int> tmp = solve(m / 2), A(n + 1), B(n + 1);
  for (int i = 0; i <= n; ++i) (i % 2 ? A : B)[i] = tmp[i];
  A[1] = (m + 1) / 2;
  std::vector<int> C = B * B, D = Inv(std::vector<int>{1} - A);
  C.resize(n + 1);
  C *= D, C.resize(n + 1);
  C += A;
  if (n % 2 == 0)
    add(ans, ans);
  else
    ans = 0;
  for (int i = 1; i <= n; i += 2)
    add(ans, 1LL * A[i] * D[n - i] % mod * i % mod);
  return C;
}
int main() {
  setup();
  int m;
  read(n, m);
  solve(m);
  printf("%d\n", ans);
  return 0;
}
