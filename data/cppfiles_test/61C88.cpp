#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T, size_t N>
inline ostream &operator<<(ostream &os, const array<T, N> &a) {
  os << "[";
  int cnt = 0;
  for (auto &val : a) {
    if (cnt++) os << ", ";
    os << val;
  }
  os << "]";
  return os;
}
template <typename T>
inline ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  int cnt = 0;
  for (auto &val : v) {
    if (cnt++) os << ", ";
    os << val;
  }
  return os << "]";
}
template <typename T>
inline ostream &operator<<(ostream &os, const set<T> &v) {
  os << "{";
  int cnt = 0;
  for (auto &val : v) {
    if (cnt++) os << ", ";
    os << val;
  }
  return os << "}";
}
template <typename T>
inline ostream &operator<<(ostream &os, const unordered_set<T> &v) {
  os << "{";
  int cnt = 0;
  for (auto &val : v) {
    if (cnt++) os << ", ";
    os << val;
  }
  return os << "}";
}
template <typename T>
inline ostream &operator<<(ostream &os, const multiset<T> &v) {
  os << "{";
  int cnt = 0;
  for (auto &val : v) {
    if (cnt++) os << ", ";
    os << val;
  }
  return os << "}";
}
template <typename T1, typename T2>
inline ostream &operator<<(ostream &os, const map<T1, T2> &v) {
  os << "[";
  int cnt = 0;
  for (auto &val : v) {
    if (cnt++) os << ", ";
    os << val;
  }
  return os << "]";
}
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args) {
  const char *comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vs = vector<string>;
using vb = vector<bool>;
using vd = vector<double>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using vc = vector<char>;
using si = set<int>;
using mpii = map<int, int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const char nl = '\n';
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T>
inline bool umin(T &a, const T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
inline bool umax(T &a, const T b) {
  return a < b ? a = b, 1 : 0;
}
ll solve() {
  int n;
  cin >> n;
  vector<pii> t(n);
  vi a(n + 1, 0), b(n + 1, 0);
  for (int i = 0; i < (n); i++) {
    cin >> t[i].first >> t[i].second;
    a[t[i].first]++;
    b[t[i].second]++;
  }
  ll ans = 1LL * n * (n - 1) * (n - 2) / 6;
  for (int i = 0; i < (n); i++) {
    ans -= 1LL * (a[t[i].first] - 1) * (b[t[i].second] - 1);
  }
  return ans;
}
void solve(int _cas) { cout << solve() << endl; }
int main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL), cout.precision(12);
  int cas;
  cin >> cas;
  for (int i = 0; i < (cas); i++) solve(i + 1);
}
