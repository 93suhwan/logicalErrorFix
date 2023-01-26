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
void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < (n); i++) cin >> s[i];
  vector<int> G(n * m, -1);
  string dir = "LDRU";
  vector<int> deg(n * m, 0);
  for (int i = 0; i < (n); i++)
    for (int j = 0; j < (m); j++) {
      for (int k = 0; k < (4); k++) {
        if (s[i][j] == dir[k]) {
          int ny = i + dy[k];
          int nx = j + dx[k];
          if (in(ny, nx, n, m)) {
            G[i * m + j] = ny * m + nx;
            deg[ny * m + nx]++;
          }
        }
      }
    }
  vector<int> g = G;
  vector<bool> notCycle(n * m, 0);
  queue<int> q;
  for (int i = 0; i < (n * m); i++)
    if (deg[i] == 0) q.push(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    notCycle[u] = 1;
    int v = g[u];
    deg[v]--;
    if (deg[v] == 0) q.push(v);
  }
  for (int i = 0; i < (n * m); i++) deg[i] = 0;
  for (int i = 0; i < (n * m); i++) deg[G[i]]++;
  int ans = 0;
  pair<int, int> anspos;
  vector<pair<int, int> > d(n * m, {0, 0}), D(n * m, {0, 0});
  vector<int> ls;
  for (int i = 0; i < (n * m); i++) {
    if (d[i].first > 0) continue;
    if (!notCycle[i]) {
      d[i] = {1, i};
      q.push(i);
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        ls.push_back(u);
        int v = G[u];
        deg[v]--;
        if (d[v].first > 0) {
          for (auto x : ls) d[x] = d[u];
          break;
        }
        d[v] = {d[u].first + 1, d[u].second};
        q.push(v);
      }
    }
    ls.clear();
  }
  for (int i = 0; i < (n * m); i++) {
    if (deg[i] == 0 && notCycle[i]) {
      q.push(i);
      d[i] = {1, i};
    }
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    int v = G[u];
    if (v == -1) continue;
    if (notCycle[v]) {
      chmax(d[v], pair<int, int>{d[u].first + 1, d[u].second});
    } else {
      chmax(D[v], pair<int, int>{d[u].first + d[v].first, d[u].second});
      continue;
    }
    deg[v]--;
    if (deg[v] == 0) q.push(v);
  }
  for (int i = 0; i < (n * m); i++) {
    if (chmax(ans, d[i].first)) {
      anspos = {d[i].second / m, d[i].second % m};
    }
    if (chmax(ans, D[i].first)) {
      anspos = {D[i].second / m, D[i].second % m};
    }
  }
  cout << anspos.first + 1 << " " << anspos.second + 1 << " " << ans << "\n";
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
