#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
template <class T>
void take(vector<T> &v, long long &n) {
  cin >> n;
  v.resize(n);
  for (auto &zz : v) cin >> zz;
}
template <class T>
void take(vector<vector<T>> &v, long long &n, long long &m) {
  cin >> n >> m;
  v.resize(n, vector<T>(m));
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> v[i][j];
    }
  }
}
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
  long long f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() {
  cerr << "]\n"
       << "\033[0m";
}
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
long long n, k;
vector<long long> v;
void take() {
  cin >> n >> k;
  v.resize(n);
  for (auto &zz : v) cin >> zz;
}
void solve() {
  take();
  sort(v.begin(), v.end());
  vector<long long> pos;
  vector<long long> neg;
  for (auto t : v) {
    if (t < 0)
      neg.push_back(t);
    else
      pos.push_back(t);
  }
  long long ans = 0;
  for (long long i = 0; i < neg.size(); i++) {
    ans -= 2 * neg[i];
    i += k - 1;
    i = min(i, (long long)neg.size() - 1);
  }
  reverse(pos.begin(), pos.end());
  for (long long i = 0; i < pos.size(); i++) {
    ans += 2 * pos[i];
    i += k - 1;
    i = min(i, (long long)pos.size() - 1);
  }
  long long check = -1;
  if (pos.size() > 0) check = max(check, pos[0]);
  if (neg.size() > 0) check = max(check, -1 * neg[0]);
  ans -= check;
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  auto time0 = chrono::high_resolution_clock::now();
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
}
