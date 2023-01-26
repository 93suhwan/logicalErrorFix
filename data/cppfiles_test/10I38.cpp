#include <bits/stdc++.h>
using namespace std;
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
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
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
template <int MOD_>
struct modnum {
  static constexpr int MOD = MOD_;
  static_assert(MOD_ > 0, "MOD must be positive");

 private:
  using ll = long long;
  int v;
  static int minv(int a, int m) {
    a %= m;
    assert(a);
    return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
  }

 public:
  modnum() : v(0) {}
  modnum(ll v_) : v(int(v_ % MOD)) {
    if (v < 0) v += MOD;
  }
  explicit operator int() const { return v; }
  friend std::ostream& operator<<(std::ostream& out, const modnum& n) {
    return out << int(n);
  }
  friend std::istream& operator>>(std::istream& in, modnum& n) {
    ll v_;
    in >> v_;
    n = modnum(v_);
    return in;
  }
  friend bool operator==(const modnum& a, const modnum& b) {
    return a.v == b.v;
  }
  friend bool operator!=(const modnum& a, const modnum& b) {
    return a.v != b.v;
  }
  modnum inv() const {
    modnum res;
    res.v = minv(v, MOD);
    return res;
  }
  friend modnum inv(const modnum& m) { return m.inv(); }
  modnum neg() const {
    modnum res;
    res.v = v ? MOD - v : 0;
    return res;
  }
  friend modnum neg(const modnum& m) { return m.neg(); }
  modnum operator-() const { return neg(); }
  modnum operator+() const { return modnum(*this); }
  modnum& operator++() {
    v++;
    if (v == MOD) v = 0;
    return *this;
  }
  modnum& operator--() {
    if (v == 0) v = MOD;
    v--;
    return *this;
  }
  modnum& operator+=(const modnum& o) {
    v -= MOD - o.v;
    v = (v < 0) ? v + MOD : v;
    return *this;
  }
  modnum& operator-=(const modnum& o) {
    v -= o.v;
    v = (v < 0) ? v + MOD : v;
    return *this;
  }
  modnum& operator*=(const modnum& o) {
    v = int(ll(v) * ll(o.v) % MOD);
    return *this;
  }
  modnum& operator/=(const modnum& o) { return *this *= o.inv(); }
  friend modnum operator++(modnum& a, int) {
    modnum r = a;
    ++a;
    return r;
  }
  friend modnum operator--(modnum& a, int) {
    modnum r = a;
    --a;
    return r;
  }
  friend modnum operator+(const modnum& a, const modnum& b) {
    return modnum(a) += b;
  }
  friend modnum operator-(const modnum& a, const modnum& b) {
    return modnum(a) -= b;
  }
  friend modnum operator*(const modnum& a, const modnum& b) {
    return modnum(a) *= b;
  }
  friend modnum operator/(const modnum& a, const modnum& b) {
    return modnum(a) /= b;
  }
};
using num = modnum<1000000007>;
const int mod = 1e9 + 7;
num power(num a, int64_t b) {
  if (b == 0) return 1;
  num res = power(a, b / 2);
  if (b & 1) return res * res * a;
  return res * res;
}
bool checkinter(pair<int, int> x, pair<int, int> y) {
  if (x.first > y.first) swap(x, y);
  return x.first <= y.first && y.first <= x.second;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);
  int N, M, K, R, C, Ax, Bx, Ay, By;
  cin >> N >> M >> K >> R >> C >> Ax >> Ay >> Bx >> By;
  if (!checkinter(make_pair(Ax, Ax + R - 1), make_pair(Bx, Bx + R - 1)) or
      !checkinter(make_pair(By, By + C - 1), make_pair(Ay, Ay + C - 1))) {
    num res = 0;
    res = power(K, 1ll * N * M - 2ll * R * C);
    res *= power(K, 1ll * R * C);
    cout << res;
    return 0;
  }
  if (Ax > Bx) swap(Ax, Bx), swap(Ay, By);
  if (By < Ay) {
    int diff = abs(By + C - 1 - Ay);
    By = Ay - diff + 1;
  }
  int64_t sharearea = 1ll * ((Ay + C - 1) - By + 1) * ((Ax + R - 1) - Bx + 1);
  int64_t area = 2ll * R * C - sharearea;
  int64_t remainarea = 1ll * N * M - area;
  num res = power(K, remainarea);
  res *= power(K, 1ll * R * C - sharearea);
  cout << res;
}
