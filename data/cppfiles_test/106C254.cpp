#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using PLL = std::pair<ll, ll>;
template <class T>
using prique = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <class T>
class infinity {
 public:
  static constexpr T value = std::numeric_limits<T>::max() / 2;
  static constexpr T mvalue = std::numeric_limits<T>::min() / 2;
  static constexpr T max = std::numeric_limits<T>::max();
  static constexpr T min = std::numeric_limits<T>::min();
};
template <class T>
constexpr T infinity<T>::value;
template <class T>
constexpr T infinity<T>::mvalue;
template <class T>
constexpr T infinity<T>::max;
template <class T>
constexpr T infinity<T>::min;
constexpr ll inf = infinity<ll>::value;
constexpr ld EPS = 1e-8;
constexpr ld PI = 3.1415926535897932384626;
template <class T, class U>
std::ostream& operator<<(std::ostream& ost, const std::pair<T, U>& p) {
  return ost << p.first << ' ' << p.second;
}
template <class T, class U>
std::istream& operator>>(std::istream& ist, std::pair<T, U>& p) {
  return ist >> p.first >> p.second;
}
template <class Container, typename std::enable_if<!std::is_same<
                               Container, std::string>::value>::type* = nullptr>
auto operator<<(std::ostream& ost, const Container& cont)
    -> decltype(cont.begin(), cont.end(), ost) {
  for (auto itr = cont.begin(); itr != cont.end(); ++itr) {
    if (itr != cont.begin()) ost << ' ';
    ost << *itr;
  }
  return ost;
}
template <class Container, typename std::enable_if<!std::is_same<
                               Container, std::string>::value>::type* = nullptr>
auto operator>>(std::istream& ist, Container& cont)
    -> decltype(cont.begin(), cont.end(), ist) {
  for (auto itr = cont.begin(); itr != cont.end(); ++itr) ist >> *itr;
  return ist;
}
template <class T, class U>
inline constexpr bool chmin(T& a, const U& b) noexcept {
  return a > b ? a = b, true : false;
}
template <class T, class U>
inline constexpr bool chmax(T& a, const U& b) noexcept {
  return a < b ? a = b, true : false;
}
inline ll gcd(ll a, ll b) noexcept {
  while (b) {
    const ll c = a;
    a = b;
    b = c % b;
  }
  return a;
}
inline ll lcm(ll a, ll b) noexcept { return a / gcd(a, b) * b; }
inline bool is_prime(ll N) noexcept {
  if (N <= 1) return false;
  for (ll i = 2; i * i <= N; ++i) {
    if (N % i == 0) return false;
  }
  return true;
}
inline std::vector<ll> prime_factor(ll N) noexcept {
  std::vector<ll> res;
  for (ll i = 2; i * i <= N; ++i) {
    while (N % i == 0) {
      res.push_back(i);
      N /= i;
    }
  }
  if (N != 1) res.push_back(N);
  return res;
}
inline ll my_pow(ll a, ll b) noexcept {
  ll res = 1;
  while (b) {
    if (b & 1) res *= a;
    b >>= 1;
    a *= a;
  }
  return res;
}
inline ll mod_pow(ll a, ll b, ll mod) noexcept {
  a %= mod;
  ll res = 1;
  while (b) {
    if (b & 1) (res *= a) %= mod;
    b >>= 1;
    (a *= a) %= mod;
  }
  return res;
}
PLL extGCD(ll a, ll b) noexcept {
  if (b == 0) return PLL{1, 0};
  PLL p = extGCD(b, a % b);
  std::swap(p.first, p.second);
  p.second -= p.first * (a / b);
  if (p.first < 0) {
    p.first += b;
    p.second -= a;
  }
  return p;
}
ll mod_inv(ll a, ll mod) noexcept {
  const PLL p = extGCD(a, mod);
  assert(p.first * a + p.second * mod == 1);
  return p.first;
}
PLL ChineseRemainder(ll b1, ll m1, ll b2, ll m2) noexcept {
  const PLL p = extGCD(m1, m2);
  const ll g = p.first * m1 + p.second * m2;
  const ll l = m1 / g * m2;
  if ((b2 - b1) % g != 0) return PLL{-1, -1};
  const ll x = (b2 - b1) / g * p.first % (m2 / g);
  return {(x * m1 + b1 + l) % l, l};
}
PLL ChineseRemainders(const std::vector<ll>& b,
                      const std::vector<ll>& m) noexcept {
  PLL res{0, 1};
  for (ll i = 0; i < (ll)(b.size()); ++i) {
    res = ChineseRemainder(res.first, res.second, b[i], m[i]);
    if (res.first == -1) return res;
  }
  return res;
}
template <class F>
class RecLambda {
 private:
  F f;

