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
struct segsum {
 private:
 public:
  long long cor = (1 << 20);
  vector<long long> vec;
  void shoki1() { vec.resize(2 * cor + 3, 0); }
  void shoki2() {
    for (long long i = cor - 1; i > 0; i--)
      vec[i] = vec[2 * i] + vec[2 * i + 1];
  }
  void clear() {
    for (long long i = 0; i < (long long)vec.size(); i++) vec[i] = 0;
  }
  void updadd(long long x, long long w) {
    x += cor;
    vec[x] += w;
    x /= 2;
    while (x) {
      vec[x] = vec[2 * x] + vec[2 * x + 1];
      x /= 2;
    }
  }
  void updchan(long long x, long long w) {
    x += cor;
    vec[x] = w;
    while (x) {
      x /= 2;
      vec[x] = vec[2 * x] + vec[2 * x + 1];
    }
  }
  long long sum(long long a, long long b) {
    long long hi = 0, mi = 0;
    a += cor, b += cor;
    while (a < b) {
      if (a & 1) {
        hi = hi + vec[a];
        a++;
      }
      if (b & 1) {
        b--;
        mi = vec[b] + mi;
      }
      a /= 2, b /= 2;
    }
    return hi + mi;
  }
  long long lower_bound(long long p, long long x) {
    p += cor;
    long long ima = 0;
    while (1) {
      while (!(p & 1)) p /= 2;
      if (ima + vec[p] >= x) break;
      ima = ima + vec[p];
      p++;
      if (p == (p & (-p))) return cor;
    }
    while (1) {
      if (p >= cor) return p - cor;
      p *= 2;
      if (ima + vec[p] < x) {
        ima += vec[p];
        p++;
      }
    }
  }
  long long upper_bound(long long p, long long x) {
    p += cor;
    long long ima = 0;
    while (1) {
      while (!(p & 1)) p /= 2;
      if (ima + vec[p] > x) break;
      ima = ima + vec[p];
      p++;
      if (p == (p & (-p))) return cor;
    }
    while (1) {
      if (p >= cor) return p - cor;
      p *= 2;
      if (ima + vec[p] <= x) {
        ima += vec[p];
        p++;
      }
    }
  }
};
segsum ss;
vector<long long> G[1000020];
vector<long long> ve[1000020];
long long hin[1000020];
long long iti[1000020];
vector<pa3> que[1000020];
long long a[1000020];
long long ans[1000002];
void ato(long long n) {
  for (long long i = 0; i <= n; i++) {
    G[i].clear();
    ve[i].clear();
    ss.updchan(i, 0);
  }
}
void tasu(long long r, long long d = 1) {
  long long h = hin[r];
  long long k = ve[h].size();
  long long s = ve[h].back();
  if (r != s) {
    swap(ve[h][iti[r]], ve[h][k - 1]);
    swap(iti[r], iti[s]);
  }
  ve[h].pop_back();
  ve[h + d].push_back(r);
  hin[r] = h + d;
  iti[r] = (long long)ve[h + d].size() - 1;
  ss.updadd(h, -1);
  ss.updadd(h + d, 1);
}
void dfs(long long r) {
  while (que[r].size()) {
    pa3 z = que[r].back();
    que[r].pop_back();
    long long l = z.x;
    long long k = z.y;
    long long e = ss.lower_bound(l, k);
    if (e == ss.cor) {
      ans[z.z] = -1;
    } else {
      ans[z.z] = ve[e][0];
    }
  }
  for (auto v : G[r]) {
    tasu(a[v]);
    dfs(v);
    tasu(a[v], -1);
  }
}
void solve() {
  long long n;
  cin >> n;
  long long q;
  cin >> q;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 2; i <= n; i++) {
    long long y;
    cin >> y;
    G[y].push_back(i);
  }
  for (long long i = 0; i < q; i++) {
    long long y, yy, yyy;
    cin >> y >> yy >> yyy;
    que[y].push_back(pa3(yy, yyy, i));
  }
  for (long long i = 1; i <= n; i++) {
    ve[0].push_back(i);
    hin[i] = 0;
    iti[i] = i - 1;
  }
  tasu(a[1]);
  dfs(1);
  for (long long i = 0; i < q; i++) cout << ans[i] << " ";
  cout << endl;
  ato(n);
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ss.shoki1();
  ss.shoki2();
  long long n = 1;
  cin >> n;
  for (long long i = 0; i < n; i++) solve();
  return 0;
}
