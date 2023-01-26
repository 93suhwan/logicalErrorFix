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
const int MAXN = 300010;
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
int n, m, k, cnt[MAXN];
mint<MODBASE> dp[MAXN];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cin >> n >> m >> k;
  vector<vi> A(n);
  vi bad(k);
  for (int i = (0); i <= (n - 1); i++) {
    int c;
    cin >> c;
    A[i].resize(c);
    for (int j = (0); j <= (c - 1); j++) {
      cin >> A[i][j];
      A[i][j]--;
    }
  }
  for (int i = (0); i <= (n - 1); i++) {
    if (set<int>(A[i].begin(), A[i].end()).size() != A[i].size()) {
      for (auto& x : A[i]) {
        bad[x] = 1;
      }
    }
  }
  vector<vi> nex(k), pre(k);
  for (int i = (0); i <= (n - 1); i++) {
    for (int j = (0); j <= (int((A[i]).size()) - 2); j++) {
      nex[A[i][j]].push_back(A[i][j + 1]);
      pre[A[i][j + 1]].push_back(A[i][j]);
    }
  }
  for (int i = (0); i <= (k - 1); i++) {
    remDup(nex[i]);
    remDup(pre[i]);
  }
  vi used(k, 0);
  for (int i = (0); i <= (k - 1); i++) {
    if (used[i]) continue;
    queue<int> q;
    vi comp;
    q.push(i);
    used[i] = 1;
    while (int((q).size())) {
      int u = q.front();
      q.pop();
      comp.push_back(u);
      for (auto& v : nex[u])
        if (!used[v]) {
          used[v] = 1;
          q.push(v);
        }
      for (auto& v : pre[u])
        if (!used[v]) {
          used[v] = 1;
          q.push(v);
        }
    }
    bool isBad = false;
    int cntBegin = 0;
    for (auto& x : comp) {
      if (int((pre[x]).size()) == 0) cntBegin++;
      if (int((pre[x]).size()) > 1 || int((nex[x]).size()) > 1 || bad[x])
        isBad = true;
    }
    isBad |= (cntBegin == 0);
    if (isBad) continue;
    cnt[int((comp).size())]++;
  }
  vi non0;
  for (int i = (1); i <= (k); i++)
    if (cnt[i]) non0.push_back(i);
  dp[0] = 1;
  for (int i = (1); i <= (m); i++) {
    for (auto& x : non0) {
      if (x <= i) dp[i] += dp[i - x] * cnt[x];
    }
  }
  cout << int(dp[m]);
  return 0;
}
