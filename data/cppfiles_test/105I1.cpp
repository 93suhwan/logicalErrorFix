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
bool in(long long y, long long x, long long h, long long w) {
  return 0 <= y && y < h && 0 <= x && x < w;
}
vector<vector<pair<long long, long long> > > v(1010101);
void solve() {
  int n;
  cin >> n;
  vector<long long> a(n), b(n), m(n);
  vector<long long> ex;
  for (int i = 0; i < (n); i++) {
    cin >> a[i] >> b[i] >> m[i];
    v[a[i] + b[i] - m[i]].emplace_back(max(0LL, a[i] - m[i]),
                                       a[i] + min(0LL, b[i] - m[i]));
    ex.push_back(a[i] + b[i] - m[i]);
  }
  sort((ex).begin(), (ex).end());
  ex.erase(unique((ex).begin(), (ex).end()), ex.end());
  int ans = 0;
  pair<long long, long long> pos = {linf, linf};
  for (auto x : ex) {
    vector<pair<long long, long long> > eve;
    for (auto p : v[x]) {
      eve.emplace_back(p.first, 0);
      eve.emplace_back(p.second, 1);
    }
    sort((eve).begin(), (eve).end());
    int cnt = 0;
    for (auto p : eve) {
      if (p.second == 0)
        cnt++;
      else
        cnt--;
      if (chmax(ans, cnt)) pos = {x, p.first};
    }
    v[x].clear();
  }
  cout << n - ans + 1 << "\n";
  for (int i = 0; i < (n); i++) {
    if (a[i] + b[i] - m[i] == pos.first && a[i] - m[i] <= pos.second &&
        pos.second <= a[i] && m[i] - (a[i] - pos.second) <= b[i]) {
      cout << a[i] - pos.second << " " << m[i] - (a[i] - pos.second) << "\n";
    } else {
      long long A = min(a[i], m[i]);
      cout << A << " " << m[i] - A << "\n";
    }
  }
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
