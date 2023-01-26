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
const int N = 50005, mod = 1000000007, inv2 = (mod + 1) / 2;
template <typename _Tp1, typename _Tp2>
inline void add(_Tp1 &a, _Tp2 b) {
  a = a + b > mod ? a + b - mod : a + b;
}
template <typename _Tp1, typename _Tp2>
inline void sub(_Tp1 &a, _Tp2 b) {
  a = a - b < 0 ? a - b + mod : a - b;
}
long long ksm(long long a, long long b = mod - 2) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod, b >>= 1;
  }
  return res;
}
struct num {
  int a, b;
  inline num operator+=(const num &o) {
    add(a, o.a), add(b, o.b);
    return *this;
  }
  inline num operator+(const num &o) const {
    num x(*this);
    return x += o;
  }
  inline num operator-=(const num &o) {
    sub(a, o.a), sub(b, o.b);
    return *this;
  }
  inline num operator-(const num &o) const {
    num x(*this);
    return x -= o;
  }
  inline num operator*(const num &o) const {
    return {(int)((1LL * a * o.a + 5LL * b * o.b) % mod),
            (int)((1LL * b * o.a + 1LL * a * o.b) % mod)};
  }
  inline num operator*(const int &o) const {
    return {(int)(1LL * o * a % mod), (int)(1LL * o * b % mod)};
  }
  inline num inv() const {
    long long tmp = ksm(1LL * a * a + 1LL * (mod - 5) * b % mod * b) % mod;
    return (num){a, mod - b} * tmp;
  }
  inline num operator/(const num &o) const { return *this * (o.inv()); }
};
long long a[2][N];
num b[2][N], c[2][N];
int n, q, O[N], K[N], L[N], R[N], X[N];
num ans1[N], ans2[N];
num ksm(num a, int b) {
  num res = {1, 0};
  while (b) {
    if (b & 1) res = res * a;
    a = a * a, b >>= 1;
  }
  return res;
}
void solve(const num &w1, const num &w2) {
  for (int i = 0; i < 2; ++i)
    for (int j = 1; j <= n; ++j)
      b[i][j] = ksm(w1, a[i][j]), c[i][j] = ksm(w2, a[i][j]);
  for (int t = 1; t <= q; ++t) {
    int l = L[t], r = R[t];
    if (O[t] == 4) {
      for (int i = l; i <= r; ++i) ans1[t] += b[0][i] * b[1][i];
      for (int i = l; i <= r; ++i) ans2[t] += c[0][i] * c[1][i];
    } else {
      int k = K[t], x = X[t];
      num t1 = x >= 0 ? ksm(w1, x) : ksm(w1.inv(), -x),
          t2 = x >= 0 ? ksm(w2, x) : ksm(w2.inv(), -x);
      if (O[t] == 1) {
        for (int i = l; i <= r; ++i)
          if (a[k][i] > x) a[k][i] = x, b[k][i] = t1, c[k][i] = t2;
      } else if (O[t] == 2) {
        for (int i = l; i <= r; ++i)
          if (a[k][i] < x) a[k][i] = x, b[k][i] = t1, c[k][i] = t2;
      } else if (O[t] == 3) {
        for (int i = l; i <= r; ++i)
          a[k][i] += x, b[k][i] = b[k][i] * t1, c[k][i] = c[k][i] * t2;
      }
    }
  }
}
int main() {
  read(n, q);
  for (int i = 0; i < 2; ++i)
    for (int j = 1; j <= n; ++j) read(a[i][j]);
  for (int i = 1; i <= q; ++i) {
    read(O[i]);
    if (O[i] == 4)
      read(L[i], R[i]);
    else
      read(K[i], L[i], R[i], X[i]), --K[i];
  }
  solve({inv2, inv2}, {inv2, mod - inv2});
  for (int i = 1; i <= q; ++i)
    if (O[i] == 4) {
      num tmp = ans1[i] - ans2[i];
      printf("%d\n", tmp.b);
    }
  return 0;
}
