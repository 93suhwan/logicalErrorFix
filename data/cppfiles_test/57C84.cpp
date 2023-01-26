#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v) is >> x;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (int i = 0; i < (int)v.size(); i++) {
    os << v[i] << (i + 1 == (int)v.size() ? "" : " ");
  }
  return os;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  os << '(' << p.first << ',' << p.second << ')';
  return os;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, const map<T, U>& m) {
  os << '{';
  for (auto itr = m.begin(); itr != m.end();) {
    os << '(' << itr->first << ',' << itr->second << ')';
    if (++itr != m.end()) os << ',';
  }
  os << '}';
  return os;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, const unordered_map<T, U>& m) {
  os << '{';
  for (auto itr = m.begin(); itr != m.end();) {
    os << '(' << itr->first << ',' << itr->second << ')';
    if (++itr != m.end()) os << ',';
  }
  os << '}';
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& s) {
  os << '{';
  for (auto itr = s.begin(); itr != s.end();) {
    os << *itr;
    if (++itr != s.end()) os << ',';
  }
  os << '}';
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const multiset<T>& s) {
  os << '{';
  for (auto itr = s.begin(); itr != s.end();) {
    os << *itr;
    if (++itr != s.end()) os << ',';
  }
  os << '}';
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const unordered_set<T>& s) {
  os << '{';
  for (auto itr = s.begin(); itr != s.end();) {
    os << *itr;
    if (++itr != s.end()) os << ',';
  }
  os << '}';
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const deque<T>& v) {
  for (int i = 0; i < (int)v.size(); i++) {
    os << v[i] << (i + 1 == (int)v.size() ? "" : " ");
  }
  return os;
}
template <int i, typename T>
void print_tuple(ostream&, const T&) {}
template <int i, typename T, typename H, class... Args>
void print_tuple(ostream& os, const T& t) {
  if (i) os << ',';
  os << get<i>(t);
  print_tuple<i + 1, T, Args...>(os, t);
}
template <typename... Args>
ostream& operator<<(ostream& os, const tuple<Args...>& t) {
  os << '{';
  print_tuple<0, tuple<Args...>, Args...>(os, t);
  return os << '}';
}
void debug_out() { cerr << '\n'; }
template <class Head, class... Tail>
void debug_out(Head&& head, Tail&&... tail) {
  cerr << head;
  if (sizeof...(Tail) > 0) cerr << ", ";
  debug_out(move(tail)...);
}
template <typename T>
T gcd(T x, T y) {
  return y != 0 ? gcd(y, x % y) : x;
}
template <typename T>
T lcm(T x, T y) {
  return x / gcd(x, y) * y;
}
int topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
int topbit(long long t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
int botbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }
int botbit(long long a) { return a == 0 ? 64 : __builtin_ctzll(a); }
int popcount(signed t) { return __builtin_popcount(t); }
int popcount(long long t) { return __builtin_popcountll(t); }
bool ispow2(int i) { return i && (i & -i) == i; }
template <class T>
T ceil(T x, T y) {
  assert(y >= 1);
  return (x > 0 ? (x + y - 1) / y : x / y);
}
template <class T>
T floor(T x, T y) {
  assert(y >= 1);
  return (x > 0 ? x / y : (x - y + 1) / y);
}
template <class T1, class T2>
inline bool chmin(T1& a, T2 b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T1, class T2>
inline bool chmax(T1& a, T2 b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
void solve() {
  long long s, n, k;
  cin >> s >> n >> k;
  if (k > s) {
    cout << "NO" << '\n';
    return;
  }
  if (k == s) {
    cout << "YES" << '\n';
    return;
  }
  long long can = (n / k) * (2 * k) + n % k;
  if (can <= s) {
    cout << "NO" << '\n';
    return;
  }
  cout << "YES" << '\n';
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (; t--;) solve();
  return 0;
}
