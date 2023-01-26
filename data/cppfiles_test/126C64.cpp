#include <bits/stdc++.h>
using namespace std;
int n, m, s, t, x, y, tot = 2, head[20001], cur[20001], dep[20001], l, r,
                      u[20001], r2;
long long w, ans[20001], aa[20001];
long long mn(long long x, long long y) { return (x > y ? y : x); }
struct f {
  int to, net;
  long long w;
} a[4000011];
void add(int x, int y, long long w) {
  a[tot].to = y, a[tot].w = w, a[tot].net = head[x], head[x] = tot++;
  return;
}
bool bfs() {
  memset(dep, -1, sizeof(dep));
  queue<int> u;
  u.push(s);
  dep[s] = 0;
  while (u.size()) {
    int x = u.front();
    u.pop();
    for (int j = head[x]; j; j = a[j].net) {
      if (a[j].w > 0 && dep[a[j].to] == -1) {
        u.push(a[j].to);
        dep[a[j].to] = dep[x] + 1;
      }
    }
  }
  return dep[t] != -1;
}
long long dfs(int d, long long in) {
  if (d == t) return in;
  long long out = 0;
  int uw = dep[d] + 1;
  for (int &j = cur[d]; j && in; j = a[j].net) {
    if (a[j].w <= 0 || dep[a[j].to] != uw) continue;
    long long s = dfs(a[j].to, mn(in, a[j].w));
    out += s, in -= s;
    a[j].w -= s, a[j ^ 1].w += s;
  }
  if (out == 0) {
    dep[d] = 0;
  }
  return out;
}
void Dinic() {
  while (bfs()) {
    memcpy(cur, head, sizeof(cur));
    while (1) {
      if (!dfs(s, 1e9)) break;
    }
  }
  return;
}
int newid[20000];
vector<int> edg[20000];
void solve(vector<int> V, long long l, long long r) {
  if (l == r) {
    for (int i = 0; i < V.size(); i++) ans[V[i]] = l;
    return;
  }
  if (!V.size()) return;
  n = V.size() + 1, s = 0, t = n, tot = 2;
  for (int i = 0; i < V.size(); i++) newid[V[i]] = i + 1;
  for (int i = 0; i <= n; i++) head[i] = 0;
  for (int i = 0; i < V.size(); i++) {
    int x = V[i];
    for (int j = 0; j < edg[x].size(); j++) {
      if (!newid[edg[x][j]]) continue;
      add(i + 1, newid[edg[x][j]], 1e9);
      add(newid[edg[x][j]], i + 1, 0);
    }
  }
  long long mid = l + r >> 1;
  for (int i = 0; i < V.size(); i++) {
    int u = V[i];
    if (mid < aa[u])
      add(s, i + 1, 1), add(i + 1, s, 0);
    else
      add(i + 1, t, 1), add(t, i + 1, 0);
  }
  Dinic();
  vector<int> LV, RV;
  for (int i = 0; i < V.size(); i++) {
    if (dep[i + 1] != -1)
      RV.push_back(V[i]);
    else
      LV.push_back(V[i]);
  }
  for (int i = 0; i < V.size(); i++) newid[V[i]] = 0;
  solve(LV, l, mid);
  solve(RV, mid + 1, r);
  return;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) scanf("%lld", &aa[i]);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    edg[x].push_back(y);
  }
  vector<int> U;
  for (int i = 1; i <= n; i++) U.push_back(i);
  solve(U, 1, 1e9);
  for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
  return 0;
}
