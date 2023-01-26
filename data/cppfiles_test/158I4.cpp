#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cout << x; }
void __print(long x) { cout << x; }
void __print(long long x) { cout << x; }
void __print(unsigned x) { cout << x; }
void __print(unsigned long x) { cout << x; }
void __print(unsigned long long x) { cout << x; }
void __print(float x) { cout << x; }
void __print(double x) { cout << x; }
void __print(long double x) { cout << x; }
void __print(char x) { cout << '\'' << x << '\''; }
void __print(const char *x) { cout << '\"' << x << '\"'; }
void __print(const string &x) { cout << '\"' << x << '\"'; }
void __print(bool x) { cout << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cout << '{';
  __print(x.first);
  cout << ',';
  __print(x.second);
  cout << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cout << '{';
  for (auto &i : x) cout << (f++ ? "," : ""), __print(i);
  cout << "}";
}
void _print() { cout << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cout << ", ";
  _print(v...);
}
const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const int d8i[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
          d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};
template <class T>
bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
bool ckmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> x(n);
  for (auto &y : x) cin >> y;
  vector<vector<int> > q(n, vector<int>(m));
  for (auto &v : q) {
    string s;
    cin >> s;
    for (int i = 0; i < m; ++i) v[i] = s[i] - '0';
  }
  vector<int> sol;
  int best = -1;
  for (int mask = 0; mask < (1 << n); ++mask) {
    int cost = 0;
    for (int i = 0; i < n; ++i) {
      int bit = (1 << i) & mask;
      cost += x[i] * (bit == 0 ? 1 : -1);
    }
    vector<int> qc(m);
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        int bit = (1 << j) & mask;
        if (q[j][i]) qc[i] += bit ? 1 : -1;
      }
    vector<int> ids(m);
    iota((ids).begin(), (ids).end(), 0);
    sort((ids).begin(), (ids).end(),
         [&](int a, int b) { return qc[a] < qc[b]; });
    for (int i = 0; i < m; ++i) cost += (i + 1) * qc[ids[i]];
    if (cost > best) {
      best = cost;
      sol = ids;
    }
  }
  for (auto y : sol) cout << y + 1 << " ";
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(12);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
