#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
char s[N], ans[N * 2];
int box[26], node[N], flag[N], fa[N][25];
int l[N], r[N], nex[N], cnt = 0;
void dfs(int x) {
  if (!x) return;
  for (int i = 1; i <= 20; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1];
  dfs(l[x]);
  ans[++cnt] = s[x];
  node[cnt] = x;
  dfs(r[x]);
}
void floodfill(int x) {
  if (!x) return;
  if (flag[x] != 0) return;
  flag[x] = -1;
  floodfill(l[x]);
  floodfill(r[x]);
}
int getans(int x) {
  if (flag[x] == 1 || x == 0) return 0;
  return getans(fa[x][0]) + 1;
}
void DFS(int x) {
  if (!x) return;
  DFS(l[x]);
  ans[++cnt] = s[x];
  if (flag[x] == 1) ans[++cnt] = s[x];
  DFS(r[x]);
}
int getfa(int x, int y) {
  for (int i = 20; i >= 0; i--)
    if (y >= (1 << i)) {
      x = fa[x][i];
      y -= (1 << i);
    }
  return x;
}
int main() {
  int n, m;
  cin >> n >> m;
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &l[i], &r[i]);
    fa[l[i]][0] = fa[r[i]][0] = i;
  }
  fa[0][0] = 0;
  flag[0] = 1;
  dfs(1);
  memset(nex, 0x3f, sizeof(nex));
  memset(box, 0x3f, sizeof(box));
  for (int i = n; i >= 1; i--) {
    box[ans[i] - 'a'] = i;
    for (int j = 0; j <= 25; j++) {
      if (j != ans[i] - 'a') nex[i] = min(nex[i], box[j]);
    }
  }
  for (int i = 1; i <= cnt; i++) {
    if (flag[node[i]] != 0) continue;
    if (nex[i] == 0x3f3f3f3f || ans[nex[i]] < ans[i]) {
      floodfill(node[i]);
      continue;
    }
    int val = getfa(node[i], m);
    if (flag[val]) {
      for (int j = node[i]; flag[j] == 0; j = fa[j][0]) {
        flag[j] = 1;
        m--;
      }
    } else
      floodfill(node[i]);
  }
  cnt = 0;
  DFS(1);
  for (int i = 1; i <= cnt; i++) printf("%c", ans[i]);
}
