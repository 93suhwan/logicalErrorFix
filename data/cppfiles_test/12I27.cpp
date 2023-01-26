#include <bits/stdc++.h>
using namespace std;
const int dx[] = {1, 1, -1, -1};
const int dy[] = {1, -1, 1, -1};
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
  for (int d = 0; d < 4; ++d) {
    for (int i = 0; i <= n + 1; ++i)
      for (int j = 0; j <= m + 1; ++j) f[i][j] = pair<int, int>(1e4, 1e4);
    for (int pi = 1; pi <= n; ++pi)
      for (int pj = 1; pj <= m; ++pj) {
        int i = dx[d] == 1 ? pi : n - pi + 1;
        int j = dy[d] == 1 ? pj : m - pj + 1;
        if (s[i][j] == '1')
          f[i][j] = pair<int, int>(i, j);
        else {
          for (int di = 0; di <= 4; ++di)
            for (int dj = 0; dj <= 4; ++dj)
              if (di || dj) {
                int ni = i - dx[d] * di, nj = j - dy[d] * dj;
                if (ni < 1 || ni > n || nj < 1 || nj > m) continue;
                Update(f[i][j], f[ni][nj], i, j);
              }
        }
        Update(ans[i][j], f[i][j], i, j);
      }
  }
  long long sm = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      sm += Sqr(ans[i][j].first - i) + Sqr(ans[i][j].second - j);
  cout << sm << endl;
  return 0;
}
