#include <bits/stdc++.h>
using namespace std;
using namespace std;
const double eps = 1e-6;
const int int_inf = 2 * 1e9;
const long long ll_inf = 8 * 1e18;
const long double PI = acosl(-1.0);
template <typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<long long, int>;
using pll = pair<long long, long long>;
istream& operator>>(istream& in, pii& i) {
  in >> i.first >> i.second;
  return in;
}
template <class T>
istream& operator>>(istream& in, vector<T>& a) {
  for (auto& i : a) {
    in >> i;
  }
  return in;
}
template <class T>
ostream& operator<<(ostream& out, vector<T>& a) {
  for (auto i : a) {
    out << i << " ";
  }
  out << '\n';
  return out;
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long myRand(long long B) { return (unsigned long long)rng() % B; }
long long powmod(long long a, long long b, long long p) {
  a %= p;
  if (a == 0) return 0;
  long long product = 1;
  while (b > 0) {
    if (b & 1) {
      product *= a;
      product %= p;
      --b;
    }
    a *= a;
    a %= p;
    b /= 2;
  }
  return product;
}
long long factor[35];
long long inv(long long a, long long p) { return powmod(a, p - 2, p); }
long long nCk(long long n, long long k, long long p) {
  return ((factor[n] * inv(factor[k], p) % p) * inv(factor[n - k], p)) % p;
}
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
  assert(m == 1);
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
constexpr int md = 1e9 + 7;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;
vector<Mint> fact(1, 1);
vector<Mint> inv_fact(1, 1);
Mint C(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  while ((int)fact.size() < n + 1) {
    fact.push_back(fact.back() * (int)fact.size());
    inv_fact.push_back(1 / fact.back());
  }
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}
const long long MOD = 1e9 + 7;
void solve() {
  int n, m, rb, cb, rd, cd, p;
  cin >> n >> m >> rb >> cb >> rd >> cd >> p;
  int cur_b = 1, cur_c = 1;
  int time = 0;
  int start_r = rb, start_c = cb;
  vector<vector<int>> cnt(n + 1, vector<int>(m + 1, 0));
  vector<int> q;
  int glob_time = 0;
  int start_bb = 1;
  int start_cc = 1;
  if (rb + cur_b > n || rb + cur_b <= 0) {
    start_bb *= -1;
  }
  if (cb + cur_c > m || cb + cur_c <= 0) {
    start_cc *= -1;
  }
  while (true) {
    if (rb + cur_b > n || rb + cur_b <= 0) {
      cur_b *= -1;
    }
    if (cb + cur_c > m || cb + cur_c <= 0) {
      cur_c *= -1;
    }
    if (time > 0)
      if (rb == start_r && cb == start_c && cur_b == start_bb &&
          cur_c == start_cc) {
        glob_time = time;
        break;
      }
    if (rb == rd || cb == cd) {
      q.push_back(time);
    }
    ++time;
    rb += cur_b;
    cb += cur_c;
  }
  Mint a = 0;
  Mint real_p = Mint(p) / Mint(100);
  Mint real_1_p = Mint(100 - p) / Mint(100);
  Mint cur_p = real_p;
  Mint cur_1_p = 1;
  for (int i = 0; i < q.size(); ++i) {
    a = (a + (q[i] * cur_1_p * real_p));
    cur_1_p = (cur_1_p * real_1_p);
  }
  Mint zn = 1 - cur_1_p;
  cout << (((((a + (Mint(time) * cur_1_p))) / zn))) << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
