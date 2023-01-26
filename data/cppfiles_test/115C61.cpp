#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<ld, ld>;
using cd = complex<ld>;
using vcd = vector<cd>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<ld>;
using vs = vector<string>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
template <class T>
using min_pq = priority_queue<T, vector<T>, greater<T> >;
template <class T>
inline int ckmin(T& a, const T& val) {
  return val < a ? a = val, 1 : 0;
}
template <class T>
inline int ckmax(T& a, const T& val) {
  return a < val ? a = val, 1 : 0;
}
template <class T>
void remDup(vector<T>& v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), end(v));
}
constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x); }
constexpr int p2(int x) { return 1 << x; }
constexpr int msk2(int x) { return p2(x) - 1; }
ll ceilDiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }
ll floorDiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }
void setPrec(int x) { cout << fixed << setprecision(x); }
string to_string(char c) { return string(1, c); }
string to_string(const char* s) { return (string)s; }
string to_string(string s) { return s; }
string to_string(bool b) { return to_string((int)b); }
template <class T>
string to_string(complex<T> c) {
  stringstream ss;
  ss << c;
  return ss.str();
}
template <class T>
using V = vector<T>;
string to_string(V<bool> v) {
  string res = "{";
  for (int i = (0); i <= (int((v).size()) - 1); i++) res += char('0' + v[i]);
  res += "}";
  return res;
}
template <size_t sz>
string to_string(bitset<sz> b) {
  string res = "";
  for (int i = (0); i <= (int((b).size()) - 1); i++) res += char('0' + b[i]);
  return res;
}
template <class T, class U>
string to_string(pair<T, U> p);
template <class T>
string to_string(T v) {
  bool fst = 1;
  string res = "";
  for (const auto& x : v) {
    if (!fst) res += " ";
    fst = 0;
    res += to_string(x);
  }
  return res;
}
template <class T, class U>
string to_string(pair<T, U> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <class T>
void pr(T x) {
  cout << to_string(x);
}
template <class T, class... U>
void pr(const T& t, const U&... u) {
  pr(t);
  pr(u...);
}
void ps() { pr("\n"); }
template <class T, class... U>
void ps(const T& t, const U&... u) {
  pr(t);
  if (sizeof...(u)) pr(" ");
  ps(u...);
}
void DBG() { cerr << "]" << endl; }
template <class T, class... U>
void DBG(const T& t, const U&... u) {
  cerr << to_string(t);
  if (sizeof...(u)) cerr << ", ";
  DBG(u...);
}
const ld PI = acos(-1.0);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ld EPS = 1e-9;
const ll MODBASE = 998244353;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000010;
const int MAXM = 1000;
const int MAXK = 16;
const int MAXQ = 200010;
template <int MOD>
struct mint {
  static const int mod = MOD;
  int v;
  explicit operator int() const { return v; }
  mint() { v = 0; }
  mint(ll _v) {
    v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
    if (v < 0) v += MOD;
  }
  friend bool operator==(const mint& a, const mint& b) { return a.v == b.v; }
  friend bool operator!=(const mint& a, const mint& b) { return !(a == b); }
  friend bool operator<(const mint& a, const mint& b) { return a.v < b.v; }
  friend string to_string(mint a) { return to_string(a.v); }
  mint& operator+=(const mint& m) {
    if ((v += m.v) >= MOD) v -= MOD;
    return *this;
  }
  mint& operator-=(const mint& m) {
    if ((v -= m.v) < 0) v += MOD;
    return *this;
  }
  mint& operator*=(const mint& m) {
    v = int((ll)v * m.v % MOD);
    return *this;
  }
  mint& operator/=(const mint& m) { return (*this) *= inv(m); }
  friend mint pow(mint a, ll p) {
    mint ans = 1;
    assert(p >= 0);
    for (; p; p /= 2, a *= a)
      if (p & 1) ans *= a;
    return ans;
  }
  friend mint inv(const mint& a) {
    assert(a.v != 0);
    return pow(a, MOD - 2);
  }
  mint operator-() const { return mint(-v); }
  mint& operator++() { return *this += 1; }
  mint& operator--() { return *this -= 1; }
  friend mint operator+(mint a, const mint& b) { return a += b; }
  friend mint operator-(mint a, const mint& b) { return a -= b; }
  friend mint operator*(mint a, const mint& b) { return a *= b; }
  friend mint operator/(mint a, const mint& b) { return a /= b; }
};
int n, m, k, cntx[2];
map<pi, int> c;
set<int> badR, badC, uR, uC;
int cntR[MAXN][2], cntC[MAXN][2];
mint<MODBASE> mu[MAXN];
void update2(int pos, int col, int add, int cnt[MAXN][2], set<int>& bad,
             set<int>& u) {
  cnt[pos][col] += add;
  if (cnt[pos][0] && cnt[pos][1]) {
    bad.insert(pos);
  } else {
    bad.erase(pos);
  }
  if (cnt[pos][0] > 0 || cnt[pos][1] > 0) {
    u.insert(pos);
  } else {
    u.erase(pos);
  }
}
void update(int x, int y, int t) {
  int mark = (x & 1) ^ (y & 1);
  if (c.count({x, y})) {
    int nMark = mark ^ c[{x, y}];
    cntx[nMark]--;
    update2(x, nMark, -1, cntR, badR, uR);
    update2(y, nMark, -1, cntC, badC, uC);
    c.erase({x, y});
  }
  if (t == -1) return;
  int nMark = mark ^ t;
  cntx[nMark]++;
  update2(x, nMark, 1, cntR, badR, uR);
  update2(y, nMark, 1, cntC, badC, uC);
  c[{x, y}] = t;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  mu[0] = 1;
  for (int i = (1); i <= (1000000); i++) mu[i] = mu[i - 1] * 2;
  cin >> n >> m >> k;
  for (int i = (1); i <= (k); i++) {
    int x, y, t;
    cin >> x >> y >> t;
    x--;
    y--;
    update(x, y, t);
    mint<MODBASE> res = 0;
    if (int((badR).size()) && int((badC).size())) {
      res = 0;
    } else if (int((badR).size())) {
      res = mu[m - int((uC).size())];
    } else if (int((badC).size())) {
      res = mu[n - int((uR).size())];
    } else {
      if (int((uR).size()) == 0 && int((uC).size()) == 0) {
        res = mu[n] + mu[m] - 2;
      } else {
        res += mu[m - int((uC).size())];
        res += mu[n - int((uR).size())];
        if (cntx[0] == 0 || cntx[1] == 0) {
          res -= 1;
        }
      }
    }
    cout << int(res) << "\n";
  }
  return 0;
}
