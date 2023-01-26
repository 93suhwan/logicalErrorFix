#include <bits/stdc++.h>
using namespace std;
clock_t time_p = clock();
void time_taken() {
  time_p = clock() - time_p;
  cerr << "Time Taken : " << (float)(time_p) / CLOCKS_PER_SEC << "\n";
}
const long long mod = 1e9 + 7;
const long long INF = 1e18;
long long modinv(long long a, long long m) {
  assert(m > 0);
  if (m == 1) return 0;
  a %= m;
  if (a < 0) a += m;
  assert(a != 0);
  if (a == 1) return 1;
  return m - modinv(m, a) * m / a;
}
template <int MOD_>
struct modnum {
 private:
  int v;

 public:
  static const int MOD = MOD_;
  modnum() : v(0) {}
  modnum(long long v_) : v(int(v_ % MOD)) {
    if (v < 0) v += MOD;
  }
  explicit operator int() const { return v; }
  friend bool operator==(const modnum &a, const modnum &b) {
    return a.v == b.v;
  }
  friend bool operator!=(const modnum &a, const modnum &b) {
    return a.v != b.v;
  }
  modnum operator~() const {
    modnum res;
    res.v = modinv(v, MOD);
    return res;
  }
  modnum &operator+=(const modnum &o) {
    v += o.v;
    if (v >= MOD) v -= MOD;
    return *this;
  }
  modnum &operator-=(const modnum &o) {
    v -= o.v;
    if (v < 0) v += MOD;
    return *this;
  }
  modnum &operator*=(const modnum &o) {
    v = int(long long(v) * long long(o.v) % MOD);
    return *this;
  }
  modnum &operator/=(const modnum &o) { return *this *= (~o); }
  friend modnum operator+(const modnum &a, const modnum &b) {
    return modnum(a) += b;
  }
  friend modnum operator-(const modnum &a, const modnum &b) {
    return modnum(a) -= b;
  }
  friend modnum operator*(const modnum &a, const modnum &b) {
    return modnum(a) *= b;
  }
  friend modnum operator/(const modnum &a, const modnum &b) {
    return modnum(a) /= b;
  }
};
using num = modnum<mod>;
vector<num> fact;
vector<num> ifact;
void init() {
  fact = {1};
  for (int i = 1; i < 300005; i++) fact.push_back(i * fact[i - 1]);
  for (num x : fact) ifact.push_back(1 / x);
}
num ncr(int n, int k) {
  if (k < 0 || k > n) return 0;
  return fact[n] * ifact[k] * ifact[n - k];
}
num powmod(num x, int a) {
  if (a == 0) return 1;
  if (a & 1) return x * powmod(x, a - 1);
  return powmod(x * x, a / 2);
}
void solve() {
  int n, m;
  cin >> n >> m;
  auto f = [&](int x1, int x2, int mx, int dx) -> pair<int, int> {
    if (dx > 0) {
      if (x1 <= x2) {
        return make_pair(x2 - x1, dx);
      }
      return make_pair(2 * mx - (x1 + x2), -dx);
    } else {
      if (x2 <= x1) {
        return make_pair(x1 - x2, dx);
      }
      return make_pair(x1 + x2 - 2, -dx);
    }
    return make_pair(0, 0);
  };
  auto get2 = [&](long long y, long long dir, long long mx,
                  long long dis) -> pair<int, int> {
    if (dir < 0) {
      if (y - dis >= 1) return {y - dis, dir};
      dis -= (y - 1);
      return {1 + dis, -dir};
    } else {
      if (y + dis <= mx) {
        return {y + dis, dir};
      }
      dis -= (mx - y);
      return {mx - dis, -dir};
    }
  };
  auto get = [&](int x1, int y1, int x2, int y2, int dx,
                 int dy) -> vector<int> {
    int ans = mod;
    int nx = x2, ny = y2;
    int ndx, ndy;
    {
      auto foo = f(x1, x2, n, dx);
      if (ans > foo.first) {
        ans = foo.first;
        nx = x2;
        ndx = foo.second;
        auto bar = get2(y1, dy, m, ans);
        ny = bar.first;
        ndy = bar.second;
      }
      foo = f(y1, y2, m, dy);
      if (ans > foo.first) {
        ans = foo.first;
        ny = y2;
        ndy = foo.second;
        auto bar = get2(x1, dx, n, ans);
        nx = bar.first;
        ndx = bar.second;
      }
    }
    return vector<int>{ans, nx, ny, ndx, ndy};
  };
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int _p;
  cin >> _p;
  num p = num(_p) / 100;
  auto foo = get(x1, y1, x2, y2, 1, 1);
  bool fl = 0;
  if (x1 != x2 and y1 != y2) {
    fl = 1;
  }
  num ans = foo[0];
  x1 = foo[1];
  y1 = foo[2];
  int dx = foo[3];
  int dy = foo[4];
  if (fl) {
    if (x1 == 1 or x1 == n) dx *= -1;
    if (y1 == 1 or y1 == m) dy *= -1;
  }
  set<vector<int> > vis;
  map<vector<int>, int> pos;
  vector<int> cyc;
  while (!vis.count({x1, y1, dx, dy})) {
    vis.insert({x1, y1, dx, dy});
    auto nxt = get(x1 + dx, y1 + dy, x2, y2, dx, dy);
    cyc.push_back(nxt[0] + 1);
    pos[{x1, y1, dx, dy}] = (int)(cyc).size() - 1;
    x1 = nxt[1];
    y1 = nxt[2];
    dx = nxt[3];
    dy = nxt[4];
    if (x1 == 1 or x1 == n) dx *= -1;
    if (y1 == 1 or y1 == m) dy *= -1;
  }
  num mul = (1 - p);
  int till = pos[{x1, y1, dx, dy}];
  for (int i = 0; i < till; i++) {
    ans += mul * cyc[i];
    mul *= (1 - p);
  }
  int cycSz = (int)(cyc).size() - till;
  mul *= num(1) / (1 - powmod(1 - p, cycSz));
  for (int i = till; i <= (int)(cyc).size() - 1; i++) {
    ans += mul * cyc[i];
    mul *= (1 - p);
  }
  cout << int(ans) << '\n';
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  time_taken();
  return 0;
}
