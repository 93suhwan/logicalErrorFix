#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 512;
int n, a[N], m = 512;
bool vis[M], b[M][M], ans[M][M], anss[M];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  vis[0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < a[i]; ++j)
      if (vis[j]) b[a[i]][j] = 1;
    vis[a[i]] = 1;
  }
  ans[0][0] = anss[0] = 1;
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < i; ++j)
      if (b[i][j])
        for (int k = 0; k < m; ++k)
          if (ans[j][k]) ans[i][i ^ k] = 1, anss[i ^ k] = 1;
  int cnt = 0;
  for (int i = 0; i < m; ++i)
    if (anss[i]) ++cnt;
  cout << cnt << '\n';
  for (int i = 0; i < m; ++i)
    if (anss[i]) cout << i << ' ';
  cout << '\n';
}
