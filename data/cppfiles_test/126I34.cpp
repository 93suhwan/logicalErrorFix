#include <bits/stdc++.h>
using namespace std;
template <class T>
bool checkmax(T &a, T b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
bool checkmin(T &a, T b) {
  return b < a ? a = b, 1 : 0;
}
const int N = 1010;
const long long inf = 1000000000000000;
namespace dinic {
int all;
const int M = 40010;
struct road {
  int nxt, to;
  long long w;
} r[M];
int head[N], cnt;
void add(int u, int v, long long w) {
  r[++cnt] = (road){head[u], v, w};
  head[u] = cnt;
  r[++cnt] = (road){head[v], u, 0};
  head[v] = cnt;
}
int dis[N], cur[N];
queue<int> q;
bool bfs(int s, int t) {
  for (int i = 1; i <= all; i++) dis[i] = 0, cur[i] = head[i];
  dis[s] = 1;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = head[u]; i; i = r[i].nxt)
      if (r[i].w) {
        int v = r[i].to;
        if (!dis[v]) dis[v] = dis[u] + 1, q.push(v);
      }
  }
  return dis[t];
}
long long dfs(int u, int t, long long flow = inf) {
  if (u == t || !flow) return flow;
  long long res = 0;
  for (int &i = cur[u]; i; i = r[i].nxt) {
    int v = r[i].to;
    long long f;
    if (dis[v] == dis[u] + 1 && (f = dfs(v, t, min(flow, r[i].w)))) {
      flow -= f;
      res += f;
      r[i].w -= f;
      r[i ^ 1].w += f;
      if (!flow) break;
    }
  }
  return res;
}
long long work(int s, int t) {
  long long res = 0;
  while (bfs(s, t)) res += dfs(s, t);
  return res;
}
void init(int n) {
  for (int i = 1; i <= n; i++) head[i] = cur[i] = 0;
  cnt = 1;
  all = n;
}
}  // namespace dinic
using dinic::add;
using dinic::work;
vector<int> g[N];
int a[N], n, m;
void init() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1, x, y; i <= m; i++) scanf("%d%d", &x, &y), g[x].push_back(y);
}
int l[N], r[N];
void solve() {
  int s = n + 1, t = n + 2;
  for (int i = 1; i <= n; i++) l[i] = 0, r[i] = 1e9 + 1;
  long long ans = 0;
  for (int _ = 0; _ <= 40; _++) {
    dinic::init(t);
    for (int i = 1; i <= n; i++) add(s, i, abs(a[i] - l[i]));
    for (int i = 1; i <= n; i++) add(i, t, abs(a[i] - r[i]));
    for (int u = 1; u <= n; u++)
      for (int v : g[u])
        if (l[u] == l[v] && r[u] == r[v]) add(u, v, inf);
    ans = dinic::work(s, t);
    for (int i = 1; i <= n; i++)
      if (dinic::dis[i])
        l[i] = (l[i] + r[i]) >> 1;
      else
        r[i] = (l[i] + r[i] + 1) >> 1;
  }
  for (int i = 1; i <= n; i++) printf("%d ", dinic::dis[i] ? r[i] : l[i]);
}
int main() {
  init();
  solve();
  return 0;
}
