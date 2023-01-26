#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V>& x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T& x) {
  int first = 0;
  cerr << '{';
  for (auto& i : x) cerr << (first++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
template <int MOD_>
struct modnum {
  static constexpr int MOD = MOD_;
  static_assert(MOD_ > 0, "MOD must be positive");
  int v;
  modnum() : v(0) {}
  modnum(long long v_) : v(int(v_ % MOD)) {
    if (v < 0) v += MOD;
  }
  explicit operator int() const { return v; }
  explicit operator bool() const { return v; }
  friend ostream& operator<<(ostream& out, const modnum& n) {
    return out << int(n);
  }
  friend istream& operator>>(istream& in, modnum& n) {
    long long v_;
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
  friend bool operator!(const modnum& a) { return a.v == 0; }
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
    v = int((long long)v * o.v % MOD);
    return *this;
  }
  friend modnum binpow(modnum a, long long p) {
    if (p == 0) return 1;
    modnum ret = 1;
    for (; p; p /= 2, a *= a)
      if (p & 1) ret *= a;
    return ret;
  }
  modnum inv() const { return binpow(*this, MOD - 2); }
  friend modnum inv(const modnum& m) { return m.inv(); }
  modnum& operator/=(const modnum& o) { return *this *= o.inv(); }
  modnum neg() const {
    modnum res;
    res.v = v ? MOD - v : 0;
    return res;
  }
  friend modnum neg(const modnum& m) { return m.neg(); }
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
const int mod = 1e9 + 7;
using mint = modnum<mod>;
void __print(mint x) { cerr << x; }
vector<mint> facs, invfacs;
mint choose(const mint& a, const mint& b) {
  int _a = (int)a, _b = (int)b;
  if (_b > _a || _a < 0 || _b < 0) return 0;
  return facs[_a] * invfacs[_b] * invfacs[_a - _b];
}
void minit(const int nx) {
  facs.resize(nx + 1);
  invfacs.resize(nx + 1);
  facs[0] = facs[1] = invfacs[0] = invfacs[1] = 1;
  for (int i = 2; i <= nx; i++) {
    facs[i] = facs[i - 1] * i;
  }
  invfacs[nx] = inv(facs[nx]);
  for (int i = nx - 1; i > 1; i--) {
    invfacs[i] = invfacs[i + 1] * (i + 1);
  }
}
void test_case() {
  int a, b, startx, starty, endx, endy, p;
  cin >> a >> b >> startx >> starty >> endx >> endy >> p;
  mint win = mint(p) / 100, lose = 1 - win;
  vector<vector<vector<bool>>> vis(
      a + 1, vector<vector<bool>>(b + 1, vector<bool>(4)));
  int sx = -1, sy = -1, sz = -1, dx = 1, dy = 1;
  vector<array<int, 3>> blocks;
  while (1) {
    if (startx + dx <= 0 || startx + dx > a) dx *= -1;
    if (starty + dy <= 0 || starty + dy > b) dy *= -1;
    int conv = (dx == 1 ? 0 : 1) + (dy == 1 ? 0 : 2);
    if (vis[startx][starty][conv]) {
      sx = startx, sy = starty, sz = conv;
      break;
    }
    vis[startx][starty][conv] = 1;
    blocks.push_back({startx, starty, conv});
    startx += dx, starty += dy;
  }
  int pos = find(blocks.begin(), blocks.end(), array<int, 3>{sx, sy, sz}) -
            blocks.begin();
  vector<array<int, 3>> path, cycle;
  for (int i = 0; i < pos; i++) {
    path.push_back(blocks[i]);
  }
  for (int i = pos; i < (int)(blocks).size(); i++) {
    cycle.push_back(blocks[i]);
  }
  mint probhere = 1, time = 0, ans = 0;
  for (const auto& [x, y, dir] : path) {
    if (x == endx || y == endy) {
      ans += probhere * time;
      probhere *= lose;
    }
    time += win;
  }
  int len = 0;
  for (const auto& [x, y, dir] : cycle) len += (x == endx || y == endy);
  const mint rc2 = binpow(lose, len);
  for (const auto& [x, y, dir] : cycle) {
    if (x == endx || y == endy) {
      ans += (probhere *
              (-time * rc2 + mint((int)(cycle).size()) * win * rc2 + time)) /
             (binpow(rc2 - 1, 2));
      probhere *= lose;
    }
    time += win;
  }
  cout << ans << '\n';
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t;
  while (t--) test_case();
}
