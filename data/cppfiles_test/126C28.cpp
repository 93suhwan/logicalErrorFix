#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int GRAPH_SIZE = 1050;
int pin[GRAPH_SIZE], s = 0, t = GRAPH_SIZE - 1;
long long dep[GRAPH_SIZE];
struct EDGE {
  int u, v;
  long long c;
};
vector<EDGE> e;
vector<int> each[GRAPH_SIZE];
bool bfs() {
  queue<int> Q;
  Q.push(s);
  while (!Q.empty()) {
    int now = Q.front();
    Q.pop();
    for (auto it : each[now]) {
      int next = e[it].v;
      if (e[it].c)
        if (dep[next] > dep[now] + 1) {
          dep[next] = dep[now] + 1;
          Q.push(next);
        }
    }
  }
  return dep[t] != INF;
}
long long dfs(int now, long long flow) {
  if (now == t) {
    return flow;
  }
  for (int& i = pin[now]; i < each[now].size(); i++) {
    int it = each[now][i];
    if (e[it].c && dep[e[it].v] == dep[now] + 1) {
      long long tmp;
      if (tmp = dfs(e[it].v, min(flow, e[it].c))) {
        e[it].c -= tmp;
        e[it ^ 1].c += tmp;
        return tmp;
      }
    }
  }
  return 0ll;
}
long long Dinic() {
  long long max_flow = 0;
  for (int i = 0; i < GRAPH_SIZE; ++i) {
    dep[i] = INF;
  }
  dep[s] = 0;
  while (bfs()) {
    for (int i = 0; i < GRAPH_SIZE; ++i) {
      pin[i] = 0;
    }
    long long tmp;
    while (tmp = dfs(s, INF)) {
      max_flow += tmp;
    }
    for (int i = 0; i < GRAPH_SIZE; ++i) {
      dep[i] = INF;
    }
    dep[s] = 0;
  }
  return max_flow;
}
void make_edge(int U, int V, long long C) {
  EDGE tmp;
  tmp.u = U;
  tmp.v = V;
  tmp.c = C;
  e.push_back(tmp);
  each[U].push_back(e.size() - 1);
  swap(tmp.u, tmp.v);
  tmp.c = 0;
  e.push_back(tmp);
  each[V].push_back(e.size() - 1);
}
void init() {
  e.clear();
  for (int i = 0; i < GRAPH_SIZE; ++i) {
    each[i].clear();
  }
}
int a[1001];
vector<pair<int, int> > edge;
int answer[1001];
vector<int> b;
int ans[1001];
bool in[GRAPH_SIZE];
void tour(int now) {
  in[now] = 1;
  for (auto it : each[now]) {
    if (e[it].c && !in[e[it].v]) {
      tour(e[it].v);
    }
  }
}
void solve(vector<int> v, int l, int r) {
  if (l == r || v.empty()) {
    for (auto it : v) ans[it] = b[l];
    return;
  }
  memset(in, 0, sizeof(in));
  for (auto it : v) in[it] = 1;
  init();
  int mid = (l + r) / 2;
  for (auto it : v) {
    make_edge(s, it, (long long)(1e13) + abs(b[mid + 1] - a[it]));
    make_edge(it, t, (long long)(1e13) + abs(b[mid] - a[it]));
  }
  for (auto it : edge) {
    int u, v;
    tie(u, v) = it;
    if (in[u] && in[v]) make_edge(v, u, INF);
  }
  Dinic();
  memset(in, 0, sizeof(in));
  tour(s);
  vector<int> L, R;
  for (auto it : e) {
    int u, v;
    u = it.u;
    v = it.v;
    if (in[u] && !in[v]) {
      if (u == s) {
        R.push_back(v);
      }
      if (v == t) {
        L.push_back(u);
      }
    }
  }
  sort(L.begin(), L.end());
  L.erase(unique(L.begin(), L.end()), L.end());
  sort(R.begin(), R.end());
  R.erase(unique(R.begin(), R.end()), R.end());
  solve(L, l, mid);
  solve(R, mid + 1, r);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    edge.push_back(make_pair(u, v));
  }
  for (int i = 1; i <= n; ++i) b.push_back(a[i]);
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  vector<int> v;
  for (int i = 1; i <= n; ++i) v.push_back(i);
  solve(v, 0, b.size() - 1);
  for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
