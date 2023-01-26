#include <bits/stdc++.h>
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
const int maxn = (int)1e5 + 1;
int n, t;
int m;
void solve() {
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < (int)n; ++i)
    for (int j = 0; j < (int)m; ++j) scanf("%d", &a[i][j]);
  vector<int> ord(n);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(),
       [&a](int x, int y) { return a[x][0] > a[y][0]; });
  vector<vector<int>> maxl(n, vector<int>(m, INT_MIN));
  vector<vector<int>> minr(n, vector<int>(m, INT_MAX));
  for (int i = n - 1; i >= 0; i--)
    for (int j = 0; j < (int)m; ++j) {
      maxl[i][j] = a[ord[i]][j];
      if (i < n - 1) maxl[i][j] = max(maxl[i][j], maxl[i + 1][j]);
      if (j > 0) maxl[i][j] = max(maxl[i][j], maxl[i][j - 1]);
    }
  for (int i = n - 1; i >= 0; i--)
    for (int j = m - 1; j >= 0; j--) {
      minr[i][j] = a[ord[i]][j];
      if (i < n - 1) minr[i][j] = min(minr[i][j], minr[i + 1][j]);
      if (j < m - 1) minr[i][j] = min(minr[i][j], minr[i][j + 1]);
    }
  vector<int> minl(m, INT_MAX), maxr(m, INT_MIN);
  pair<int, int> ans = {-1, -1};
  for (int i = 0; i < (int)n - 1; ++i) {
    for (int j = 0; j < (int)m; ++j) {
      minl[j] = a[ord[i]][j];
      if (j > 0) minl[j] = min(minl[j], minl[j - 1]);
    }
    for (int j = m - 1; j >= 0; j--) {
      maxr[j] = a[ord[i]][j];
      if (j < m - 1) maxr[j] = max(maxr[j], maxr[j + 1]);
    }
    for (int j = 0; j < (int)m - 1; ++j)
      if (minl[j] > maxl[i + 1][j] and maxr[j + 1] < minr[i + 1][j + 1]) {
        ans = {i, j};
      }
  }
  if (ans.first == -1) {
    puts("NO");
    return;
  }
  puts("YES");
  string res(n, ' ');
  for (int i = 0; i < (int)n; ++i) res[ord[i]] = i <= ans.first ? 'R' : 'B';
  printf("%s %d\n", res.c_str(), ans.second + 1);
}
int main() {
  cin >> t;
  while (t--) solve();
  return 0;
}
