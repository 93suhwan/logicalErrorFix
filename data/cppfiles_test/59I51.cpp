#include <bits/stdc++.h>
using namespace std;
int a[1010];
int b[1010];
bool mark[1010];
int from[1010];
int cnt = 0;
vector<int> outgo[1010];
bool extendFlag = false;
int baseValue = 0;
void update(int x) {
  if (mark[x]) return;
  baseValue += b[x];
  mark[x] = true;
  cnt++;
  update(from[x]);
}
void dfs(int now, int str) {
  if (extendFlag) return;
  for (int i = 0; i < outgo[now].size(); i++) {
    int to = outgo[now][i];
    if (to == from[now]) continue;
    if (from[to] == -1) {
      if (mark[to] && mark[now]) {
        from[to] = now;
        dfs(to, str);
      } else if (mark[to] && !mark[now]) {
        update(now);
        extendFlag = true;
        return;
      } else if (a[to] < str) {
        from[to] = now;
        dfs(to, str + b[to]);
      }
    } else if (!mark[now]) {
      if (mark[to]) {
        extendFlag = true;
        update(now);
        return;
      } else if (a[to] < str) {
        update(to);
        update(now);
        extendFlag = true;
        return;
      }
    }
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 2; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 2; i <= n; i++) scanf("%d", &b[i]);
    for (int i = 1; i <= n; i++) outgo[i].clear();
    for (int i = 1; i <= m; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      outgo[u].push_back(v);
      outgo[v].push_back(u);
    }
    int l = 1, r = 1000000000;
    int ans = 1000000000;
    while (l <= r) {
      int mid = (l + r) >> 1;
      baseValue = mid;
      for (int i = 2; i <= n; i++) mark[i] = false;
      mark[1] = true;
      cnt = 1;
      while (true) {
        for (int i = 1; i <= n; i++) from[i] = -1;
        from[1] = 0;
        extendFlag = false;
        dfs(1, baseValue);
        if (!extendFlag) break;
      }
      if (cnt == n) {
        ans = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}
