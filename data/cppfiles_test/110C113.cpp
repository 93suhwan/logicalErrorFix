#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, M = N;
struct Graph {
  struct Edge {
    int nxt, to;
    long long w;
  } e[M << 1];
  int head[N], cnt = 1, in[N];
  void add(int x, int y, long long w) {
    e[++cnt].nxt = head[x], head[x] = cnt, e[cnt].to = y, e[cnt].w = w, in[y]++;
  }
  void init(int MAXN) {
    memset(head, 0, sizeof(int) * (MAXN + 1));
    memset(in, 0, sizeof(int) * (MAXN + 1));
    cnt = 1;
  }
} gr;
int n, m;
vector<int> son[N];
struct Tarjan {
  int idx;
  int col[N], cnt[N];
  int dfn[N], low[N];
  bool vis[N];
  vector<int> stac;
  void dfs(int now, Graph& graph) {
    low[now] = dfn[now] = ++idx;
    stac.push_back(now), vis[now] = 1;
    for (int i = graph.head[now]; i; i = graph.e[i].nxt) {
      int j = graph.e[i].to;
      if (!dfn[j]) {
        dfs(j, graph);
        low[now] = min(low[now], low[j]);
      } else if (vis[j])
        low[now] = min(low[now], dfn[j]);
    }
    if (dfn[now] == low[now]) {
      while (1) {
        col[stac.back()] = now;
        cnt[stac.back()]++;
        vis[stac.back()] = 0;
        if (stac.back() == now) {
          stac.pop_back();
          break;
        }
        stac.pop_back();
      }
    }
  }
  void init(Graph& graph, int MAXN) {
    idx = 0;
    memset(col, 0, sizeof(int) * (MAXN + 1));
    memset(cnt, 0, sizeof(int) * (MAXN + 1));
    memset(dfn, 0, sizeof(int) * (MAXN + 1));
    memset(low, 0, sizeof(int) * (MAXN + 1));
    for (int i = 1; i <= MAXN; i++)
      if (!dfn[i]) dfs(i, graph);
  }
} tarjan;
void solve() {
  cin >> n;
  gr.init(n);
  for (int i = 1; i <= n; i++) son[i].clear();
  vector<int> du(n + 1);
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    du[i] = k;
    for (int j = 1; j <= k; j++) {
      int x;
      cin >> x;
      son[x].push_back(i);
      gr.add(x, i, 1);
    }
  }
  tarjan.init(gr, n);
  set<int> st;
  for (int i = 1; i <= n; i++) {
    if (tarjan.col[i] != i) {
      cout << -1 << '\n';
      return;
    }
    if (du[i] == 0) st.insert(i);
  }
  int ans = 0;
  while (st.size()) {
    auto it = st.begin();
    while (it != st.end()) {
      int u = *it;
      for (auto sn : son[u]) {
        du[sn]--;
        if (du[sn] == 0) {
          st.insert(sn);
        }
      }
      st.erase(u);
      it = st.upper_bound(u);
    }
    ans++;
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int ttt = 1;
  cin >> ttt;
  for (int i = 1; i <= ttt; i++) solve();
  return 0;
}
