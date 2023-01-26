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
void solve() {
  long long n, m, q;
  cin >> n >> m >> q;
  vector<pair<long long, long long> > ve;
  long long ima = 0;
  for (long long i = 0; i < n; i++) {
    long long y;
    cin >> y;
    ima += y;
    ve.push_back(make_pair(y, 1));
  }
  for (long long i = 0; i < m; i++) {
    long long y;
    cin >> y;
    ve.push_back(make_pair(y, 0));
  }
  sort(ve.begin(), ve.end());
  vector<long long> rui(n + m);
  rui[0] = ve[0].first;
  for (long long i = 1; i < n + m; i++) rui[i] = rui[i - 1] + ve[i].first;
  set<pa3> kukan;
  for (long long i = 0; i < n + m; i++) {
    kukan.insert(pa3(i, i + 1, ve[i].second));
  }
  set<pair<long long, long long> > se;
  for (long long i = 1; i < n + m; i++) {
    se.insert((pair<long long, long long>)make_pair(
        ve[i].first - ve[i - 1].first, i));
  }
  vector<pair<long long, long long> > qu(q);
  for (long long i = 0; i < q; i++) {
    cin >> qu[i].first;
    qu[i].second = i;
  }
  sort(qu.begin(), qu.end());
  pair<long long, long long> tt = make_pair(1000000007 * 100000000ll, -1);
  se.insert(tt);
  vector<long long> ans(q);
  for (long long i = 0; i < q; i++) {
    while ((*se.begin()).first <= qu[i].first) {
      pair<long long, long long> r = *se.begin();
      se.erase(r);
      auto it = kukan.lower_bound(pa3(r.second, -1, -1));
      auto it2 = it;
      it2--;
      pa3 x = *it;
      pa3 y = *it2;
      if ((*it).y > (*it).z)
        ima -= rui[(*it).y - 1] - rui[(*it).y - (*it).z - 1];
      else
        ima -= rui[(*it).y - 1];
      if ((*it2).y > (*it2).z)
        ima -= rui[(*it2).y - 1] - rui[(*it2).y - (*it2).z - 1];
      else
        ima -= rui[(*it2).y - 1];
      kukan.erase(it);
      kukan.erase(it2);
      pa3 z = {y.x, x.y, y.z + x.z};
      if (z.y > z.z)
        ima += rui[z.y - 1] - rui[z.y - z.z - 1];
      else
        ima += rui[z.y - 1];
      kukan.insert(z);
    }
    ans[qu[i].second] = ima;
  }
  cout << ans << endl;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long n = 1;
  for (long long i = 0; i < n; i++) solve();
  return 0;
}
