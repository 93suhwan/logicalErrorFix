#include <bits/stdc++.h>
using namespace std;
using F = long long;
const F oo = 0x3f3f3f3f3f3f3f3f;
const int N = 1000 + 10, M = 2 * N;
struct Edge {
  int to, nxt;
  F f;
} e[M << 1];
int head[N], tot = 1, cur[N], vis[N];
F dep[N];
queue<int> q;
void clear() {
  memset(head, 0, sizeof(head)), memset(vis, 0, sizeof(vis)), tot = 1;
}
void adde(int u, int v, F w) { e[++tot] = Edge{v, head[u], w}, head[u] = tot; }
void fadd(int u, int v, F w) { adde(u, v, w), adde(v, u, 0); }
int bfs(int s, int t, int n) {
  for (int i = 1; i <= n; i++) cur[i] = head[i], dep[i] = oo;
  q.push(s);
  dep[s] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = cur[u]; i; i = e[i].nxt) {
      int v = e[i].to;
      if (e[i].f && dep[v] > dep[u] + 1) {
        dep[v] = dep[u] + 1;
        q.push(v);
      }
    }
  }
  return dep[t] < oo;
}
F dfs(int u, int t, F in) {
  if (u == t || !in) return in;
  F f = 0, flow = 0;
  for (int &i = cur[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (dep[v] == dep[u] + 1 && (f = dfs(v, t, min(in, e[i].f))) > 0) {
      flow += f, in -= f, e[i].f -= f, e[i ^ 1].f += f;
      if (!in) break;
    }
  }
  if (!flow) dep[u] = -1;
  return flow;
}
F dinic(int s, int t, int n) {
  F flow = 0;
  while (bfs(s, t, n)) flow += dfs(s, t, oo);
  return flow;
}
void build(int u) {
  if (vis[u]) return;
  vis[u] = 1;
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (e[i].f) build(v);
  }
  return;
}
int a[N], b[N];
int first[N], second[N], arr[N], atot = 0;
int etot[N];
int n, m;
void divide(int l, int r, vector<int> v) {
  if (l == r) {
    for (int u : v) first[u] = arr[l];
    return;
  }
  int mid = (l + r) / 2;
  clear();
  int s = n + 1, t = n + 2;
  for (int first : v) {
    int delta =
        abs(arr[mid + 1] - second[first]) - abs(arr[mid] - second[first]);
    delta = -delta;
    if (delta < 0)
      fadd(first, t, -delta);
    else
      fadd(s, first, delta);
    etot[first] = tot - 1;
  }
  vector<int> ls, rs;
  for (int i = 1; i <= m; i++) {
    if (etot[a[i]] && etot[b[i]]) {
      fadd(a[i], b[i], oo);
    }
  }
  dinic(s, t, n + 2);
  build(s);
  for (int first : v) {
    int delta =
        abs(arr[mid + 1] - second[first]) - abs(arr[mid] - second[first]);
    delta = -delta;
    if (vis[first])
      rs.push_back(first);
    else
      ls.push_back(first);
    etot[first] = 0;
  }
  divide(l, mid, ls), divide(mid + 1, r, rs);
  return;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> second[i], arr[++atot] = second[i];
  sort(arr + 1, arr + atot + 1);
  atot = unique(arr + 1, arr + atot + 1) - (arr + 1);
  for (int i = 1; i <= m; i++) cin >> a[i] >> b[i];
  vector<int> v;
  for (int i = 1; i <= n; i++) v.emplace_back(i);
  divide(1, atot, v);
  for (int i = 1; i <= n; i++) cout << first[i] << " ";
  cout << endl;
  return 0;
}
