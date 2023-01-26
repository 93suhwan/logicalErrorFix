#include <bits/stdc++.h>
using namespace std;
const int N = 200010, M = 6000010;
int n, a[N], rt, tot;
map<int, int> mp;
int val[M];
vector<int> g[M];
int ans, ansx, ansy, S, T, cur;
bool vis[M];
int res, fa[M];
void dfs(int x, int fath, int dis, int *var) {
  vis[x] = true;
  if (x <= n && dis > cur) *var = x, cur = dis;
  for (int y : g[x])
    if (y != fath) dfs(y, x, dis + 1, var);
}
int getfa(int v) {
  int t = 0, x = mp[v];
  if (fa[x]) return fa[x];
  while ((1 << t) < v) t++;
  int w = (1 << t) - v;
  if (mp[w] == 0) tot++, mp[w] = tot, val[tot] = w;
  g[x].push_back(tot), g[tot].push_back(x);
  return fa[x] = w;
}
int main() {
  cin >> n, tot = n;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), mp[a[i]] = i, val[i] = a[i];
  sort(a + 1, a + n + 1), rt = a[1];
  for (int i = 2; i <= n; i++) {
    int x = a[i], y = rt;
    while (x != y) {
      if (x < y) swap(x, y);
      x = getfa(x);
    }
    rt = x;
  }
  ans = -1;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      cur = res = 0, dfs(i, 0, 0, &S);
      assert(res <= tot);
      cur = 0, dfs(S, 0, 0, &T);
      if (cur > ans) ans = cur, ansx = S, ansy = T;
    }
  printf("%d %d %d\n", ansx, ansy, cur);
  return 0;
}
