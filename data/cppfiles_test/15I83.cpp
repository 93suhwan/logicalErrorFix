#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
const long long N = 1e6 + 5;
bool isval(long long x, long long y, long long n, long long m,
           vector<vector<char>>& v) {
  return (x >= 1 && x <= n && y >= 1 && y <= m && v[x][y] == '*');
}
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  vector<vector<char>> v(n + 1, vector<char>(m + 1));
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      cin >> v[i][j];
    }
  }
  vector<vector<long long>> vis(n + 1, vector<long long>(m + 1));
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      if (v[i][j] == '*') {
        long long c1 = 0, c2 = 0;
        long long x = i - 1, y = j - 1;
        vector<pair<long long, long long>> pp;
        pp.push_back({i, j});
        while (isval(x, y, n, m, v)) {
          pp.push_back({x, y});
          x--;
          y--;
          c1++;
        }
        x = i - 1, y = j + 1;
        while (isval(x, y, n, m, v)) {
          pp.push_back({x, y});
          x--;
          y++;
          c2++;
        }
        if (c1 >= k && c2 >= k) {
          for (auto f : pp) {
            vis[f.first][f.second] = 1;
          }
        }
      }
    }
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      if (v[i][j] == '*' && !vis[i][j]) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
