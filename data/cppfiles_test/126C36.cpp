#include <bits/stdc++.h>
using namespace std;
const int N = 10005, M = 100005;
using ll = long long;
const ll inf = LLONG_MAX >> 5;
vector<int> curp;
namespace FlowGraph {
int head[N], v[M], nxt[M], ptr, t;
ll w[M];
inline void padd_edge(int uu, int vv, ll ww) {
  v[ptr] = vv;
  w[ptr] = ww;
  nxt[ptr] = head[uu];
  head[uu] = ptr++;
}
int dis[N], cur[N];
bool bfs(int s, int t) {
  dis[s] = dis[t] = -1;
  for (auto &i : curp) dis[i] = -1;
  queue<int> q;
  q.push(s);
  dis[s] = 1;
  while (!q.empty()) {
    int nd = q.front();
    q.pop();
    for (int i = head[nd]; i != -1; i = nxt[i])
      if (w[i] && dis[v[i]] == -1) {
        dis[v[i]] = dis[nd] + 1;
        q.push(v[i]);
      }
  }
  return dis[t] != -1;
}
ll dfs(int pos, ll flow) {
  if (pos == t) return flow;
  ll tmp = flow;
  for (int &i = cur[pos]; i != -1; i = nxt[i])
    if (w[i] && dis[v[i]] == dis[pos] + 1) {
      ll fl = dfs(v[i], min(flow, w[i]));
      w[i] -= fl;
      w[i ^ 1] += fl;
      flow -= fl;
      if (!flow) break;
    }
  return tmp - flow;
}
inline void add_edge(int uu, int vv, ll ww) {
  padd_edge(uu, vv, ww);
  padd_edge(vv, uu, 0);
}
ll dinic(int ss, int tt) {
  t = tt;
  ll ret = 0;
  while (bfs(ss, tt)) {
    cur[ss] = head[ss];
    cur[tt] = head[tt];
    for (auto &i : curp) cur[i] = head[i];
    ret += dfs(ss, inf);
  }
  return ret;
}
};  // namespace FlowGraph
ll ans[N], a[N];
int n, m;
vector<int> v[N];
bool vis[N];
void solve(ll l, ll r, vector<int> p) {
  if (p.empty()) return;
  if (l == r) {
    for (auto &i : p) ans[i] = l;
    return;
  }
  curp = p;
  ll mid = (l + r) >> 1;
  int S = 0, T = n + 1;
  FlowGraph::head[S] = FlowGraph::head[T] = -1;
  for (auto &i : p) FlowGraph::head[i] = -1, vis[i] = 1;
  FlowGraph::ptr = 0;
  for (auto &i : p)
    if (a[i] <= mid)
      FlowGraph::add_edge(S, i, 1);
    else
      FlowGraph::add_edge(i, T, 1);
  for (auto &i : p)
    for (auto &j : v[i])
      if (vis[j]) FlowGraph::add_edge(i, j, inf);
  FlowGraph::dinic(S, T);
  for (auto &i : p) vis[i] = 0;
  vector<int> lp, rp;
  for (auto &i : p)
    if (FlowGraph::dis[i] != -1)
      lp.push_back(i);
    else
      rp.push_back(i);
  solve(l, mid, lp);
  solve(mid + 1, r, rp);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  vector<int> tt;
  for (int i = 1; i <= n; i++) cin >> a[i], tt.push_back(i);
  int t1, t2;
  for (int i = 1; i <= m; i++) {
    cin >> t1 >> t2;
    v[t2].push_back(t1);
  }
  solve(0, *max_element(a + 1, a + n + 1), tt);
  for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
  return 0;
}
