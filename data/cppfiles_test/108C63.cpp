#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int mod = (ll)1e9 + 7;
const int INF = 1e9 + 1;
const int N = 2e5 + 100;
const double eps = 1e-7;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;
template <class T, size_t SZ>
using AR = array<T, SZ>;
template <class T>
using PR = pair<T, T>;
template <typename XPAX>
bool ckma(XPAX &x, XPAX y) {
  return (x < y ? x = y, 1 : 0);
}
template <typename XPAX>
bool ckmi(XPAX &x, XPAX y) {
  return (x > y ? x = y, 1 : 0);
}
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
void solve() {
  int n;
  cin >> n;
  V<int> A(n), B(n);
  VV<int> tt(n);
  V<AR<int, 3>> E;
  for (int i = 0; i < (n); ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < (n); ++i) cin >> B[i];
  for (int i = 0; i < (n); ++i) E.push_back({A[i], B[i], i});
  sort((E).begin(), (E).end(),
       [&](AR<int, 3> x, AR<int, 3> y) { return x[1] < y[1]; });
  for (int i = 0; i < (n - 1); ++i) tt[E[i][2]].push_back(E[i + 1][2]);
  sort((E).begin(), (E).end(),
       [&](AR<int, 3> x, AR<int, 3> y) { return x[0] < y[0]; });
  for (int i = 0; i < (n - 1); ++i) tt[E[i][2]].push_back(E[i + 1][2]);
  queue<int> q;
  V<bool> vis(n, false);
  int mx = *max_element((A).begin(), (A).end());
  int st = find((A).begin(), (A).end(), mx) - A.begin();
  q.push(st);
  vis[st] = 1;
  V<char> ans(n, '0');
  while ((int)q.size()) {
    int v = q.front();
    q.pop();
    for (auto c : tt[v]) {
      if (vis[c]) continue;
      vis[c] = 1;
      q.push(c);
    }
  }
  for (int i = 0; i < (n); ++i) {
    if (vis[i]) ans[i] = '1';
    cout << ans[i];
  }
  cout << '\n';
}
void test_case() {
  int t;
  cin >> t;
  for (int p = 0; p < (t); ++p) {
    solve();
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  test_case();
}
