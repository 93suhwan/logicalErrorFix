#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
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
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
const long long maxn = 1e6 + 4;
void solve() {
  long long n, m;
  cin >> n >> m;
  string s[n];
  pair<long long, long long> str;
  for (long long i = 0; i < n; i++) {
    cin >> s[i];
    for (long long j = 0; j < m; j++) {
      if (s[i][j] == 'L') str = {i, j};
    }
  }
  auto inside = [&](long long a, long long b) {
    return (a >= 0 && a < n && b >= 0 && b < m);
  };
  vector<vector<long long> > deg(n, vector<long long>(m));
  vector<pair<long long, long long> > dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      for (pair<long long, long long> d : dir) {
        long long ni = i + d.first;
        long long nj = j + d.second;
        if (inside(ni, nj) && s[ni][nj] != '#') {
          deg[i][j]++;
        }
      }
    }
  }
  set<vector<long long> > st;
  vector<vector<long long> > vis(n, vector<long long>(m));
  vector<vector<long long> > strict(n, vector<long long>(m));
  st.insert({0, str.first, str.second});
  vis[str.first][str.second] = 1;
  strict[str.first][str.second] = 1;
  string map[n];
  auto dof = [&](long long a, long long b) {
    long long df = 0;
    for (pair<long long, long long> d : dir) {
      long long ni = a + d.first;
      long long nj = b + d.second;
      if (inside(ni, nj) && s[ni][nj] != '#') {
        df += strict[ni][nj];
      }
    }
    return (deg[a][b] - df);
  };
  for (long long i = 0; i < n; i++) map[i] = s[i];
  while (!st.empty()) {
    vector<long long> tp = *st.begin();
    st.erase(st.begin());
    long long i = tp[1];
    long long j = tp[2];
    long long dege = tp[0];
    for (pair<long long, long long> d : dir) {
      long long ni = i + d.first;
      long long nj = j + d.second;
      if (inside(ni, nj) && s[ni][nj] != '#' && !vis[ni][nj]) {
        if (dof(ni, nj) <= 1) {
          strict[ni][nj] = 1;
          vis[ni][nj] = 1;
          st.insert({0, ni, nj});
          map[ni][nj] = '+';
        }
      }
    }
  }
  for (string x : map) {
    for (char y : x) {
      cout << y;
    }
    cout << '\n';
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) solve();
}
