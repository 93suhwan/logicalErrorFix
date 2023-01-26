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
const long long mod = 1000000007;
long long comb(long long nn, long long rr) {
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
long long beki2(long long wa, long long rr) {
  if (rr == 0) return 1;
  if (rr == 1) return wa;
  if (rr % 2 == 1) return ((long long)beki2(wa, rr - 1) * (long long)wa) % mod;
  long long zx = beki2(wa, rr / 2);
  return (zx * zx) % mod;
}
long long beki3(long long a, long long b) {
  long long ANS = 1;
  long long be = a;
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
vector<long long> G[20002];
long long d[200][200] = {};
void dfs(long long r, long long p, long long di, long long it) {
  d[it][di]++;
  for (auto v : G[r])
    if (v != p) dfs(v, r, di + 1, it);
}
long long dp[200][200] = {};
long long solve(vector<long long> ve, long long k) {
  long long n = ve.size();
  for (long long i = 0; i <= n; i++)
    for (long long j = 0; j <= n; j++) dp[i][j] = 0;
  dp[0][0] = 1;
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j <= i; j++) {
      dp[i + 1][j] += dp[i][j];
      dp[i + 1][j] %= mod;
      dp[i + 1][j + 1] += dp[i][j] * ve[i] % mod;
      dp[i + 1][j + 1] %= mod;
    }
  return dp[n][k];
}
long long solve(long long r, long long k) {
  if ((long long)G[r].size() < k) return 0;
  long long it = 0;
  for (auto v : G[r]) {
    dfs(v, r, 0, it);
    it++;
  }
  long long e = G[r].size();
  long long ans = 0;
  for (long long kk = 0; kk < 110; kk++) {
    long long ko = 0;
    vector<long long> ve;
    for (long long j = 0; j < e; j++) {
      if (d[j][kk]) ko++, ve.push_back(d[j][kk]);
    }
    if (ko < k) break;
    ans += solve(ve, k);
  }
  for (long long i = 0; i <= 110; i++)
    for (long long j = 0; j < e; j++) d[j][i] = 0;
  return ans % mod;
}
long long ke(long long n) {
  for (long long i = 0; i < n; i++) G[i].clear();
  return 0;
}
void solve() {
  long long n, k;
  cin >> n >> k;
  for (long long i = 0; i < n - 1; i++) {
    long long y, yy;
    cin >> y >> yy;
    y--, yy--;
    G[y].push_back(yy);
    G[yy].push_back(y);
  }
  if (k == 2) {
    cout << n * (n - 1) / 2 % mod << endl;
    ke(n);
    return;
  }
  long long ans = 0;
  for (long long i = 0; i < n; i++) ans += solve(i, k);
  ke(n);
  cout << ans % mod << endl;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long n = 1;
  cin >> n;
  for (long long i = 0; i < n; i++) solve();
  return 0;
}
