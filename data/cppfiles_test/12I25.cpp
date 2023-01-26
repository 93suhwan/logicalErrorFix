#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
int n, m;
char s[N][N];
pair<int, int> f[N][N];
pair<int, int> ans[N][N];
inline int Sqr(int x) { return x * x; }
inline void Update(pair<int, int> &u, pair<int, int> v, int x, int y) {
  if (Sqr(u.first - x) + Sqr(u.second - y) >
      Sqr(v.first - x) + Sqr(v.second - y))
    u = v;
}
int main() {
  scanf("%d%d", &n, &m);
  ++n;
  ++m;
  for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) ans[i][j] = pair<int, int>(1e4, 1e4);
  for (int i = 0; i <= n + 1; ++i)
    for (int j = 0; j <= m + 1; ++j) f[i][j] = pair<int, int>(1e4, 1e4);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      if (s[i][j] == '1')
        f[i][j] = pair<int, int>(i, j);
      else {
        Update(f[i][j], f[i - 1][j], i, j);
        Update(f[i][j], f[i][j - 1], i, j);
        Update(f[i][j], f[i - 1][j - 1], i, j);
      }
      Update(ans[i][j], f[i][j], i, j);
    }
  for (int i = 0; i <= n + 1; ++i)
    for (int j = 0; j <= m + 1; ++j) f[i][j] = pair<int, int>(1e4, 1e4);
  for (int i = 1; i <= n; ++i)
    for (int j = m; j; --j) {
      if (s[i][j] == '1')
        f[i][j] = pair<int, int>(i, j);
      else {
        Update(f[i][j], f[i - 1][j], i, j);
        Update(f[i][j], f[i][j + 1], i, j);
        Update(f[i][j], f[i - 1][j + 1], i, j);
      }
      Update(ans[i][j], f[i][j], i, j);
    }
  for (int i = 0; i <= n + 1; ++i)
    for (int j = 0; j <= m + 1; ++j) f[i][j] = pair<int, int>(1e4, 1e4);
  for (int i = n; i; --i)
    for (int j = 1; j <= m; ++j) {
      if (s[i][j] == '1')
        f[i][j] = pair<int, int>(i, j);
      else {
        Update(f[i][j], f[i + 1][j], i, j);
        Update(f[i][j], f[i][j - 1], i, j);
        Update(f[i][j], f[i + 1][j - 1], i, j);
      }
      Update(ans[i][j], f[i][j], i, j);
    }
  for (int i = 0; i <= n + 1; ++i)
    for (int j = 0; j <= m + 1; ++j) f[i][j] = pair<int, int>(1e4, 1e4);
  for (int i = n; i; --i)
    for (int j = m; j; --j) {
      if (s[i][j] == '1')
        f[i][j] = pair<int, int>(i, j);
      else {
        Update(f[i][j], f[i + 1][j], i, j);
        Update(f[i][j], f[i][j + 1], i, j);
        Update(f[i][j], f[i + 1][j + 1], i, j);
      }
      Update(ans[i][j], f[i][j], i, j);
    }
  long long sm = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      sm += Sqr(ans[i][j].first - i) + Sqr(ans[i][j].second - j);
  cout << sm << endl;
  return 0;
}
