#include <bits/stdc++.h>
using namespace std;
const int N = 5007;
int n, m, q;
long long w[N];
int ehd[N], ev[N], enx[N], ew[N], eid;
int ord[N], tp, Fa[N];
void eadd(int u, int v, int w) {
  ++eid, enx[eid] = ehd[u], ev[eid] = v, ew[eid] = w, ehd[u] = eid;
}
long long dis[N];
bool vis[N];
void Dij() {
  memset(dis, 0x3f, sizeof(dis));
  priority_queue<pair<long long, int> > q;
  q.push({0, 1}), dis[1] = 0;
  while (!q.empty()) {
    int u = q.top().second;
    q.pop();
    ord[++tp] = u;
    if (vis[u]) continue;
    vis[u] = true;
    for (int i = ehd[u]; i; i = enx[i])
      if (dis[ev[i]] > dis[u] + ew[i])
        dis[ev[i]] = dis[u] + ew[i], q.push({-dis[ev[i]], ev[i]});
  }
  Fa[1] = -1;
  for (int u = (2); u <= (n); ++u) {
    for (int i = ehd[u]; i; i = enx[i])
      if (dis[ev[i]] + ew[i] == dis[u]) {
        if (!Fa[u])
          Fa[u] = ev[i];
        else
          Fa[u] = -1;
      }
    if (Fa[u] == 1) Fa[u] = 0;
  }
}
inline long long query() {
  long long ns = 0;
  for (int i = (2); i <= (n); ++i)
    if (Fa[i] != -1) {
      long long ret = 1e18;
      for (int j = (1); j <= (i - 1); ++j)
        if (dis[ord[j]] < dis[ord[i]] && ord[j] != Fa[ord[i]])
          ret = min(ret, w[ord[j]]);
      ns += ret;
    }
  return ns;
}
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> q;
  for (int i = (1); i <= (n); ++i) cin >> w[i];
  for (int i = (1); i <= (m); ++i) {
    int u, v, d;
    cin >> u >> v >> d;
    eadd(u, v, d);
    eadd(v, u, d);
  }
  Dij();
  cout << query() << '\n';
  while (q--) {
    int x, k;
    cin >> x >> k;
    w[x] += k;
    cout << query() << '\n';
  }
  return 0;
}
