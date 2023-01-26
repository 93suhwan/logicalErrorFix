#include <bits/stdc++.h>
using namespace std;
template <typename T>
void cmax(T& x, T y) {
  if (x < y) x = y;
}
template <typename T>
void cmin(T& x, T y) {
  if (x > y) x = y;
}
const int N = 1005, INF = 2e9;
int n, m, s, t, num = 1, a[N], d[N], h[N], cur[N], dis[N], vis[N];
struct E {
  int x, t, w, c;
} e[2 * N];
void add(int s, int t, int w, int c) { e[++num] = {h[s], t, w, c}, h[s] = num; }
bool spfa() {
  for (int i = (0); i <= (n + 1); i++) cur[i] = h[i], dis[i] = INF;
  queue<int> q;
  q.push(s), dis[s] = 0, vis[s] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop(), vis[u] = 0;
    for (int i = h[u]; i; i = e[i].x)
      if (e[i].w && dis[e[i].t] > dis[u] + e[i].c) {
        dis[e[i].t] = dis[u] + e[i].c;
        if (!vis[e[i].t]) q.push(e[i].t), vis[e[i].t] = 1;
      }
  }
  return dis[t] < 0;
}
int dfs(int u, int lim) {
  if (u == t) return lim;
  vis[u] = 1;
  int res = 0;
  for (int& i = cur[u]; i; i = e[i].x)
    if (!vis[e[i].t] && dis[e[i].t] == dis[u] + e[i].c) {
      int tmp = dfs(e[i].t, min(lim, e[i].w));
      res += tmp, lim -= tmp, e[i].w -= tmp, e[i ^ 1].w += tmp;
      if (lim == 0) break;
    }
  vis[u] = 0;
  return res;
}
int main() {
  scanf("%d%d", &n, &m), s = 0, t = n + 1;
  for (int i = (1); i <= (n); i++) {
    scanf("%d", &a[i]);
    add(s, i, 1, 0), add(i, s, 0, 0);
    add(i, t, 1, 0), add(t, i, 0, 0);
  }
  for (int i = (1); i <= (m); i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    add(x, y, INF, a[y] - a[x]), add(y, x, 0, a[x] - a[y]);
  }
  while (spfa()) dfs(s, INF);
  for (int i = (0); i <= (n + 1); i++) d[i] = -INF;
  d[0] = 0;
  for (int i = (1); i <= (n + 1); i++)
    for (int j = (0); j <= (n + 1); j++)
      if (d[j] != -INF)
        for (int k = h[j]; k; k = e[k].x) cmax(d[e[k].t], d[j] - e[k].c);
  for (int i = (1); i <= (n); i++) printf("%d ", a[i] + d[i]);
}
