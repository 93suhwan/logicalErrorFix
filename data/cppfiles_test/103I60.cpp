#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using db = double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<str>;
using vc = vector<char>;
using vpi = vector<pi>;
using vpl = vector<pl>;
template <class T>
using V = vector<T>;
template <class T, size_t SZ>
using AR = array<T, SZ>;
template <class T, class U>
using PR = pair<T, U>;
template <class T, class U>
using umap = unordered_map<T, U>;
template <class T>
using uset = unordered_set<T>;
template <class T>
using mset = multiset<T>;
const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INFL = ll(3e18) + 10;
const int INF = int(1e9) + 10;
const ld PI = acos((ld)-1);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T>
using pql = priority_queue<T, vector<T>, less<T>>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x); }
constexpr int p2(int x) { return 1 << x; }
constexpr int msk2(int x) { return p2(x) - 1; }
ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }
ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
template <class T, class U>
T fstTrue(T lo, T hi, U first) {
  hi++;
  assert(lo <= hi);
  while (lo < hi) {
    T mid = lo + (hi - lo) / 2;
    first(mid) ? hi = mid : lo = mid + 1;
  }
  return lo;
}
template <class T, class U>
T lstTrue(T lo, T hi, U first) {
  lo--;
  assert(lo <= hi);
  while (lo < hi) {
    T mid = lo + (hi - lo + 1) / 2;
    first(mid) ? lo = mid : hi = mid - 1;
  }
  return lo;
}
template <class T>
void remDup(vector<T>& v) {
  sort(begin(v), end(v));
  v.erase(unique(begin(v), end(v)), end(v));
}
template <class T, class U>
void erase(T& t, const U& u) {
  auto it = t.find(u);
  assert(it != end(t));
  t.erase(it);
}
str to_string(char c) { return str(1, c); }
str to_string(const char* second) { return (str)second; }
str to_string(str second) { return second; }
str to_string(bool b) { return to_string((int)b); }
template <class T, class U>
str to_string(pair<T, U> p) {
  return to_string(p.first) + " " + to_string(p.second);
}
template <class T, class U>
str to_string(V<pair<T, U>> v) {
  bool fst = 1;
  str res = "";
  for (const auto& x : v) {
    if (!fst) res += " ";
    fst = 0;
    res += to_string(x);
  }
  return res;
}
template <class T>
str to_string(T v) {
  bool fst = 1;
  str res = "";
  for (const auto& x : v) {
    if (!fst) res += " ";
    fst = 0;
    res += to_string(x);
  }
  return res;
}
void DBG() { cerr << "]" << endl; }
template <class T, class... U>
void DBG(const T& t, const U&... u) {
  cerr << to_string(t);
  if (sizeof...(u)) cerr << ", ";
  DBG(u...);
}
void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }
void setPrec() { cout << fixed << setprecision(15); }
void setIn(str second) { freopen(second.c_str(), "r", stdin); }
void setOut(str second) { freopen(second.c_str(), "w", stdout); }
void setIO(str second = "") {
  unsyncIO();
  setPrec();
  if (int((second).size())) setIn(second + ".in"), setOut(second + ".out");
}
const int nax = 2005;
str D[nax];
int vis[nax][nax], len[nax][nax];
map<char, pi> dir;
pi operator+(pi a, pi b) {
  return make_pair(a.first + b.first, a.second + b.second);
}
void reset(int N, int M) {
  for (int i = (0); i < (N); ++i)
    for (int j = (0); j < (M); ++j) vis[i][j] = 0, len[i][j] = -INF;
}
void solve() {
  int N, M;
  cin >> N >> M;
  reset(N, M);
  for (int i = (0); i < (N); ++i) cin >> D[i];
  queue<pi> q;
  for (int i = (0); i < (N); ++i)
    for (int j = (0); j < (M); ++j) {
      if (vis[i][j]) continue;
      pi u = make_pair(i, j);
      pi nu = u + dir[D[i][j]];
      if (nu.second >= M || nu.first >= N || nu.first < 0 || nu.second < 0) {
        len[i][j] = 1;
        q.push(make_pair(i, j));
      } else {
        vpi cyc;
        pi v = u;
        while (!vis[v.first][v.second]) {
          vis[v.first][v.second] = 1;
          cyc.push_back(v);
          v = v + dir[D[v.first][v.second]];
          if (v.second >= M || v.first >= N || v.first < 0 || v.second < 0)
            break;
        }
        if (v == cyc.front()) {
          for (auto& u : cyc) {
            len[u.first][u.second] = int((cyc).size());
            q.push(u);
          }
        }
        for (auto& u : cyc) vis[u.first][u.second] = 0;
      }
    }
  while (!q.empty()) {
    pi u = q.front();
    q.pop();
    if (vis[u.first][u.second]) continue;
    vis[u.first][u.second] = 1;
    for (int i = (0); i < (4); ++i) {
      pi nu = u + make_pair(dx[i], dy[i]);
      if (nu.second >= M || nu.first >= N || nu.first < 0 || nu.second < 0)
        continue;
      if (len[nu.first][nu.second] != -INF) continue;
      if (dir[D[nu.first][nu.second]] == make_pair(-dx[i], -dy[i])) {
        len[nu.first][nu.second] = len[u.first][u.second] + 1;
        q.push(nu);
      }
    }
  }
  pi u = make_pair(-1, -1);
  int best = -1;
  for (int i = (0); i < (N); ++i)
    for (int j = (0); j < (M); ++j) {
      if (ckmax(best, len[i][j])) u = make_pair(j + 1, i + 1);
    }
  assert(best != -1);
  cout << to_string(u) << " " << best << '\n';
}
int main() {
  setIO();
  dir['R'] = make_pair(0, 1);
  dir['L'] = make_pair(0, -1);
  dir['U'] = make_pair(-1, 0);
  dir['D'] = make_pair(1, 0);
  int TT = 1;
  cin >> TT;
  for (int _ = (0); _ < (TT); ++_) solve();
  exit(0);
}
