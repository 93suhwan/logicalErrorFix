#include <bits/stdc++.h>
using namespace std;
vector<int> v[1010];
long long fa[1010], y[1010 * 1010], Y[1010 * 1010], A[1010 * 1010],
    B[1010 * 1010], f[1010 * 1010], p[1010 * 1010], id[1010 * 1010],
    newp[1010 * 1010], n, m, use[1010 * 1010], cur;
namespace MCMF {
int tot = 1;
int head[1010 * 1010], dep[1010 * 1010];
struct edge {
  int to, next, len;
} dat[500001];
void add_edge(int x, int y, int z) {
  dat[++tot] = (edge){y, head[x], z};
  head[x] = tot;
}
void Add_edge(int x, int y, int z) {
  add_edge(x, y, z);
  add_edge(y, x, 0);
}
int fuck[1010 * 1010], S, T;
queue<int> q;
int bfs() {
  for (int i = S; i <= T; i++) dep[i] = 0, fuck[i] = head[i];
  dep[S] = 1;
  q.push(S);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = head[x]; i; i = dat[i].next) {
      int t = dat[i].to;
      if (!dat[i].len || dep[t]) continue;
      dep[t] = dep[x] + 1;
      q.push(t);
    }
  }
  return dep[T];
}
int dfs(int x, int limit) {
  if (x == T) return limit;
  int sum = 0;
  for (int i = fuck[x]; i; i = dat[i].next) {
    fuck[x] = i;
    int t = dat[i].to;
    if (!dat[i].len || dep[t] != dep[x] + 1) continue;
    int hh = dfs(t, min(limit, dat[i].len));
    dat[i].len -= hh;
    dat[i ^ 1].len += hh;
    sum += hh;
    limit -= hh;
    if (!limit) return sum;
  }
  return sum;
}
int dinic() {
  int sum = 0;
  while (bfs()) {
    sum += dfs(S, 2e9);
  }
  return sum;
}
void init(int _S, int _T) {
  S = _S, T = _T;
  for (int i = S; i <= T; i++) head[i] = 0;
  tot = 1;
}
}  // namespace MCMF
void solve(long long L, long long R, int l, int r) {
  if (l > r) return;
  if (L == R) {
    for (int i = l; i <= r; i++) f[p[i]] = L;
    return;
  }
  long long mid = (L + R) >> 1;
  MCMF::init(0, r - l + 2);
  for (int i = l; i <= r; i++) id[p[i]] = i - l + 1;
  for (int i = l; i <= r; i++) {
    int x = p[i];
    if (y[x] > mid)
      MCMF::Add_edge(MCMF::S, id[x], 1);
    else
      MCMF::Add_edge(id[x], MCMF::T, 1);
    for (int j = 0; j < (int)v[x].size(); j++) {
      int t = v[x][j];
      if (id[t]) MCMF::Add_edge(id[x], id[t], 2e9);
    }
  }
  MCMF::dinic();
  int now1 = l - 1;
  for (int i = l; i <= r; i++) {
    if (!MCMF::dep[id[p[i]]]) newp[++now1] = p[i];
  }
  int now2 = now1;
  for (int i = l; i <= r; i++) {
    if (MCMF::dep[id[p[i]]]) newp[++now2] = p[i];
  }
  for (int i = l; i <= r; i++) p[i] = newp[i], id[p[i]] = 0;
  solve(L, mid, l, now1);
  solve(mid + 1, R, now1 + 1, r);
}
long long a[1010], b[1010];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) scanf("%lld", &y[i]);
  for (int i = 1; i <= m; i++) {
    int X, YY;
    scanf("%d%d", &X, &YY);
    v[X].push_back(YY);
  }
  for (int i = 1; i <= n; i++) p[i] = i;
  solve(-1e15, 1e15, 1, n);
  for (int i = 1; i <= n; i++) printf("%lld ", f[i]);
}
