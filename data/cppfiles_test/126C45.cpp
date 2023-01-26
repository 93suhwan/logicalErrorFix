#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
struct strongly_connected_components {
  vector<vector<int>> ans;
  vector<int> scc;
  void dfs1(vector<vector<int>> &E, vector<int> &t, vector<bool> &used, int v) {
    for (int w : E[v]) {
      if (!used[w]) {
        used[w] = true;
        dfs1(E, t, used, w);
      }
    }
    t.push_back(v);
  }
  void dfs2(vector<vector<int>> &E2, vector<bool> &used2, int v) {
    ans.back().push_back(v);
    for (int w : E2[v]) {
      if (!used2[w]) {
        used2[w] = true;
        dfs2(E2, used2, w);
      }
    }
  }
  strongly_connected_components(vector<vector<int>> &E) {
    int N = E.size();
    vector<vector<int>> E2(N);
    for (int i = 0; i < N; i++) {
      for (int j : E[i]) {
        E2[j].push_back(i);
      }
    }
    vector<int> t;
    vector<bool> used(N, false);
    for (int i = 0; i < N; i++) {
      if (!used[i]) {
        used[i] = true;
        dfs1(E, t, used, i);
      }
    }
    reverse(t.begin(), t.end());
    vector<bool> used2(N, false);
    scc = vector<int>(N);
    int cnt = 0;
    for (int i = 0; i < N; i++) {
      if (!used2[t[i]]) {
        used2[t[i]] = true;
        ans.push_back(vector<int>());
        dfs2(E2, used2, t[i]);
        for (int j : ans.back()) {
          scc[j] = cnt;
        }
        cnt++;
      }
    }
  }
  int operator[](int k) { return scc[k]; }
  int size() { return ans.size(); }
};
template <typename Cap, typename Cost>
struct primal_dual {
  struct edge {
    int to, rev;
    Cap cap;
    Cost cost;
    edge(int to, int rev, Cap cap, Cost cost)
        : to(to), rev(rev), cap(cap), cost(cost) {}
  };
  int N;
  vector<vector<edge>> G;
  primal_dual() {}
  primal_dual(int N) : N(N), G(N) {}
  void add_edge(int from, int to, Cap cap, Cost cost) {
    int id1 = G[from].size();
    int id2 = G[to].size();
    G[from].push_back(edge(to, id2, cap, cost));
    G[to].push_back(edge(from, id1, 0, -cost));
  }
  vector<Cost> min_cost_flow(int s, int t, Cap F) {
    Cap flow = 0;
    Cost cost = 0;
    vector<Cost> h(N, 0);
    while (flow < F) {
      vector<Cap> m(N, INF);
      vector<Cost> d(N, INF);
      vector<int> pv(N, -1);
      vector<int> pe(N, -1);
      vector<bool> used(N, false);
      priority_queue<pair<Cost, int>, vector<pair<Cost, int>>,
                     greater<pair<Cost, int>>>
          pq;
      pq.push(make_pair(0, s));
      d[s] = 0;
      while (!pq.empty()) {
        int v = pq.top().second;
        pq.pop();
        if (!used[v]) {
          used[v] = true;
          if (v == t) {
            break;
          }
          int cnt = G[v].size();
          for (int i = 0; i < cnt; i++) {
            int w = G[v][i].to;
            if (!used[w] && G[v][i].cap > 0) {
              Cost tmp = G[v][i].cost - h[w] + h[v];
              if (d[w] > d[v] + tmp) {
                d[w] = d[v] + tmp;
                m[w] = min(m[v], G[v][i].cap);
                pv[w] = v;
                pe[w] = i;
                pq.push(make_pair(d[w], w));
              }
            }
          }
        }
      }
      if (!used[t]) {
        break;
      }
      for (int i = 0; i < N; i++) {
        if (used[i]) {
          h[i] -= d[t] - d[i];
        }
      }
      Cap c = min(m[t], F - flow);
      for (int i = t; i != s; i = pv[i]) {
        G[pv[i]][pe[i]].cap -= c;
        G[i][G[pv[i]][pe[i]].rev].cap += c;
      }
      flow += c;
      cost += c * (-h[s]);
    }
    return h;
  }
};
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> E(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(v);
  }
  strongly_connected_components G(E);
  int V = G.size();
  vector<vector<int>> x(V);
  for (int i = 0; i < n; i++) {
    x[G[i]].push_back(a[i]);
  }
  vector<vector<int>> E2(V);
  for (int i = 0; i < n; i++) {
    for (int j : E[i]) {
      if (G[i] != G[j]) {
        E2[G[i]].push_back(G[j]);
      }
    }
  }
  primal_dual<long long, long long> G2(V + 3);
  vector<long long> b(V + 1, 0);
  for (int i = 0; i < V; i++) {
    sort(x[i].begin(), x[i].end());
    int cnt = x[i].size();
    for (int j = 0; j < cnt; j++) {
      G2.add_edge(V, i, 2, x[i][j]);
    }
    b[V] += cnt;
    b[i] -= cnt;
  }
  for (int i = 0; i < V; i++) {
    for (int j : E2[i]) {
      G2.add_edge(j, i, INF, 0);
    }
  }
  int sum = 0;
  for (int i = 0; i <= V; i++) {
    if (b[i] < 0) {
      G2.add_edge(i, V + 2, -b[i], 0);
    } else {
      sum += b[i];
      G2.add_edge(V + 1, i, b[i], 0);
    }
  }
  vector<long long> p = G2.min_cost_flow(V + 1, V + 2, n);
  for (int i = 0; i < n; i++) {
    cout << p[G[i]] - p[V];
    if (i < n - 1) {
      cout << ' ';
    }
  }
  cout << endl;
}
