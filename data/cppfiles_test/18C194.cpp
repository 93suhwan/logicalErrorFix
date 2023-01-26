#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int vis[N];
char s[N];
int mp[N], ans, a[N], fla, f, b[N];
void dfs(int x) {
  if (vis[mp[x]]) return;
  vis[mp[x]] = vis[x] + 1;
  dfs(mp[x]);
}
int main() {
  int n, m, k, _, d;
  scanf("%d", &_);
  while (_--) {
    ans = fla = 0;
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      vis[i] = a[i] ^ 1;
      mp[i] = (i + n - d) % n;
    }
    for (int i = 0; i < n; i++) {
      if (!a[i]) {
        dfs(i);
      }
    }
    for (int i = 0; i < n; i++) {
      if (a[i] && vis[i] == 0) {
        fla = 1;
        break;
      }
      ans = max(ans, vis[i]);
    }
    if (fla)
      printf("-1\n");
    else
      printf("%d\n", ans - 1);
  }
  return 0;
}
