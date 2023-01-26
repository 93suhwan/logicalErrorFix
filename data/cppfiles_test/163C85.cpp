#include <bits/stdc++.h>
using namespace std;
namespace algo {
template <int modulo>
class ModInt {
 public:
  ModInt() : val_(0) {}
  ModInt(int v) {
    val_ = v % modulo;
    if (val_ < 0) val_ += modulo;
  }
  ModInt(long long v) {
    val_ = v % modulo;
    if (val_ < 0) val_ += modulo;
  }
  static int Modulus() { return modulo; }
  inline int val() const { return val_; }
  inline operator bool() const { return val_ != 0; }
  ModInt& operator++() {
    ++val_;
    if (val_ == modulo) val_ = 0;
    return *this;
  }
  ModInt& operator--() {
    if (val_ == 0) val_ = modulo;
    --val_;
    return *this;
  }
  ModInt operator++(int) {
    auto ret = *this;
    ++*this;
    return ret;
  }
  ModInt operator--(int) {
    auto ret = *this;
    --*this;
    return ret;
  }
  ModInt& operator+=(const ModInt& o) {
    val_ += o.val_;
    if (val_ >= modulo) val_ -= modulo;
    return *this;
  }
  ModInt& operator-=(const ModInt& o) {
    val_ -= o.val_;
    if (val_ < 0) val_ += modulo;
    return *this;
  }
  ModInt& operator*=(const ModInt& o) {
    val_ = (1ll * val_ * o.val_) % modulo;
    return *this;
  }
  ModInt& operator/=(const ModInt& o) { return *this *= o.Inv(); }
  ModInt Pow(long long n) const {
    ModInt a = *this;
    ModInt res(1);
    while (n > 0) {
      if (n & 1) res *= a;
      a *= a;
      n >>= 1;
    }
    return res;
  }
  ModInt Inv() const { return Pow(modulo - 2); }
  friend ModInt operator+(const ModInt& lhs, const ModInt& rhs) {
    return ModInt(lhs) += rhs;
  }
  friend ModInt operator-(const ModInt& lhs, const ModInt& rhs) {
    return ModInt(lhs) -= rhs;
  }
  friend ModInt operator*(const ModInt& lhs, const ModInt& rhs) {
    return ModInt(lhs) *= rhs;
  }
  friend ModInt operator/(const ModInt& lhs, const ModInt& rhs) {
    return ModInt(lhs) /= rhs;
  }
  friend bool operator==(const ModInt& lhs, const ModInt& rhs) {
    return lhs.val_ == rhs.val_;
  }
  friend bool operator!=(const ModInt& lhs, const ModInt& rhs) {
    return lhs.val_ != rhs.val_;
  }

 private:
  int val_;
};
}  // namespace algo
namespace algo {
using std::to_string;
template <typename A, typename B>
std::string to_string(std::pair<A, B> p);
template <typename A, typename B, typename C>
std::string to_string(std::tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
std::string to_string(std::tuple<A, B, C, D> p);
inline std::string to_string(const std::string& s) { return '"' + s + '"'; }
inline std::string to_string(const char* s) {
  return to_string((std::string)s);
}
inline std::string to_string(bool b) { return (b ? "true" : "false"); }
template <size_t N>
std::string to_string(const std::bitset<N>& v) {
  std::string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
template <typename Container>
std::string to_string(const Container& v) {
  bool first = true;
  std::string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
std::string to_string(std::pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
std::string to_string(std::tuple<A, B, C> p) {
  return "(" + to_string(std::get<0>(p)) + ", " + to_string(std::get<1>(p)) +
         ", " + to_string(std::get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
std::string to_string(std::tuple<A, B, C, D> p) {
  return "(" + to_string(std::get<0>(p)) + ", " + to_string(std::get<1>(p)) +
         ", " + to_string(std::get<2>(p)) + ", " + to_string(std::get<3>(p)) +
         ")";
}
inline void DebugOut() { std::cerr << std::endl; }
template <typename Head, typename... Tail>
void DebugOut(Head head, Tail... tail) {
  std::cerr << " " << to_string(head);
  DebugOut(tail...);
}
}  // namespace algo
using mint = algo::ModInt<(int)1e9 + 7>;
bool inside(int x, int n) { return 0 <= x && x < n; }
void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  int sx, sy;
  scanf("%d%d", &sx, &sy);
  --sx;
  --sy;
  int tx, ty;
  scanf("%d%d", &tx, &ty);
  --tx;
  --ty;
  int p;
  scanf("%d", &p);
  mint prob = mint(p) / mint(100);
  using T = tuple<int, int, int, int>;
  int x = sx, y = sy;
  int dx = 1, dy = 1;
  map<T, int> id;
  int idn = 0;
  map<T, T> next;
  T inters;
  while (true) {
    int ndx = dx;
    int ndy = dy;
    if (!inside(x + ndx, n)) ndx *= -1;
    if (!inside(y + ndy, m)) ndy *= -1;
    int nx = x + ndx;
    int ny = y + ndy;
    assert(inside(nx, n));
    assert(inside(ny, m));
    T state = {x, y, dx, dy};
    next[state] = {nx, ny, ndx, ndy};
    if (id.count(state) > 0) {
      inters = state;
      break;
    }
    id[state] = idn++;
    x = nx;
    y = ny;
    dx = ndx;
    dy = ndy;
  }
  auto get_coefs = [&](T s) {
    int x = get<0>(s);
    int y = get<1>(s);
    if (x == tx || y == ty) {
      return make_pair(mint(1), mint(1) - prob);
    } else {
      return make_pair(mint(1), mint(1));
    }
  };
  T state = inters;
  pair<mint, mint> coefs = get_coefs(state);
  state = next[state];
  while (state != inters) {
    auto ncoefs = get_coefs(state);
    coefs = {coefs.first + coefs.second * ncoefs.first,
             coefs.second * ncoefs.second};
    state = next[state];
  }
  state = {sx, sy, 1, 1};
  auto coefs1 = get_coefs(state);
  state = next[state];
  while (state != inters) {
    auto ncoefs = get_coefs(state);
    coefs1 = {coefs1.first + coefs1.second * ncoefs.first,
              coefs1.second * ncoefs.second};
    state = next[state];
  }
  mint val = coefs.first / (mint(1) - coefs.second);
  mint ans = (coefs1.first + val * coefs1.second);
  ans -= mint(1);
  cout << ans.val() << endl;
}
int main() {
  int tests = 1;
  scanf("%d", &tests);
  for (int t = 0; t < tests; ++t) {
    solve();
  }
  return 0;
}
