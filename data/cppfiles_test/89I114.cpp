#include <bits/stdc++.h>
using namespace std;
int leaf[200005], bud[200005], bn, bsize, cn[200005];
vector<int> ch[200005];
void dfs(int now, int pa) {
  int i, j, k, a, b, c, bcnt = 0, lcnt = 0;
  vector<int> vec;
  if (ch[now].size() <= 1) {
    leaf[now] = 1;
    return;
  }
  for (auto a : ch[now]) {
    if (a == pa) continue;
    cn[now]++;
    dfs(a, now);
    if (leaf[a]) lcnt++;
    if (bud[a]) {
      bcnt++;
    }
  }
  if (lcnt > 0)
    bud[now] = 1;
  else if (lcnt == 0)
    leaf[now] = 1;
  cn[now] -= bcnt;
}
void solve() {
  int i, j, k, a, b, c, n;
  scanf("%d", &n);
  bsize = bn = 0;
  for (i = 1; i <= n; i++) {
    bud[i] = leaf[i] = cn[i] = 0;
    ch[i].clear();
  }
  for (i = 1; i < n; i++) {
    scanf("%d%d", &a, &b);
    ch[a].push_back(b);
    ch[b].push_back(a);
  }
  dfs(1, 0);
  for (i = 1; i <= n; i++) {
    bn += bud[i];
    if (bud[i]) {
      bsize += cn[i];
    }
  }
  if (bud[1] == 0)
    k = bsize - bn + 1;
  else
    k = bsize - bn + 1;
  printf("%d\n", k);
}
int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
}
