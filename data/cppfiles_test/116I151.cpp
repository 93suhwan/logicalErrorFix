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
const int lim = 5e5 + 5;
long long val[lim][2];
int solve() {
  int n;
  cin >> n;
  long long ans = 0, one = 0;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] == 1) one++;
    long long a = (arr[i] == 0 ? 1 : 0), b = (arr[i] == 1 ? 1 : 0);
    if (arr[i] - 1 >= 0) a = modAdd(a, val[arr[i] - 1][0], mod);
    if (arr[i] - 2 >= 0) b = modAdd(b, val[arr[i] - 2][0], mod);
    a = modAdd(a, val[arr[i]][0], mod);
    b = modAdd(b, val[arr[i]][1], mod);
    ans = modAdd(ans, a, mod);
    ans = modAdd(ans, b, mod);
    val[arr[i]][0] = modAdd(val[arr[i]][0], a, mod);
    val[arr[i]][1] = modAdd(val[arr[i]][1], b, mod);
  }
  cout << ans << "\n";
  for (int i = 0; i < n; i++) val[arr[i]][0] = val[arr[i]][1] = 0;
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
