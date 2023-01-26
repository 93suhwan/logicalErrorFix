#include <bits/stdc++.h>
using namespace std;
long long dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
long long dy[8] = {1, 0, -1, 0, -1, 1, 1, -1};
class pa3 {
 public:
  long long x;
  long long y, z;
  pa3(long long x = 0, long long y = 0, long long z = 0) : x(x), y(y), z(z) {}
  bool operator<(const pa3& p) const {
    if (x != p.x) return x < p.x;
    if (y != p.y) return y < p.y;
    return z < p.z;
  }
  bool operator>(const pa3& p) const {
    if (x != p.x) return x > p.x;
    if (y != p.y) return y > p.y;
    return z > p.z;
  }
  bool operator==(const pa3& p) const {
    return x == p.x && y == p.y && z == p.z;
  }
  bool operator!=(const pa3& p) const {
    return !(x == p.x && y == p.y && z == p.z);
  }
};
class pa4 {
 public:
  long long x;
  long long y, z, w;
  pa4(long long x = 0, long long y = 0, long long z = 0, long long w = 0)
      : x(x), y(y), z(z), w(w) {}
  bool operator<(const pa4& p) const {
    if (x != p.x) return x < p.x;
    if (y != p.y) return y < p.y;
    if (z != p.z) return z < p.z;
    return w < p.w;
  }
  bool operator>(const pa4& p) const {
    if (x != p.x) return x > p.x;
    if (y != p.y) return y > p.y;
    if (z != p.z) return z > p.z;
    return w > p.w;
  }
  bool operator==(const pa4& p) const {
    return x == p.x && y == p.y && z == p.z && w == p.w;
  }
};
class pa2 {
 public:
  long long x, y;
  pa2(long long x = 0, long long y = 0) : x(x), y(y) {}
  pa2 operator+(pa2 p) { return pa2(x + p.x, y + p.y); }
  pa2 operator-(pa2 p) { return pa2(x - p.x, y - p.y); }
  bool operator<(const pa2& p) const { return y != p.y ? y < p.y : x < p.x; }
  bool operator>(const pa2& p) const { return x != p.x ? x < p.x : y < p.y; }
  bool operator==(const pa2& p) const {
    return abs(x - p.x) == 0 && abs(y - p.y) == 0;
  }
  bool operator!=(const pa2& p) const {
    return !(abs(x - p.x) == 0 && abs(y - p.y) == 0);
  }
};
string itos(long long i) {
  ostringstream s;
  s << i;
  return s.str();
}
long long Gcd(long long v, long long b) {
  if (v == 0) return b;
  if (b == 0) return v;
  if (v > b) return Gcd(b, v);
  if (v == b) return b;
  if (b % v == 0) return v;
  return Gcd(v, b % v);
}
long long extgcd(long long a, long long b, long long& x, long long& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long d = extgcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}
pair<long long, long long> operator+(const pair<long long, long long>& l,
                                     const pair<long long, long long>& r) {
  return {l.first + r.first, l.second + r.second};
}
pair<long long, long long> operator-(const pair<long long, long long>& l,
                                     const pair<long long, long long>& r) {
  return {l.first - r.first, l.second - r.second};
}
ostream& operator<<(ostream& os, const vector<long long>& VEC) {
  for (auto v : VEC) os << v << " ";
  return os;
}
ostream& operator<<(ostream& os, const pair<long long, long long>& PAI) {
  os << PAI.first << " : " << PAI.second;
  return os;
}
ostream& operator<<(ostream& os, const pa3& PAI) {
  os << PAI.x << " : " << PAI.y << " : " << PAI.z;
  return os;
}
ostream& operator<<(ostream& os, const pa4& PAI) {
  os << PAI.x << " : " << PAI.y << " : " << PAI.z << " : " << PAI.w;
  return os;
}
ostream& operator<<(ostream& os,
                    const vector<pair<long long, long long> >& VEC) {
  for (auto v : VEC) os << v << " ";
  return os;
}
ostream& operator<<(ostream& os, const vector<pa3>& VEC) {
  for (auto v : VEC) {
    os << v << " ";
    os << endl;
  }
  return os;
}
long long beki(long long wa, long long rr, long long warukazu) {
  if (rr == 0) return 1 % warukazu;
  if (rr == 1) return wa % warukazu;
  wa %= warukazu;
  if (rr % 2 == 1)
    return ((long long)beki(wa, rr - 1, warukazu) * (long long)wa) % warukazu;
  long long zx = beki(wa, rr / 2, warukazu);
  return (zx * zx) % warukazu;
}
long long pr[2521000];
long long inv[2521000];
const long long mod = 998244353;
long long comb(long long nn, long long rr) {
  if (nn == -1 && rr == -1) return 1;
  if (rr < 0 || rr > nn || nn < 0) return 0;
  long long r = pr[nn] * inv[rr];
  r %= mod;
  r *= inv[nn - rr];
  r %= mod;
  return r;
}
void gya(long long ert) {
  pr[0] = 1;
  for (long long i = 1; i <= ert; i++) {
    pr[i] = ((long long)pr[i - 1] * i) % mod;
  }
  inv[ert] = beki(pr[ert], mod - 2, mod);
  for (long long i = ert - 1; i >= 0; i--) {
    inv[i] = (long long)inv[i + 1] * (i + 1) % mod;
  }
}
long long beki(long long a, long long b) {
  long long ANS = 1;
  long long be = a % mod;
  while (b) {
    if (b & 1) {
      ANS *= be;
      ANS %= mod;
    }
    be *= be;
    be %= mod;
    b /= 2;
  }
  return ANS;
}
struct unionfind {
 private:
 public:
  vector<long long> par, ranks, kosuu;
  void shoki(long long N) {
    par.resize(N + 1, 0);
    ranks.resize(N + 1, 0);
    kosuu.resize(N + 1, 1);
    for (long long i = 0; i <= N; i++) {
      par[i] = i;
    }
  }
  long long root(long long x) {
    return par[x] == x ? x : par[x] = root(par[x]);
  }
  bool same(long long x, long long y) { return root(x) == root(y); }
  bool is_root(long long x) { return x == root(x); }
  void unite(long long x, long long y) {
    x = root(x);
    y = root(y);
    long long xx = kosuu[x], yy = kosuu[y];
    if (x == y) return;
    if (ranks[x] < ranks[y]) {
      par[x] = y;
      kosuu[y] = yy + xx;
    } else {
      par[y] = x;
      if (ranks[x] == ranks[y]) ranks[x] = ranks[x] + 1;
      kosuu[x] = yy + xx;
    }
    return;
  }
};
vector<long long> G[200020 * 32];
long long f(long long r) {
  long long t = 1;
  while (r > t) {
    t *= 2;
  }
  return t - r;
}
long long dis[200020 * 32];
void dfs(long long r, long long p, long long d) {
  dis[r] = d;
  for (auto v : G[r])
    if (v != p) dfs(v, r, d + 1);
}
void solve() {
  long long n;
  cin >> n;
  map<long long, long long> ma;
  ma[0] = 0;
  vector<long long> ve(n + 1);
  for (long long i = 1; i <= n; i++) {
    cin >> ve[i];
    ma[ve[i]] = i;
  }
  long long tu = n + 1;
  for (long long i = 1; i <= n; i++) {
    long long y = ve[i];
    while (y) {
      if (!ma.count(y)) {
        ma[y] = tu;
        tu++;
      }
      y = f(y);
    }
  }
  for (auto i : ma) {
    if (i.first) {
      long long p = i.second;
      long long e = f(i.first);
      long long q = ma[e];
      G[p].push_back(q);
      G[q].push_back(p);
    }
  }
  dfs(0, 0, 0);
  long long r = -1, d = -1;
  for (long long i = 0; i < tu; i++) {
    if (dis[i] > d) {
      d = dis[i];
      r = i;
    }
  }
  assert(r <= n);
  dfs(r, r, 0);
  long long r2 = -1;
  d = -1;
  for (long long i = 0; i < tu; i++) {
    if (dis[i] > d) {
      d = dis[i];
      r2 = i;
    }
  }
  cout << r << " " << r2 << " " << d << endl;
}
signed main() {
  long long n = 1;
  for (long long i = 0; i < n; i++) solve();
  return 0;
}
