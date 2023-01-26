#include <bits/stdc++.h>
using namespace std;
clock_t startTime;
double getCurrentTime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
template <typename T, typename U>
inline ostream &operator<<(ostream &_out, const pair<T, U> &_p) {
  _out << _p.first << " " << _p.second;
  return _out;
}
template <typename T, typename U>
inline istream &operator>>(istream &_in, pair<T, U> &_p) {
  _in >> _p.first >> _p.second;
  return _in;
}
template <typename T>
inline ostream &operator<<(ostream &_out, const vector<T> &_v) {
  if (_v.empty()) return _out;
  _out << _v.front();
  for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) _out << ' ' << *_it;
  return _out;
}
template <typename T>
inline istream &operator>>(istream &_in, vector<T> &_v) {
  for (auto &_i : _v) _in >> _i;
  return _in;
}
template <typename T>
inline ostream &operator<<(ostream &_out, const set<T> &_s) {
  if (_s.empty()) return _out;
  _out << *_s.begin();
  for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it;
  return _out;
}
template <typename T>
inline ostream &operator<<(ostream &_out, const multiset<T> &_s) {
  if (_s.empty()) return _out;
  _out << *_s.begin();
  for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it;
  return _out;
}
template <typename T>
inline ostream &operator<<(ostream &_out, const unordered_set<T> &_s) {
  if (_s.empty()) return _out;
  _out << *_s.begin();
  for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it;
  return _out;
}
template <typename T>
inline ostream &operator<<(ostream &_out, const unordered_multiset<T> &_s) {
  if (_s.empty()) return _out;
  _out << *_s.begin();
  for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it;
  return _out;
}
template <typename T, typename U>
inline ostream &operator<<(ostream &_out, const map<T, U> &_m) {
  if (_m.empty()) return _out;
  _out << "{\"" << _m.begin()->first << "\", \"" << _m.begin()->second << "\"}";
  for (auto _it = ++_m.begin(); _it != _m.end(); ++_it)
    _out << ", { \"" << _it->first << "\", \"" << _it->second << "\"}";
  return _out;
}
template <typename T, typename U>
inline ostream &operator<<(ostream &_out, const unordered_map<T, U> &_m) {
  if (_m.empty()) return _out;
  _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')';
  for (auto _it = ++_m.begin(); _it != _m.end(); ++_it)
    _out << ", (" << _it->first << ": " << _it->second << ')';
  return _out;
}
template <typename T>
void out(const vector<T> &a, int n) {
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << ' ';
  }
  cout << "\n";
}
template <typename T>
void out(const vector<vector<T>> &a, int n, int m) {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }
}
template <typename T, typename U>
int less_than_or_equal_to(T val, const vector<U> &a) {
  int n = a.size();
  int l = -1, r = n, mid;
  while (r > l + 1) {
    mid = (l + r) / 2;
    if (a[mid] <= val)
      l = mid;
    else
      r = mid;
  }
  return l;
}
template <typename T, typename U>
int less_than(T val, const vector<U> &a) {
  int n = a.size();
  int l = -1, r = n, mid;
  while (r > l + 1) {
    mid = (l + r) / 2;
    if (a[mid] < val)
      l = mid;
    else
      r = mid;
  }
  return l;
}
template <typename T, typename U>
int greater_than_or_equal_to(T val, const vector<U> &a) {
  int n = a.size();
  int l = -1, r = n, mid;
  while (r > l + 1) {
    mid = (l + r) / 2;
    if (a[mid] < val)
      l = mid;
    else
      r = mid;
  }
  return r;
}
template <typename T, typename U>
int greater_than(T val, const vector<U> &a) {
  int n = a.size();
  int l = -1, r = n, mid;
  while (r > l + 1) {
    mid = (l + r) / 2;
    if (a[mid] <= val)
      l = mid;
    else
      r = mid;
  }
  return r;
}
const int N = 8200;
const int INF = 1e7;
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> a(N);
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    a[x].push_back(i);
  }
  vector<int> dp(N, INF), ndp(N, INF);
  dp[0] = 0;
  for (int i = 1; i < N; ++i) {
    if (a[i].empty()) continue;
    ndp = dp;
    for (int j = 0; j < N; ++j) {
      if (dp[j] != INF) {
        int ind = greater_than(dp[j], a[i]);
        if (ind < (int)a[i].size()) ndp[i ^ j] = min(ndp[i ^ j], a[i][ind]);
      }
    }
    dp = ndp;
  }
  int ans = 0;
  for (int i = 0; i < N; ++i) ans += dp[i] != INF;
  cout << ans << "\n";
  for (int i = 0; i < N; ++i)
    if (dp[i] != INF) cout << i << ' ';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  startTime = clock();
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
