#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7, M = 2007;
const int inf = 1e9;
int ehd[N], ev[N], enx[N], eid = 1;
int ew[N];
void eadd(int u, int v, int w) {
  ++eid, enx[eid] = ehd[u], ev[eid] = v, ew[eid] = w, ehd[u] = eid;
}
void add(int u, int v, int w) { eadd(u, v, w), eadd(v, u, 0); }
int dis[N], cur[N], s, t, top;
bool bfs() {
  for (int i = (1); i <= (top); ++i) dis[i] = inf, cur[i] = ehd[i];
  queue<int> q;
  dis[s] = 0, q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = ehd[u]; i; i = enx[i])
      if (ew[i] && dis[ev[i]] > dis[u] + 1)
        dis[ev[i]] = dis[u] + 1, q.push(ev[i]);
  }
  return dis[t] < inf;
}
int dfs(int x, int flow) {
  if (x == t) return flow;
  int F = flow;
  for (int i = cur[x]; i; i = cur[x] = enx[i])
    if (ew[i] && dis[ev[i]] == dis[x] + 1) {
      int sF = dfs(ev[i], min(ew[i], F));
      ew[i] -= sF, ew[i ^ 1] += sF, F -= sF;
      if (!F) break;
    }
  return flow - F;
}
void dinic() {
  while (bfs()) dfs(s, inf);
}
int n, m, ns[N], v[N], A[N];
long long ans;
bool E[M][M];
void Div(int L, int R, int sl, int sr) {
  if (sl > sr) return;
  if (L == R) {
    for (int i = (sl); i <= (sr); ++i) ns[A[i]] = L;
    return;
  }
  int mid = (L + R) >> 1, topo = sl - 1;
  eid = 1, top = sr - sl + 1, s = ++top, t = ++top;
  for (int i = (sl); i <= (sr); ++i)
    for (int j = (sl); j <= (sr); ++j)
      if (E[A[i]][A[j]]) add(i - sl + 1, j - sl + 1, inf);
  for (int i = (sl); i <= (sr); ++i) {
    int c = abs(mid + 1 - v[A[i]]) - abs(mid - v[A[i]]);
    if (c > 0)
      add(s, i - sl + 1, c);
    else
      add(i - sl + 1, t, -c);
  }
  dinic();
  for (int i = (1); i <= (sr - sl + 1); ++i)
    if (dis[i] < inf) swap(A[++topo], A[sl + i - 1]);
  for (int i = (1); i <= (top); ++i) ehd[i] = 0;
  top = 0, Div(L, mid, sl, topo), Div(mid + 1, R, topo + 1, sr);
}
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = (1); i <= (n); ++i) cin >> v[i];
  for (int i = (1); i <= (m); ++i) {
    int u, v;
    cin >> u >> v;
    E[v][u] = true;
  }
  for (int i = (1); i <= (n); ++i) A[i] = i;
  Div(0, inf, 1, n);
  for (int i = (1); i <= (n); ++i) cout << ns[i] << ' ';
  cout << '\n';
  return 0;
}
