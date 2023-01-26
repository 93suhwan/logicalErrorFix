#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
int n, m, a[1005], z[1005], tmp[1005];
long long ans[1005];
bool vs[1005];
vector<int> vc[1005];
int cntE, hd[1005];
struct Edge {
  int v, nxt;
  long long w;
} e[1000005];
int S, T, dst[1005], cur[1005], q[1005];
void addE(int u, int v, long long w) {
  e[cntE] = (Edge){v, hd[u], w};
  hd[u] = cntE++;
  e[cntE] = (Edge){u, hd[v], 0};
  hd[v] = cntE++;
}
bool bfs(int S, int T) {
  memcpy(cur, hd, sizeof(cur));
  memset(dst, -1, sizeof(dst));
  dst[S] = 0;
  q[0] = 2;
  q[1] = 1;
  q[++q[1]] = S;
  while (q[0] <= q[1]) {
    int u = q[q[0]++];
    for (int i = hd[u], v; ~i; i = e[i].nxt) {
      v = e[i].v;
      if (e[i].w > 0 && dst[v] == -1) dst[v] = dst[u] + 1, q[++q[1]] = v;
    }
  }
  return dst[T] != -1;
}
long long dfs(int u, int T, long long nw) {
  if (u == T) return nw;
  int flw = 0;
  for (int i = cur[u], v; ~i; i = e[i].nxt) {
    long long t, w = e[i].w;
    v = e[i].v;
    cur[u] = i;
    if (w > 0 && dst[v] == dst[u] + 1 && (t = dfs(v, T, min(nw, w)))) {
      nw -= t;
      flw += t;
      e[i].w -= t;
      e[i ^ 1].w += t;
      if (!nw) break;
    }
  }
  return flw;
}
long long Dinic(int S, int T) {
  long long res = 0;
  while (bfs(S, T)) res += dfs(S, T, INF);
  return res;
}
void dfs(int u) {
  if (vs[u]) return;
  vs[u] = 1;
  for (int i = hd[u]; ~i; i = e[i].nxt)
    if (e[i].w > 0) dfs(e[i].v);
}
void slv(long long l, long long r, int l1, int r1) {
  if (l1 > r1) return;
  if (l == r) {
    for (int i = l1; i <= r1; ++i) ans[z[i]] = l;
    return;
  }
  int l2 = l1 - 1, r2 = r1 + 1;
  long long mid = l + (r - l) / 2;
  cntE = 0;
  memset(hd, -1, sizeof(hd));
  for (int i = l1; i <= r1; ++i) {
    if (a[z[i]] <= mid)
      addE(z[i], T, 1);
    else
      addE(S, z[i], 1);
    for (auto j : vc[z[i]]) addE(z[i], j, INF);
  }
  Dinic(S, T);
  vs[S] = vs[T] = 0;
  for (int i = l1; i <= r1; ++i) vs[z[i]] = 0;
  dfs(S);
  for (int i = l1; i <= r1; ++i)
    if (!vs[z[i]])
      tmp[++l2] = z[i];
    else
      tmp[--r2] = z[i];
  for (int i = l1; i <= r1; ++i) z[i] = tmp[i];
  slv(l, mid, l1, l2);
  slv(mid + 1, r, r2, r1);
}
int main() {
  scanf("%d %d", &n, &m);
  S = n + 1;
  T = S + 1;
  for (int i = 1; i <= n; ++i) z[i] = i, scanf("%d", &a[i]);
  for (int i = 1, u, v; i <= m; ++i) scanf("%d %d", &u, &v), vc[u].push_back(v);
  slv(-1e15, 1e15, 1, n);
  for (int i = 1; i <= n; ++i) printf("%lld ", ans[i]);
  return 0;
}
