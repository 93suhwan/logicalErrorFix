#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char ch = getchar();
  long long nega = 1;
  while (!isdigit(ch)) {
    if (ch == '-') nega = -1;
    ch = getchar();
  }
  long long ans = 0;
  while (isdigit(ch)) {
    ans = ans * 10 + ch - 48;
    ch = getchar();
  }
  if (nega == -1) return -ans;
  return ans;
}
void print(vector<long long> x) {
  for (long long i = 0; i < (long long)x.size(); i++)
    printf("%lld%c", x[i], " \n"[i == (long long)x.size() - 1]);
}
long long v[1005], ans[1005], vis[1005], n, m;
vector<long long> G[1005];
struct Edge {
  long long v, cap, nxt;
};
Edge edge[1005 * 512];
long long first[1005], dep[1005], cur[1005], ss, s, t;
void add(long long u, long long v, long long w) {
  edge[++ss] = (Edge){v, w, first[u]};
  first[u] = ss;
  edge[++ss] = (Edge){u, 0, first[v]};
  first[v] = ss;
}
bool bfs(long long siz) {
  for (long long i = 0; i < siz; i++) dep[i] = 0;
  dep[s] = 1, dep[t] = 0;
  queue<long long> q;
  q.push(s);
  while (!q.empty()) {
    long long u = q.front();
    q.pop();
    for (long long i = first[u]; i != 0; i = edge[i].nxt) {
      if (!edge[i].cap) continue;
      long long v = edge[i].v;
      if (!dep[v]) dep[v] = dep[u] + 1, q.push(v);
    }
  }
  return dep[t];
}
long long dfs(long long u, long long flow) {
  if (u == t || !flow) return flow;
  long long go = 0;
  for (long long &i = cur[u]; i != 0; i = edge[i].nxt) {
    long long v = edge[i].v;
    if (!edge[i].cap || dep[v] != dep[u] + 1) continue;
    long long r = dfs(v, min(flow, edge[i].cap));
    go += r, flow -= r;
    edge[i].cap -= r, edge[i ^ 1].cap += r;
    if (!flow) return go;
  }
  return go;
}
long long dinic(long long siz) {
  long long ans = 0;
  while (bfs(siz)) {
    for (long long i = 0; i < siz; i++) cur[i] = first[i];
    cur[s] = first[s], cur[t] = first[t];
    ans += dfs(s, 0x3f3f3f3f);
  }
  return ans;
}
void solve(long long l, long long r, vector<long long> cur) {
  if (cur.empty()) return;
  if (l == r) {
    for (long long i = 0; i < (long long)cur.size(); i++) ans[cur[i]] = l;
    return;
  }
  for (long long i = 0; i < (long long)cur.size(); i++) vis[cur[i]] = i;
  long long mid = (l + r) / 2;
  ss = 1;
  for (long long i = 0; i < (long long)cur.size(); i++) {
    long long val = v[cur[i]];
    long long v1 = abs(val - mid), v2 = abs(val - mid - 1);
    if (v1 <= v2)
      add(i, t, v2 - v1);
    else
      add(s, i, v1 - v2);
  }
  for (long long i = 0; i < (long long)cur.size(); i++) {
    long long u = cur[i];
    for (long long j = 0; j < (long long)G[u].size(); j++) {
      long long v = G[u][j];
      if (vis[v] != -1) add(vis[u], vis[v], 0x3f3f3f3f3f3f3f3f);
    }
  }
  dinic(cur.size());
  for (long long i = 0; i < (long long)cur.size(); i++) first[i] = 0;
  first[s] = first[t] = 0;
  for (long long i = 0; i < (long long)cur.size(); i++) vis[cur[i]] = -1;
  vector<long long> L, R;
  for (long long i = 0; i < (long long)cur.size(); i++) {
    if (!dep[i])
      L.push_back(cur[i]);
    else
      R.push_back(cur[i]);
  }
  solve(l, mid, L), solve(mid + 1, r, R);
}
signed main() {
  memset(vis, -1, sizeof(vis));
  cin >> n >> m;
  s = n + 1, t = n + 2;
  for (long long i = 1; i <= n; i++) v[i] = read();
  for (long long i = 1; i <= m; i++) {
    long long u = read(), v = read();
    G[u].push_back(v);
  }
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) v[i] = i + 1;
  solve(1, 0x3f3f3f3f, v);
  for (long long i = 1; i <= n; i++) printf("%lld%c", ans[i], " \n"[i == n]);
  return 0;
}
