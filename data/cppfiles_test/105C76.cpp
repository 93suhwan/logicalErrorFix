#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << '(' << p.first << ',' << p.second << ')';
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << '{';
  for (int i = 0; i < (int)v.size(); i++) {
    if (i) {
      os << ',';
    }
    os << v[i];
  }
  os << '}';
  return os;
}
ostream &operator<<(ostream &os, const set<int> &se) {
  os << '{';
  int now = 0;
  for (auto x : se) {
    if (now) {
      os << ',';
    }
    os << x;
    now++;
  }
  os << '}';
  return os;
}
void debugg() { cerr << endl; }
template <class T, class... Args>
void debugg(const T &x, const Args &...args) {
  cerr << " " << x;
  debugg(args...);
}
using namespace std;
const int inf = (1 << 30) - 1;
const long long linf = 1LL << 61;
const int MAX = 510000;
int dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};
int dx[8] = {-1, 0, 1, 0, 1, -1, 1, -1};
const double pi = acos(-1);
const double eps = 1e-8;
template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {
  if (a > b) {
    a = b;
    return true;
  } else
    return false;
}
template <typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {
  if (a < b) {
    a = b;
    return true;
  } else
    return false;
}
template <typename T>
inline void print(T &a) {
  int sz = a.size();
  for (auto itr = a.begin(); itr != a.end(); itr++) {
    cout << *itr;
    sz--;
    if (sz) cout << " ";
  }
  cout << "\n";
}
template <typename T1, typename T2>
inline void print2(T1 a, T2 b) {
  cout << a << " " << b << "\n";
}
template <typename T1, typename T2, typename T3>
inline void print3(T1 a, T2 b, T3 c) {
  cout << a << " " << b << " " << c << "\n";
}
void mark() {
  cout << "#"
       << "\n";
}
long long pcount(long long x) { return __builtin_popcountll(x); }
const int mod = 998244353;
void solve() {
  int n;
  cin >> n;
  vector<long long> a(n), b(n), m(n);
  map<long long, vector<vector<long long> > > mp;
  for (int i = 0; i < (n); i++) {
    cin >> a[i] >> b[i] >> m[i];
    mp[a[i] + b[i] - m[i]].push_back(vector<long long>{
        a[i] + min(0LL, b[i] - m[i]), max(0LL, a[i] - m[i]), i});
  }
  int ans = 0;
  vector<long long> A(n), B(n);
  for (auto v : mp) {
    sort((v.second).begin(), (v.second).end());
    vector<long long> r;
    for (auto x : v.second) {
      if (r.empty() || x[1] > r.back()) {
        ans++;
        r.push_back(x[0]);
      }
      A[x[2]] = a[x[2]] - r.back();
      B[x[2]] = m[x[2]] - A[x[2]];
    }
  }
  cout << ans << "\n";
  for (int i = 0; i < (n); i++) cout << A[i] << " " << B[i] << "\n";
}
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
