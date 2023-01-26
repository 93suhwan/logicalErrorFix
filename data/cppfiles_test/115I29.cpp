#include <bits/stdc++.h>
using namespace std;

template <int mod = (int)(998244353)>
struct ModInt {
  int x;
  constexpr ModInt() : x(0) {}
  constexpr ModInt(int64_t y)
      : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
  constexpr ModInt &operator+=(const ModInt &p) noexcept {
    if ((x += p.x) >= mod) x -= mod;
    return *this;
  }
  constexpr ModInt &operator-=(const ModInt &p) noexcept {
    if ((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }
  constexpr ModInt &operator*=(const ModInt &p) noexcept {
    x = (int)(1LL * x * p.x % mod);
    return *this;
  }
  constexpr ModInt &operator/=(const ModInt &p) noexcept {
    *this *= p.inverse();
    return *this;
  }
  constexpr ModInt operator-() const { return ModInt(-x); }
  constexpr ModInt operator+(const ModInt &p) const noexcept {
    return ModInt(*this) += p;
  }
  constexpr ModInt operator-(const ModInt &p) const noexcept {
    return ModInt(*this) -= p;
  }
  constexpr ModInt operator*(const ModInt &p) const noexcept {
    return ModInt(*this) *= p;
  }
  constexpr ModInt operator/(const ModInt &p) const noexcept {
    return ModInt(*this) /= p;
  }
  constexpr bool operator==(const ModInt &p) const noexcept { return x == p.x; }
  constexpr bool operator!=(const ModInt &p) const noexcept { return x != p.x; }
  constexpr ModInt inverse() const noexcept {
    int a = x, b = mod, u = 1, v = 0, t = 0;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }
  constexpr ModInt pow(int64_t n) const {
    ModInt res(1), mul(x);
    while (n) {
      if (n & 1) res *= mul;
      mul *= mul;
      n >>= 1;
    }
    return res;
  }
  friend constexpr ostream &operator<<(ostream &os, const ModInt &p) noexcept {
    return os << p.x;
  }
  friend constexpr istream &operator>>(istream &is, ModInt &a) noexcept {
    int64_t t = 0;
    is >> t;
    a = ModInt<mod>(t);
    return (is);
  }
  constexpr int get_mod() { return mod; }
};
using mint = ModInt<>;

using P = pair<int, int>;

int n, m, q;
vector<vector<int>> all(2, vector<int>(2, 0));
vector<vector<vector<int>>> row, col;
set<int> rcnt, ccnt, rng, cng;
map<P, int> mp;

void clear(int x, int y);
void change(int x, int y, int sig);

int main() {
  cin >> n >> m >> q;
  row.assign(n, vector(2, vector<int>(2, 0)));
  col.assign(m, vector(2, vector<int>(2, 0)));
  while (q--) {
    int x, y, t;
    cin >> x >> y >> t;
    clear(--x, --y);
    if (t >= 0) change(x, y, t);
    mint res = 0;
    for (int b = 0; b < 2; ++b)
      if (!all[b][0] && !all[b ^ 1][1]) res -= 1;
    if (!rng.size()) res += mint(2).pow(n - rcnt.size());
    if (!cng.size()) res += mint(2).pow(m - ccnt.size());
    cout << res << endl;
  }
  return 0;
}

void clear(int x, int y) {
  if (!mp.count(P(x, y))) return;
  int sig = mp[P(x, y)];
  --all[(x ^ y) & 1][sig];
  --row[x][y & 1][sig];
  --col[y][x & 1][sig];
  if (!row[x][0][0] && !row[x][0][1] && !row[x][1][0] && !row[x][1][1])
    rcnt.erase(x);
  if (!col[y][0][0] && !col[y][0][1] && !col[y][1][0] && !col[y][1][1])
    ccnt.erase(y);
  {
    bool ch = 1;
    for (int b = 0; b < 2; ++b)
      if ((row[x][b][0] && row[x][b][1]) || (row[x][0][b] && row[x][1][b]))
        ch = 0;
    if (ch) rng.erase(x);
  }
  {
    bool ch = 1;
    for (int b = 0; b < 2; ++b)
      if ((col[y][b][0] && col[y][b][1]) || (col[y][0][b] && col[y][1][b]))
        ch = 0;
    if (ch) cng.erase(y);
  }
}
void change(int x, int y, int sig) {
  ++all[(x ^ y) & 1][sig];
  mp[P(x, y)] = sig;
  rcnt.insert(x);
  ccnt.insert(y);
  ++row[x][y & 1][sig];
  ++col[y][x & 1][sig];
  for (int b = 0; b < 2; ++b)
    if ((row[x][b][0] && row[x][b][1]) || (row[x][0][b] && row[x][1][b]))
      rng.insert(x);
  for (int b = 0; b < 2; ++b)
    if ((col[y][b][0] && col[y][b][1]) || (col[y][0][b] && col[y][1][b]))
      cng.insert(y);
}