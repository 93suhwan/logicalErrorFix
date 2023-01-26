#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int nega = 1;
  while (!isdigit(ch)) {
    if (ch == '-') nega = -1;
    ch = getchar();
  }
  int ans = 0;
  while (isdigit(ch)) {
    ans = ans * 10 + ch - 48;
    ch = getchar();
  }
  if (nega == -1) return -ans;
  return ans;
}
void print(vector<int> x) {
  for (int i = 0; i < (int)x.size(); i++)
    printf("%d%c", x[i], " \n"[i == (int)x.size() - 1]);
}
int d[55], used[55], e[55][55], w[55][55], n, k;
int vis[55][55];
int getid(int x, int y) { return (x - 1) * n + y; }
vector<pair<int, int> > G[55 * 55];
int dis[55 * 55], eg[55 * 55], fr[55 * 55], inq[55 * 55], q[55 * 55 * 55],
    ok[55][55], ql, qr;
int fa[55];
int find(int u) { return fa[u] == u ? u : fa[u] = find(fa[u]); }
int append() {
  for (int i = 1; i <= n * n + 2; i++) G[i].clear(), dis[i] = 0x3f3f3f3f;
  int s = n * n + 1, t = n * n + 2;
  dis[s] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      if (!vis[i][j]) continue;
      if (ok[i][j]) continue;
      vis[i][j] = 0;
      for (int c = 1; c <= n; c++) fa[c] = c;
      for (int k = 1; k <= n; k++)
        for (int c = k + 1; c <= n; c++)
          if (vis[k][c]) fa[find(k)] = find(c);
      vis[i][j] = 1;
      for (int k = 1; k <= n; k++)
        for (int c = k + 1; c <= n; c++)
          if (!vis[k][c] && !ok[k][c]) {
            if (find(k) != find(c))
              G[getid(i, j)].emplace_back(getid(k, c), w[k][c]);
          }
    }
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      if (!vis[i][j]) continue;
      if (ok[i][j]) continue;
      used[i]--, used[j]--;
      for (int k = 1; k <= n; k++)
        for (int c = k + 1; c <= n; c++)
          if (!vis[k][c] && !ok[k][c]) {
            if (used[k] < d[k] && used[c] < d[c])
              G[getid(k, c)].emplace_back(getid(i, j), -w[i][j]);
          }
      used[i]++, used[j]++;
    }
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (vis[i][j]) fa[find(i)] = find(j);
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (!vis[i][j] && !ok[i][j]) {
        if (find(i) != find(j)) G[s].emplace_back(getid(i, j), w[i][j]);
      }
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (!vis[i][j] && !ok[i][j]) {
        if (used[i] < d[i] && used[j] < d[j]) G[getid(i, j)].emplace_back(t, 0);
      }
  ql = qr = 1, q[1] = s, eg[s] = 0;
  while (ql <= qr) {
    int u = q[ql++];
    inq[u] = 0;
    for (auto [v, w] : G[u]) {
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        fr[v] = u;
        if (!inq[v]) inq[v] = 1, q[++qr] = v;
      }
    }
  }
  int tmp = t;
  while (tmp != s) {
    tmp = fr[tmp];
    if (tmp == s) break;
    int i = (tmp - 1) / n + 1, j = tmp - (i - 1) * n;
    if (vis[i][j])
      used[i]--, used[j]--;
    else
      used[i]++, used[j]++;
    vis[i][j] ^= 1;
  }
  return dis[t];
}
int tu[55], tv[55];
signed main() {
  cin >> n >> k;
  for (int i = 1; i <= k; i++) d[i] = read();
  for (int i = k + 1; i <= n; i++) d[i] = n;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) e[i][j] = w[i][j] = read();
  int ans = 0x3f3f3f3f, cnt = 0;
  for (int i = 1; i <= k; i++)
    for (int j = i + 1; j <= k; j++)
      tu[cnt] = i, tv[cnt++] = j, w[i][j] = 10000, ok[i][j] = 1;
  for (int i = 0; i < 1 << (k * (k - 1) / 2); i++) {
    for (int j = 1; j <= k; j++) fa[j] = j;
    int ok = 1;
    int res = 0;
    for (int j = 0; j < k * (k - 1) / 2; j++) {
      if (i >> j & 1) {
        int u = tu[j], v = tv[j];
        if (find(u) == find(v)) ok = 0;
        fa[find(u)] = find(v);
        res += e[u][v];
      }
    }
    if (!ok) continue;
    memset(vis, 0, sizeof(vis)), memset(used, 0, sizeof(used));
    int pop = 0;
    for (int j = 0; j < k * (k - 1) / 2; j++) {
      if (i >> j & 1) {
        int u = tu[j], v = tv[j];
        vis[u][v] = 1, used[u]++, used[v]++;
        pop++;
      }
    }
    for (int j = 1; j <= k; j++)
      if (used[j] > d[j]) ok = 0;
    if (!ok) continue;
    for (int i = pop + 1; i < n; i++) {
      res += append();
    }
    ans = min(ans, res);
  }
  cout << ans << endl;
  return 0;
}
