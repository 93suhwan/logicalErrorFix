#include <bits/stdc++.h>
using namespace std;
const int inf = 1000111222;
const int max_n = 1500011;
namespace mcmf {
const int infCapacity = 1000111222;
const int infCost = 1000111222;
const int max_v = 20011;
const int DIJKSTRA_N2 = 1;
const int DIJKSTRA_MLOGN = 2;
const int DIJKSTRA_MAXD = 3;
const int DIJKSTRA_TYPE = 2;
const bool NEGATIVE_COST_INITIAL = true;
const bool ACYCLIC_INITIAL = true;
const bool STOP_WHEN_REACH_T = true;
struct edge {
  int to;
  int residual_capacity;
  int cost;
  edge(int to, int residual_capacity, int cost)
      : to(to), residual_capacity(residual_capacity), cost(cost) {}
};
vector<edge> edges;
vector<int> g[max_v];
void add_edge(int u, int v, int capacity, int cost) {
  assert(NEGATIVE_COST_INITIAL || cost >= 0);
  g[u].push_back(edges.size());
  edges.push_back({v, capacity, cost});
  g[v].push_back(edges.size());
  edges.push_back({u, 0, -cost});
}
int phi[max_v], dist[max_v];
bool used[max_v];
bool dijkstra_mlogn(int s, int t) {
  for (int i = 0; i <= t; ++i) {
    dist[i] = infCost;
  }
  dist[s] = 0;
  priority_queue<pair<int, int>> q;
  q.push({0, s});
  while (!q.empty()) {
    pair<int, int> p = q.top();
    q.pop();
    const int v = p.second;
    if (-p.first != dist[v]) {
      continue;
    }
    if ((STOP_WHEN_REACH_T && v == t) || (dist[v] > dist[t])) {
      break;
    }
    for (int id : g[v]) {
      if (edges[id].residual_capacity == 0) {
        continue;
      }
      const int to = edges[id].to;
      if (dist[v] + phi[v] - phi[to] + edges[id].cost < dist[to]) {
        dist[to] = dist[v] + phi[v] - phi[to] + edges[id].cost;
        q.push({-dist[to], to});
      }
    }
  }
  if (dist[t] == infCost) {
    return false;
  }
  return true;
}
const int MAX_D = 0;
vector<int> all_v[MAX_D];
bool dijkstra_max_d(int s, int t) {
  for (int i = 0; i <= t; ++i) {
    dist[i] = infCost;
  }
  for (int i = 0; i < MAX_D; ++i) {
    all_v[i].clear();
  }
  dist[s] = 0;
  int curd = 0;
  all_v[0].push_back(s);
  while (true) {
    while (curd < MAX_D && all_v[curd].empty()) {
      ++curd;
    }
    if (curd == MAX_D) {
      break;
    }
    const int v = all_v[curd].back();
    all_v[curd].pop_back();
    if (curd != dist[v]) {
      continue;
    }
    if ((STOP_WHEN_REACH_T && v == t) || (dist[v] > dist[t])) {
      break;
    }
    for (int id : g[v]) {
      if (edges[id].residual_capacity == 0) {
        continue;
      }
      const int to = edges[id].to;
      if (dist[v] + phi[v] - phi[to] + edges[id].cost < dist[to]) {
        dist[to] = dist[v] + phi[v] - phi[to] + edges[id].cost;
        assert(dist[to] < MAX_D);
        all_v[dist[to]].push_back(to);
      }
    }
  }
  if (dist[t] == infCost) {
    return false;
  }
  return true;
}
bool dijkstra_n2(int s, int t) {
  for (int i = 0; i <= t; ++i) {
    dist[i] = infCost;
    used[i] = 0;
  }
  dist[s] = 0;
  for (int i = 0; i <= t; ++i) {
    int v = -1;
    for (int j = 0; j <= t; ++j) {
      if (!used[j] && (v == -1 || dist[j] < dist[v])) {
        v = j;
      }
    }
    if ((STOP_WHEN_REACH_T && v == t) || (dist[v] > dist[t])) {
      break;
    }
    used[v] = 1;
    for (int id : g[v]) {
      if (edges[id].residual_capacity == 0) {
        continue;
      }
      const int to = edges[id].to;
      if (dist[v] + phi[v] - phi[to] + edges[id].cost < dist[to]) {
        dist[to] = dist[v] + phi[v] - phi[to] + edges[id].cost;
      }
    }
  }
  if (dist[t] == infCost) {
    return false;
  }
  return true;
}
void update_potentials(int s, int t) {
  int phiS = phi[s];
  for (int i = 0; i <= t; ++i) {
    if (dist[i] > dist[t]) {
      dist[i] = infCost;
      continue;
    }
    int okd = min(infCost, dist[i] + phi[i] - phiS);
    phi[i] -= dist[t] - dist[i];
    dist[i] = okd;
  }
}
bool dijkstra(int s, int t) {
  if (DIJKSTRA_TYPE == 0) {
    puts("Select dijkstra type");
    exit(1);
  }
  bool res;
  if (DIJKSTRA_TYPE == DIJKSTRA_N2) {
    res = dijkstra_n2(s, t);
  } else if (DIJKSTRA_TYPE == DIJKSTRA_MLOGN) {
    res = dijkstra_mlogn(s, t);
  } else if (DIJKSTRA_TYPE == DIJKSTRA_MAXD) {
    res = dijkstra_max_d(s, t);
  } else {
    puts("Unsupported dijkstra type");
    exit(2);
  }
  if (res) {
    update_potentials(s, t);
  }
  return res;
}
int start[max_v];
int dfs(int v, int t, int f) {
  if (v == t) {
    return f;
  }
  used[v] = 1;
  for (int &i = start[v]; i < g[v].size(); ++i) {
    const int id = g[v][i];
    if (edges[id].residual_capacity &&
        dist[v] + edges[id].cost == dist[edges[id].to] && !used[edges[id].to]) {
      int res = dfs(edges[id].to, t, min(f, edges[id].residual_capacity));
      if (res) {
        edges[id].residual_capacity -= res;
        edges[id ^ 1].residual_capacity += res;
        used[v] = 0;
        return res;
      }
    }
  }
  used[v] = 0;
  return 0;
}
void init_phi(int v, int s) {
  if (v == s) {
    phi[v] = 0;
    return;
  }
  if (phi[v] != infCost) {
    return;
  }
  for (int id : g[v]) {
    if (edges[id].residual_capacity != 0) {
      continue;
    }
    init_phi(edges[id].to, s);
    phi[v] = min(phi[v], phi[edges[id].to] - edges[id].cost);
  }
}
long long min_cost_max_flow(int s, int t) {
  assert(t < max_v);
  if (!NEGATIVE_COST_INITIAL) {
    fill(phi, phi + t + 1, 0);
  } else if (ACYCLIC_INITIAL) {
    fill(phi, phi + t + 1, infCost);
    init_phi(t, s);
  } else {
    cout << "FAIL, graph should be either acyclic, or doesn't contain negative "
            "edges"
         << endl;
    exit(1);
  }
  long long res = 0;
  while (dijkstra(s, t)) {
    memset(start, 0, sizeof(int) * (t + 1));
    if (DIJKSTRA_TYPE == DIJKSTRA_N2) {
      memset(used, 0, t + 1);
    }
    while (int x = dfs(s, t, infCapacity)) {
      res += 1LL * x * dist[t];
    }
  }
  return res;
}
void clr(int t) {
  edges.clear();
  for (int i = 0; i <= t; ++i) {
    g[i].clear();
    phi[i] = dist[i] = used[i] = 0;
  }
}
}  // namespace mcmf
int n, k, a[max_n];
vector<int> b, c;
vector<pair<int, int>> e[max_n * 2];
int main() {
  cin >> n >> k;
  for (int i = 0; i < (1 << n); ++i) {
    scanf("%d", &a[i]);
    if (__builtin_popcount(i) % 2 == 0) {
      b.push_back(i);
    }
  }
  for (int x : b) {
    for (int q = 0; q < n; ++q) {
      int y = x ^ (1 << q);
      e[a[x] + a[y]].push_back({x, y});
    }
  }
  int cnt = k * n * 2;
  map<int, int> ptr;
  int st = 2;
  int fn = k * n * 2 + 4;
  for (int i = max_n * 2 - 1; i >= 0; --i) {
    while (cnt && !e[i].empty()) {
      auto p = e[i].back();
      e[i].pop_back();
      if (ptr.find(p.first) == ptr.end()) {
        ptr[p.first] = st++;
        mcmf::add_edge(1, ptr[p.first], 1, 0);
      }
      if (ptr.find(p.second) == ptr.end()) {
        ptr[p.second] = st++;
        mcmf::add_edge(ptr[p.second], fn, 1, 0);
      }
      mcmf::add_edge(ptr[p.first], ptr[p.second], 1, -i);
      --cnt;
    }
  }
  mcmf::add_edge(0, 1, k, 0);
  cout << -mcmf::min_cost_max_flow(0, fn) << "\n";
}
