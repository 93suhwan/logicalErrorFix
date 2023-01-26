#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int vis[N];
char s[N];
int mp[N], ans, a[N], fla, f, b[N];
void dfs(int x, int cnt) {
  if (vis[mp[x]]) {
    f = 1;
    vis[x] = vis[mp[x]] + 1;
    ans = max(ans, vis[x]);
    return;
  }
  if (b[x]) return;
  b[x] = 1;
  if (a[mp[x]]) {
    dfs(mp[x], cnt + 1);
  } else {
    f = 1;
    ans = max(ans, cnt);
  }
  if (f) vis[x] = cnt;
  b[x] = 0;
}
int main() {
  int n, m, k, _, d;
  scanf("%d", &_);
  while (_--) {
    ans = fla = 0;
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      vis[i] = b[i] = 0;
      mp[i] = (i + n - d) % n;
    }
    for (int i = 0; i < n; i++) {
      if (a[i] && vis[i] == 0) {
        f = 0;
        dfs(i, 1);
      }
    }
    for (int i = 0; i < n; i++) {
      if (a[i] && vis[i] == 0) {
        fla = 1;
        break;
      }
    }
    if (fla)
      printf("-1\n");
    else
      printf("%d\n", ans);
  }
  return 0;
}
