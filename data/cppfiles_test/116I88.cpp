#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<int> g[300010], con;
vector<int> unz;
int d[300010], vis[300010];
int a[300010], l[300010], tot;
int f[300010];
void dfs(int u) {
  vis[u] = true, con.push_back(u);
  for (int v : g[u])
    if (!vis[v]) dfs(v);
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    int c;
    scanf("%d", &c);
    int pre = -1, now = -1;
    while (c--) {
      scanf("%d", &now);
      if (pre != -1)
        g[pre].push_back(now), g[now].push_back(pre), d[pre]++, d[now]++;
      pre = now;
    }
  }
  for (int i = 1; i <= k; i++)
    if (!vis[i]) {
      con.clear();
      dfs(i);
      int c1 = 0, c2 = 0;
      for (int x : con) c1 += (d[x] == 1), c2 += (d[x] == 2);
      if (con.size() == 1 || (c1 + c2 == con.size() && c1 == 2))
        a[con.size()]++;
    }
  for (int i = 1; i <= k; i++)
    if (a[i] > 0) unz.push_back(i);
  f[0] = 1;
  for (int i = 1; i <= m; i++)
    for (int j : unz)
      if (i >= j) f[i] = (f[i] + 1ll * f[i - j] * a[j] % 998244353) % 998244353;
  printf("%d\n", f[m]);
  return 0;
}
