#include <bits/stdc++.h>
using namespace std;
template <typename... T>
void show(T&&... args) {
  ((cerr << args << " "), ...);
}
template <typename F, typename S>
ostream& operator<<(ostream& os, const pair<F, S>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "{";
  typename vector<T>::const_iterator it;
  for (it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "}";
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  os << "[";
  typename set<T>::const_iterator it;
  for (it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}
template <typename T>
ostream& operator<<(ostream& os, const multiset<T>& v) {
  os << "[";
  typename multiset<T>::const_iterator it;
  for (it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}
template <typename F, typename S>
ostream& operator<<(ostream& os, const map<F, S>& v) {
  os << "[";
  typename map<F, S>::const_iterator it;
  for (it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << it->first << " = " << it->second;
  }
  return os << "]";
}
template <typename F, typename S>
ostream& operator<<(ostream& os, const unordered_map<F, S>& v) {
  os << "[";
  typename unordered_map<F, S>::const_iterator it;
  for (it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << it->first << " = " << it->second;
  }
  return os << "]";
}
template <typename... T>
void read(T&... args) {
  ((cin >> args), ...);
}
template <typename... T>
void write(T&&... args) {
  ((cout << args << " "), ...);
}
inline void file_io(string path1 = "", string path2 = "") {
  if (path2.size() == 0) path2 = path1;
  freopen(path1.c_str(), "r", stdin);
  freopen(path2.c_str(), "w", stdout);
}
template <typename T>
T egcd(T a, T b, T& x, T& y) {
  x = 1, y = 0;
  T x1 = 0, y1 = 1, a1 = a, b1 = b;
  while (b1) {
    T q = a1 / b1;
    tie(x, x1) = make_tuple(x1, x - q * x1);
    tie(y, y1) = make_tuple(y1, y - q * y1);
    tie(a1, b1) = make_tuple(b1, a1 - q * b1);
  }
  return a1;
}
template <typename F, typename S>
F bigMod(F a, F b, S mod) {
  a %= mod;
  F res = 1;
  while (b > 0) {
    if (b & 1) res = ((long long)res * a) % mod;
    a = ((long long)a * a) % mod;
    b >>= 1;
  }
  return res;
}
inline int modAdd(long long _a, long long _b, long long mod) {
  if (_a < 0) {
    _a += mod;
  }
  if (_b < 0) {
    _b += mod;
  }
  if (_a + _b >= mod) return (_a + _b - mod);
  return (_a + _b);
}
inline int modMul(long long _a, long long _b, long long mod) {
  if (_a < 0) {
    _a += mod;
  }
  if (_b < 0) {
    _b += mod;
  }
  return (_a * _b) % mod;
}
inline int modInv(long long a, long long mod) {
  return bigMod(a, mod - 2, mod);
}
const long long mod = 998244353;
int solve() {
  int n;
  cin >> n;
  int dp[n + 5][2], ans = 0;
  memset(dp, 0, sizeof dp);
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    dp[val + 1][0] = modAdd(dp[val + 1][0], dp[val + 1][0], mod);
    dp[val + 1][0] = modAdd(dp[val + 1][0], dp[val][0], mod);
    if (val - 1 >= 0)
      dp[val - 1][1] = modAdd(dp[val - 1][1], dp[val - 1][1], mod);
    if (val - 1 >= 0)
      dp[val - 1][1] = modAdd(dp[val - 1][1], dp[val - 1][0], mod);
    dp[val + 1][1] = modAdd(dp[val + 1][1], dp[val + 1][1], mod);
  }
  for (int i = 0; i < n + 5; i++) {
    ans = modAdd(ans, dp[i][0], mod);
    ans = modAdd(ans, dp[i][1], mod);
  }
  ans = modAdd(ans, -1, mod);
  cout << ans << "\n";
  return 0;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  ;
  ;
  int t = 1, cs = 0;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
