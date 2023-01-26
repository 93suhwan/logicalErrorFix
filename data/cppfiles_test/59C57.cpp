#include <bits/stdc++.h>
using std::bitset;
using std::pair;
using std::priority_queue;
using std::vector;
const int N = 1005;
int T, n, m, a[N], b[N], id[N][2];
long long dis[N][2], tot, tota;
bitset<N> st[N][2];
priority_queue<pair<long long, int> > q;
vector<int> e[N], eid[N];
void dij(int s, long long k) {
  for (int i = 1; i <= n; ++i) {
    dis[i][0] = dis[i][1] = 0;
    id[i][0] = id[i][1] = 0;
    st[i][0].reset(), st[i][1].reset();
  }
  dis[s][0] = k;
  st[s][0].set(s);
  q.push(std::make_pair(k, s << 1));
  while (!q.empty()) {
    auto tmp = q.top();
    q.pop();
    int u = tmp.second >> 1, t = tmp.second & 1;
    if (dis[u][t] != tmp.first) continue;
    for (int i = 0; i < e[u].size(); ++i)
      if (eid[u][i] != id[u][t]) {
        int v = e[u][i], first = eid[u][i];
        if (!st[u][t].test(v) && a[v] >= dis[u][t]) continue;
        if (dis[v][0] < dis[u][t] + (st[u][t][v] ? 0 : b[v])) {
          if (id[v][0] != first) {
            id[v][1] = id[v][0];
            dis[v][1] = dis[v][0];
            st[v][1] = st[v][0];
          }
          id[v][0] = first;
          dis[v][0] = dis[u][t] + (st[u][t][v] ? 0 : b[v]);
          st[v][0] = st[u][t];
          st[v][0].set(v);
          q.push(std::make_pair(dis[v][0], v << 1));
        } else if (id[v][0] != first &&
                   dis[v][1] < dis[u][t] + (st[u][t][v] ? 0 : b[v])) {
          id[v][1] = first;
          dis[v][1] = dis[u][t] + (st[u][t][v] ? 0 : b[v]);
          st[v][1] = st[u][t];
          st[v][1].set(v);
          q.push(std::make_pair(dis[v][1], v << 1 | 1));
        }
      }
  }
}
bool chk(long long k) {
  dij(1, k);
  for (int i = 1; i <= n; ++i)
    if (dis[i][0] == tot + k) return 1;
  return 0;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    for (int i = 1; i <= n; ++i) e[i].clear(), eid[i].clear();
    scanf("%d%d", &n, &m);
    tot = tota = 0;
    for (int i = 2; i <= n; ++i) scanf("%d", a + i), tota += a[i];
    for (int i = 2; i <= n; ++i) scanf("%d", b + i), tot += b[i];
    for (int i = 1, first, second; i <= m; ++i) {
      scanf("%d%d", &first, &second);
      e[first].push_back(second), e[second].push_back(first);
      eid[first].push_back(i), eid[second].push_back(i);
    }
    long long l = 0, r = tota + 1;
    while (l < r) {
      long long mid = (l + r) >> 1;
      if (chk(mid))
        r = mid;
      else
        l = mid + 1;
    }
    printf("%lld\n", l);
  }
  return 0;
}
