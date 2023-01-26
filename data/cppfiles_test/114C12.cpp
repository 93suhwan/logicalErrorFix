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
const ll INFL = 1e18 + 10;
const int INF = 1e9 + 10;
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
const int nax = 1e8;
using T = AR<int, 10>;
using U = PR<int, T>;
void solve() {
  int n;
  cin >> n;
  V<vi> v(n);
  vi k;
  set<T> b;
  for (auto& a : v) {
    int c;
    cin >> c;
    k.push_back(c);
    for (int _ = (0); _ < (c); ++_) {
      int x;
      cin >> x;
      a.push_back(x);
    }
  }
  int m;
  cin >> m;
  for (int _ = (0); _ < (m); ++_) {
    T t;
    for (int i = (0); i < (n); ++i) {
      cin >> t[i];
      t[i]--;
    }
    for (int i = (n); i < (10); ++i) t[i] = -1;
    b.insert(t);
  }
  set<U> second;
  T r;
  int val = 0;
  for (int i = (0); i < (n); ++i) r[i] = k[i] - 1, val += v[i].back();
  for (int i = (n); i < (10); ++i) r[i] = -1;
  second.insert(make_pair(val, r));
  for (int _ = (0); _ < (nax); ++_) {
    if (!int((second).size())) {
      assert(false);
    }
    U u = *second.rbegin();
    second.erase(second.find(u));
    0;
    if (b.find(u.second) == b.end()) {
      for (int i = (0); i < (n); ++i) cout << u.second[i] + 1 << " ";
      cout << '\n';
      return;
    }
    for (int i = (0); i < (n); ++i) {
      if (u.second[i] == 0) continue;
      u.first -= v[i][u.second[i]];
      u.first += v[i][u.second[i] - 1];
      u.second[i]--;
      0;
      second.insert(u);
      u.second[i]++;
      u.first += v[i][u.second[i]];
      u.first -= v[i][u.second[i] - 1];
    }
  }
  assert(false);
}
int main() {
  setIO();
  int TT = 1;
  for (int _ = (0); _ < (TT); ++_) solve();
  exit(0);
}
