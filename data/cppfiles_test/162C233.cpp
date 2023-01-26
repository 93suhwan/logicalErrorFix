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
const ll MODBASE = 1000000007LL;
const int INF = 0x3f3f3f3f;
const int MAXN = 200010;
const int MAXM = 1000;
const int MAXK = 16;
const int MAXQ = 200010;
int n;
ll a[MAXN], B[MAXN];
bool check(ll lowest) {
  for (int i = (1); i <= (n); i++) B[i] = 0;
  for (int i = (n); i >= (3); i--) {
    if (a[i] + B[i] < lowest) {
      return false;
    }
    ll remain = 0;
    if (B[i] >= lowest)
      remain = a[i];
    else {
      remain = a[i] + B[i] - lowest;
    }
    ll p = remain / 3 * 3;
    B[i - 2] += p / 3 * 2;
    B[i - 1] += p / 3;
  }
  return B[1] + a[1] >= lowest && B[2] + a[2] >= lowest;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int te;
  cin >> te;
  while (te--) {
    cin >> n;
    for (int i = (1); i <= (n); i++) cin >> a[i];
    ll dau = 1, cuoi = 2e9;
    while (dau <= cuoi) {
      ll mid = (dau + cuoi) >> 1;
      if (check(mid))
        dau = mid + 1;
      else
        cuoi = mid - 1;
    }
    cout << cuoi << "\n";
  }
  return 0;
}
