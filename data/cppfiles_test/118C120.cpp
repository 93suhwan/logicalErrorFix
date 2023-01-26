#include <bits/stdc++.h>
using namespace std;
int __FAST_IO__ = []() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  return 0;
}();
template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a;
    swap(a, m);
    u -= t * v;
    swap(u, v);
  }
  return u;
}
template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;
  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
    value = normalize(x);
  }
  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod())
      v = static_cast<Type>(x);
    else
      v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }
  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const {
    return static_cast<U>(value);
  }
  constexpr static Type mod() { return T::value; }
  Modular& operator+=(const Modular& other) {
    if ((value += other.value) >= mod()) value -= mod();
    return *this;
  }
  Modular& operator-=(const Modular& other) {
    if ((value -= other.value) < 0) value += mod();
    return *this;
  }
  template <typename U>
  Modular& operator+=(const U& other) {
    return *this += Modular(other);
  }
  template <typename U>
  Modular& operator-=(const U& other) {
    return *this -= Modular(other);
  }
  Modular& operator++() { return *this += 1; }
  Modular& operator--() { return *this -= 1; }
  Modular operator++(int) {
    Modular result(*this);
    *this += 1;
    return result;
  }
  Modular operator--(int) {
    Modular result(*this);
    *this -= 1;
    return result;
  }
  Modular operator-() const { return Modular(-value); }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value,
                     Modular>::type&
  operator*=(const Modular& rhs) {
    value = normalize(static_cast<int64_t>(value) *
                      static_cast<int64_t>(rhs.value));
    return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, long long>::value,
                     Modular>::type&
  operator*=(const Modular& rhs) {
    long long q = static_cast<long long>(static_cast<long double>(value) *
                                         rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value,
                     Modular>::type&
  operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }
  Modular& operator/=(const Modular& other) {
    return *this *= Modular(inverse(other.value, mod()));
  }
  friend const Type& abs(const Modular& x) { return x.value; }
  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);
  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);
  template <typename V, typename U>
  friend V& operator>>(V& stream, Modular<U>& number);

 private:
  Type value;
};
template <typename T>
bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) {
  return lhs.value == rhs.value;
}
template <typename T, typename U>
bool operator==(const Modular<T>& lhs, U rhs) {
  return lhs == Modular<T>(rhs);
}
template <typename T, typename U>
bool operator==(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) == rhs;
}
template <typename T>
bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) {
  return !(lhs == rhs);
}
template <typename T, typename U>
bool operator!=(const Modular<T>& lhs, U rhs) {
  return !(lhs == rhs);
}
template <typename T, typename U>
bool operator!=(U lhs, const Modular<T>& rhs) {
  return !(lhs == rhs);
}
template <typename T>
bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) {
  return lhs.value < rhs.value;
}
template <typename T>
Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) += rhs;
}
template <typename T, typename U>
Modular<T> operator+(const Modular<T>& lhs, U rhs) {
  return Modular<T>(lhs) += rhs;
}
template <typename T, typename U>
Modular<T> operator+(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) += rhs;
}
template <typename T>
Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U>
Modular<T> operator-(const Modular<T>& lhs, U rhs) {
  return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U>
Modular<T> operator-(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) -= rhs;
}
template <typename T>
Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U>
Modular<T> operator*(const Modular<T>& lhs, U rhs) {
  return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U>
Modular<T> operator*(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) *= rhs;
}
template <typename T>
Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> operator/(const Modular<T>& lhs, U rhs) {
  return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> operator/(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}
template <typename T>
bool IsZero(const Modular<T>& number) {
  return number() == 0;
}
template <typename T>
string to_string(const Modular<T>& number) {
  return to_string(number());
}
template <typename U, typename T>
U& operator<<(U& stream, const Modular<T>& number) {
  return stream << number();
}
template <typename U, typename T>
U& operator>>(U& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, long long>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}
constexpr int md = 998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;
vector<vector<Mint>> fastmulti(vector<vector<Mint>>& a,
                               vector<vector<Mint>>& b) {
  vector<vector<Mint>> ans(a.size(), vector<Mint>(b[0].size(), Mint(0)));
  for (int i = 0; i < (a.size()); ++i) {
    for (int j = 0; j < (a[0].size()); ++j) {
      for (int k = 0; k < (b[0].size()); ++k) {
        ans[i][k] += a[i][j] * b[j][k];
      }
    }
  }
  return ans;
}
vector<Mint> fac, ifac;
Mint C(int m, int n) { return fac[m] * ifac[n] * ifac[m - n]; }
void initFac(int n) {
  fac.resize(n + 1);
  ifac.resize(n + 1);
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fac[i] = fac[i - 1] * i;
  }
  ifac[n] = 1 / fac[n];
  for (int i = n - 1; i >= 0; --i) {
    ifac[i] = ifac[i + 1] * (i + 1);
  }
}
template <typename Mint>
struct NumberTheoreticTransformFriendlyModInt {
  vector<Mint> dw, idw;
  int max_base;
  Mint root;
  NumberTheoreticTransformFriendlyModInt() {
    const unsigned mod = Mint::mod();
    assert(mod >= 3 && mod % 2 == 1);
    auto tmp = mod - 1;
    max_base = 0;
    while (tmp % 2 == 0) tmp >>= 1, max_base++;
    root = 2;
    while (power(root, (mod - 1) >> 1) == 1) root += 1;
    assert(power(root, mod - 1) == 1);
    dw.resize(max_base);
    idw.resize(max_base);
    for (int i = 0; i < max_base; i++) {
      dw[i] = -power(root, (mod - 1) >> (i + 2));
      idw[i] = Mint(1) / dw[i];
    }
  }
  void ntt(vector<Mint>& a) {
    const int n = (int)a.size();
    assert((n & (n - 1)) == 0);
    assert(__builtin_ctz(n) <= max_base);
    for (int m = n; m >>= 1;) {
      Mint w = 1;
      for (int s = 0, k = 0; s < n; s += 2 * m) {
        for (int i = s, j = s + m; i < s + m; ++i, ++j) {
          auto x = a[i], y = a[j] * w;
          a[i] = x + y, a[j] = x - y;
        }
        w *= dw[__builtin_ctz(++k)];
      }
    }
  }
  void intt(vector<Mint>& a, bool f = true) {
    const int n = (int)a.size();
    assert((n & (n - 1)) == 0);
    assert(__builtin_ctz(n) <= max_base);
    for (int m = 1; m < n; m *= 2) {
      Mint w = 1;
      for (int s = 0, k = 0; s < n; s += 2 * m) {
        for (int i = s, j = s + m; i < s + m; ++i, ++j) {
          auto x = a[i], y = a[j];
          a[i] = x + y, a[j] = (x - y) * w;
        }
        w *= idw[__builtin_ctz(++k)];
      }
    }
    if (f) {
      Mint inv_sz = Mint(1) / n;
      for (int i = 0; i < n; i++) a[i] *= inv_sz;
    }
  }
  vector<Mint> multiply(vector<Mint> a, vector<Mint> b) {
    int need = a.size() + b.size() - 1;
    int nbase = 1;
    while ((1 << nbase) < need) nbase++;
    int sz = 1 << nbase;
    a.resize(sz, 0);
    b.resize(sz, 0);
    ntt(a);
    ntt(b);
    Mint inv_sz = Mint(1) / sz;
    for (int i = 0; i < sz; i++) a[i] *= b[i] * inv_sz;
    intt(a, false);
    a.resize(need);
    return a;
  }
};
int main() {
  int N;
  cin >> N;
  initFac(N);
  vector<int> d(N, -1);
  NumberTheoreticTransformFriendlyModInt<Mint> fft;
  d[0] = 0;
  for (int i = 0; i < (N - 1); ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    d[u]++;
    d[v]++;
  }
  function<vector<Mint>(int, int)> solve = [&](int l, int r) {
    if (l == r) return vector<Mint>({1, d[l]});
    int mid = (l + r) >> 1;
    auto fl = solve(l, mid), fr = solve(mid + 1, r);
    auto ft = fft.multiply(fl, fr);
    return ft;
  };
  auto dp = solve(0, N - 1);
  Mint ans = 0;
  for (int i = 0, s = 1; i < N; ++i, s = -s) {
    ans += dp[i] * s * fac[N - i];
  }
  printf("%d\n", ans);
  return 0;
}