 public:
  explicit constexpr RecLambda(F&& f_) : f(std::forward<F>(f_)) {}
  template <class... Args>
  constexpr auto operator()(Args&&... args) const
      -> decltype(f(*this, std::forward<Args>(args)...)) {
    return f(*this, std::forward<Args>(args)...);
  }
};
template <class F>
inline constexpr RecLambda<F> rec_lambda(F&& f) {
  return RecLambda<F>(std::forward<F>(f));
}
template <class T, class Arg>
constexpr std::vector<T> make_vec(int n, Arg&& arg) {
  return std::vector<T>(n, arg);
}
template <class T, class... Args>
constexpr auto make_vec(int n, Args&&... args)
    -> std::vector<decltype(make_vec<T>(args...))> {
  return std::vector<decltype(make_vec<T>(args...))>(
      n, make_vec<T>(std::forward<Args>(args)...));
}
inline int popcnt(ull x) {
  x = (x & 0x5555555555555555) + ((x >> 1) & 0x5555555555555555);
  x = (x & 0x3333333333333333) + ((x >> 2) & 0x3333333333333333);
  x = (x & 0x0f0f0f0f0f0f0f0f) + ((x >> 4) & 0x0f0f0f0f0f0f0f0f);
  x = (x & 0x00ff00ff00ff00ff) + ((x >> 8) & 0x00ff00ff00ff00ff);
  x = (x & 0x0000ffff0000ffff) + ((x >> 16) & 0x0000ffff0000ffff);
  return (x & 0x00000000ffffffff) + ((x >> 32) & 0x00000000ffffffff);
}
template <class T>
class presser : public std::vector<T> {
 private:
  using Base = std::vector<T>;

 public:
  using Base::Base;
  presser(const std::vector<T>& vec) : Base(vec) {}
  void push(const std::vector<T>& vec) {
    int n = this->size();
    this->resize(n + vec.size());
    std::copy((vec).begin(), (vec).end(), this->begin() + n);
  }
  int build() {
    std::sort(this->begin(), this->end());
    this->erase(std::unique(this->begin(), this->end()), this->end());
    return this->size();
  }
  int get_index(const T& val) const {
    return static_cast<int>(std::lower_bound(this->begin(), this->end(), val) -
                            this->begin());
  }
  std::vector<int> pressed(const std::vector<T>& vec) const {
    std::vector<int> res(vec.size());
    for (ll i = 0; i < (ll)(vec.size()); ++i) res[i] = this->get_index(vec[i]);
    return res;
  }
  void press(std::vector<T>& vec) const {
    static_assert(std::is_integral<T>::value, "cannot convert from int type");
    for (ll i = 0; i < (ll)(vec.size()); ++i) vec[i] = this->get_index(vec[i]);
  }
};
using namespace std;
int main() {
  int q;
  cin >> q;
  for (ll REP_COUNTER_0 = 0; REP_COUNTER_0 < (ll)(q); ++REP_COUNTER_0) {
    int n;
    cin >> n;
    for (ll i = 0; i < (ll)(n); ++i) cout << i + 2 << " \n"[i == n - 1];
  }
}
