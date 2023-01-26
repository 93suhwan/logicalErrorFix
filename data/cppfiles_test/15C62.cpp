#include <bits/stdc++.h>
using namespace std;
char s[55][55];
void solve() {
  int n, m, r;
  scanf("%d%d%d", &n, &m, &r);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  bool vis[20][20];
  memset(vis, false, sizeof(vis));
  for (int i = r; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int t = min(j, m - j - 1);
      for (int p = r; p <= t; p++) {
        bool flag = true;
        for (int k = 0; k <= p; k++)
          if (s[i - k][j - k] != '*' || s[i - k][j + k] != '*') {
            flag = false;
            break;
          }
        if (flag) {
          for (int k = 0; k <= p; k++)
            vis[i - k][j - k] = vis[i - k][j + k] = true;
        }
      }
    }
  }
  bool flag = true;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (s[i][j] == '*' && !vis[i][j]) {
        flag = false;
      }
  if (flag)
    printf("YES\n");
  else
    printf("NO\n");
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
