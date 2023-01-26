#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vii = vector<pii>;
struct fast_ios {
  fast_ios() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  };
} fast_ios_;
template <typename T>
void ndarray(vector<T> &vec, int len) {
  vec.resize(len);
}
template <typename T, typename... Args>
void ndarray(vector<T> &vec, int len, Args... args) {
  vec.resize(len);
  for (auto &v : vec) ndarray(v, args...);
}
template <typename V, typename T>
void ndfill(V &x, const T &val) {
  x = val;
}
template <typename V, typename T>
void ndfill(vector<V> &vec, const T &val) {
  for (auto &v : vec) ndfill(v, val);
}
template <typename T>
bool chmax(T &m, const T q) {
  if (m < q) {
    m = q;
    return true;
  } else
    return false;
}
template <typename T>
bool chmin(T &m, const T q) {
  if (m > q) {
    m = q;
    return true;
  } else
    return false;
}
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) {
  return make_pair(l.first + r.first, l.second + r.second);
}
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) {
  return make_pair(l.first - r.first, l.second - r.second);
}
template <typename T>
vector<T> srtunq(vector<T> vec) {
  sort(vec.begin(), vec.end()),
      vec.erase(unique(vec.begin(), vec.end()), vec.end());
  return vec;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (auto &v : vec) is >> v;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << '[';
  for (auto v : vec) os << v << ',';
  os << ']';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const deque<T> &vec) {
  os << "deq[";
  for (auto v : vec) os << v << ',';
  os << ']';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &vec) {
  os << '{';
  for (auto v : vec) os << v << ',';
  os << '}';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_set<T> &vec) {
  os << '{';
  for (auto v : vec) os << v << ',';
  os << '}';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &vec) {
  os << '{';
  for (auto v : vec) os << v << ',';
  os << '}';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_multiset<T> &vec) {
  os << '{';
  for (auto v : vec) os << v << ',';
  os << '}';
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &pa) {
  os << '(' << pa.first << ',' << pa.second << ')';
  return os;
}
template <typename TK, typename TV>
ostream &operator<<(ostream &os, const map<TK, TV> &mp) {
  os << '{';
  for (auto v : mp) os << v.first << "=>" << v.second << ',';
  os << '}';
  return os;
}
template <typename TK, typename TV>
ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp) {
  os << '{';
  for (auto v : mp) os << v.first << "=>" << v.second << ',';
  os << '}';
  return os;
}
constexpr ll MOD = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> a(2, vector<int>(n));
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      a[i][j] = c - '0';
    }
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    if (a[0][i] == 1 && a[1][i] == 1) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}
int main() {
  fast_ios_;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
