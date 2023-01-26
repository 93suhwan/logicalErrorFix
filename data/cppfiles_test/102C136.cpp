#include <bits/stdc++.h>
using namespace std;
template <class T>
using V = vector<T>;
template <class T, size_t SZ>
using AR = array<T, SZ>;
template <class T>
using PR = pair<T, T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template <class T>
int lwb(V<T>& a, const T& b) {
  return int(lower_bound(begin(a), end(a), b) - begin(a));
}
const int MOD = 1e9 + 7;
const long long INF = 1e18;
const double PI = acos((double)-1);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x); }
constexpr int p2(int x) { return 1 << x; }
constexpr int msk2(int x) { return p2(x) - 1; }
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return b > a ? a = b, 1 : 0;
}
long long cdiv(long long a, long long b) {
  return a / b + ((a ^ b) > 0 && a % b);
}
long long fdiv(long long a, long long b) {
  return a / b - ((a ^ b) < 0 && a % b);
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
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V>& x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T& x) {
  int first = 0;
  cerr << '{';
  for (auto& i : x) cerr << (first++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
void setPrec() { cout << fixed << setprecision(16); }
void setIO(string name = "") {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  setPrec();
  if ((int)(name).size()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}
int N, M;
string S;
void solve() {
  cin >> N >> M;
  cin >> S;
  int xmax = 0, xmin = 0, ymax = 0, ymin = 0;
  pair<int, int> cur = {0, 0};
  int pos = (int)(S).size();
  for (int i = (0); i < ((int)(S).size()); ++i) {
    if (S[i] == 'U')
      cur.first -= 1;
    else if (S[i] == 'D')
      cur.first += 1;
    else if (S[i] == 'L')
      cur.second -= 1;
    else if (S[i] == 'R')
      cur.second += 1;
    ckmin(xmin, cur.first);
    ckmin(ymin, cur.second);
    ckmax(xmax, cur.first);
    ckmax(ymax, cur.second);
    if (xmax - xmin + 1 > N || ymax - ymin + 1 > M) {
      pos = i;
      break;
    }
  }
  cur = {0, 0};
  xmax = 0, xmin = 0, ymax = 0, ymin = 0;
  for (int i = (0); i < (pos); ++i) {
    if (S[i] == 'U')
      cur.first -= 1;
    else if (S[i] == 'D')
      cur.first += 1;
    else if (S[i] == 'L')
      cur.second -= 1;
    else if (S[i] == 'R')
      cur.second += 1;
    ckmin(xmin, cur.first);
    ckmin(ymin, cur.second);
    ckmax(xmax, cur.first);
    ckmax(ymax, cur.second);
  }
  cout << abs(xmin) + 1 << " " << abs(ymin) + 1 << "\n";
}
int main() {
  setIO();
  int t = 1;
  cin >> t;
  while (t-- > 0) {
    solve();
  }
  return 0;
}
