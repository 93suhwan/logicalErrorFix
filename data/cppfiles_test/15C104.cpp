#include <bits/stdc++.h>
using namespace std;
int n, m, k;
char M[100][100];
int vis[100][100];
void test(int i, int j) {
  if (M[i][j] == '.') {
    vis[i][j] = 1;
    return;
  }
  for (int d = 1; d <= k; d++) {
    if (i - d < 1 || j - d < 1 || j + d > m) {
      return;
    }
    if (M[i - d][j - d] == '.' || M[i - d][j + d] == '.') {
      return;
    }
  }
  vis[i][j] = 1;
  for (int d = 1; i - d > 0 && j - d > 0 && j + d <= m; d++) {
    if (M[i - d][j - d] == '.' || M[i - d][j + d] == '.') break;
    vis[i - d][j - d] = 1, vis[i - d][j + d] = 1;
  }
}
void solve() {
  memset(vis, 0, sizeof(vis));
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> M[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) test(i, j);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (!vis[i][j]) {
        printf("NO\n");
        return;
      }
    }
  printf("YES\n");
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
