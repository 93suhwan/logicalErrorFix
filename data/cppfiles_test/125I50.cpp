#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000007;
const int maxn = 300010;
namespace gmatch {
template <typename T>
class graph {
 public:
  struct edge {
    int from;
    int to;
    T cost;
  };
  vector<edge> edges;
  vector<vector<int> > g;
  int n;
  graph(int _n) : n(_n) { g.resize(n); }
  virtual int add(int from, int to, T cost) = 0;
};
template <typename T>
class undirectedgraph : public graph<T> {
 public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;
  undirectedgraph(int _n) : graph<T>(_n) {}
  int add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int)edges.size();
    g[from].push_back(id);
    g[to].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }
};
template <typename T>
vector<int> find_max_unweighted_matching(const undirectedgraph<T> &g) {
  std::mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  vector<int> match(g.n, -1);
  vector<int> aux(g.n, -1);
  vector<int> label(g.n);
  vector<int> orig(g.n);
  vector<int> parent(g.n, -1);
  queue<int> q;
  int aux_time = -1;
  auto lca = [&](int v, int u) {
    aux_time++;
    while (true) {
      if (v != -1) {
        if (aux[v] == aux_time) {
          return v;
        }
        aux[v] = aux_time;
        if (match[v] == -1) {
          v = -1;
        } else {
          v = orig[parent[match[v]]];
        }
      }
      swap(v, u);
    }
  };
  auto blossom = [&](int v, int u, int a) {
    while (orig[v] != a) {
      parent[v] = u;
      u = match[v];
      if (label[u] == 1) {
        label[u] = 0;
        q.push(u);
      }
      orig[v] = orig[u] = a;
      v = parent[u];
    }
  };
  auto augment = [&](int v) {
    while (v != -1) {
      int pv = parent[v];
      int next_v = match[pv];
      match[v] = pv;
      match[pv] = v;
      v = next_v;
    }
  };
  auto bfs = [&](int root) {
    fill(label.begin(), label.end(), -1);
    iota(orig.begin(), orig.end(), 0);
    while (!q.empty()) {
      q.pop();
    }
    q.push(root);
    label[root] = 0;
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int id : g.g[v]) {
        auto &e = g.edges[id];
        int u = e.from ^ e.to ^ v;
        if (label[u] == -1) {
          label[u] = 1;
          parent[u] = v;
          if (match[u] == -1) {
            augment(u);
            return true;
          }
          label[match[u]] = 0;
          q.push(match[u]);
          continue;
        } else if (label[u] == 0 && orig[v] != orig[u]) {
          int a = lca(orig[v], orig[u]);
          blossom(u, v, a);
          blossom(v, u, a);
        }
      }
    }
    return false;
  };
  auto greedy = [&]() {
    vector<int> order(g.n);
    iota(order.begin(), order.end(), 0);
    shuffle(order.begin(), order.end(), rng);
    for (int i : order) {
      if (match[i] == -1) {
        for (auto id : g.g[i]) {
          auto &e = g.edges[id];
          int to = e.from ^ e.to ^ i;
          if (match[to] == -1) {
            match[i] = to;
            match[to] = i;
            break;
          }
        }
      }
    }
  };
  greedy();
  for (int i = 0; i < g.n; i++) {
    if (match[i] == -1) {
      bfs(i);
    }
  }
  return match;
}
}  // namespace gmatch
int s[maxn];
void solve(int n) {
  static int used[maxn];
  for (int i = 1; i <= n; ++i) {
    used[s[i]] = 1;
  }
  auto getU = [&]() {
    static int U = n;
    while (used[U]) {
      U--;
    }
    used[U--] = 1;
    assert(U >= 0);
    return U + 1;
  };
  if (s[1] == 0) {
    for (int i = 1; i < n; i += 2)
      if (s[i] == 0 && s[i + 1] == 0) {
        s[i] = s[i + 1] = getU();
      }
    if (s[1] == 0) {
      s[1] = s[2];
    }
  }
  if (s[n] == 0) {
    for (int i = n; i > 0; i -= 2)
      if (s[i] == 0 && s[i - 1] == 0) {
        s[i] = s[i - 1] = getU();
      }
    if (s[n] == 0) {
      s[n] = s[n - 1];
    }
  }
  static int fa[610], sz[610], ecnt[610];
  static pair<int, int> rep[610];
  static vector<pair<int, int> > g[610];
  int nn = min(n, 605);
  for (int i = 1; i <= nn; ++i) {
    fa[i] = i;
    sz[i] = 1;
    ecnt[i] = 0;
    rep[i] = {i, 0};
  }
  for (int i = 1; i <= nn; ++i)
    if (s[i] && s[i - 1] == s[i]) {
      rep[s[i]] = {s[i], i};
    }
  std::function<int(int)> fin = [&](int u) {
    return fa[u] == u ? u : (fa[u] = fin(fa[u]));
  };
  for (int pre = 0, i = 1; i <= n; ++i)
    if (s[i]) {
      if (pre > 0 && (i - pre) % 2 == 0) {
        int u = s[pre], v = s[i];
        int uu = fin(u), vv = fin(v);
        if (rep[uu].second != 0 && rep[vv].second != 0) {
        } else if (rep[uu].second == 0) {
          rep[uu] = {u, pre + 1};
        } else if (rep[vv].second == 0) {
          rep[vv] = {v, i - 1};
        } else {
          if (uu != vv) {
            g[u].emplace_back(v, i - 1);
            g[v].emplace_back(u, pre + 1);
            if (uu > vv) {
              swap(uu, vv);
            }
            fa[vv] = uu;
            sz[uu] += sz[vv];
          }
          ecnt[uu]++;
          if (ecnt[uu] == sz[uu]) {
            rep[uu] = {u, pre + 1};
          }
        }
      }
      pre = i;
    }
  static gmatch::undirectedgraph<int> matchG(nn + 10);
  static map<pair<int, int>, pair<int, int> > mm;
  for (int pre = 0, i = 1; i <= n; ++i)
    if (s[i]) {
      if (pre > 0 && s[i - 1] == 0 && (i - pre) % 2 == 1) {
        int u = s[pre], v = s[i];
        int uu = fin(u), vv = fin(v);
        if (rep[uu].second != 0 || rep[vv].second != 0 || uu == vv) {
        } else {
          if (uu > vv) {
            swap(uu, vv);
          }
          pair<int, int> mk = {uu, vv};
          pair<int, int> mv = {pre, i};
          if (mm.find(mk) == mm.end()) {
            mm[mk] = mv;
            matchG.add(uu, vv);
          }
        }
      }
      pre = i;
    }
  vector<int> vt = gmatch::find_max_unweighted_matching(matchG);
  assert(vt.size() > nn);
  for (int i = 1; i <= nn; ++i)
    if (vt[i] != -1 && i < vt[i]) {
      assert(vt[vt[i]] == i);
      pair<int, int> mk = {i, vt[i]};
      pair<int, int> mv = mm[mk];
      int uu = fin(s[mv.first]), vv = fin(s[mv.second]);
      assert(rep[uu].second == 0);
      assert(rep[vv].second == 0);
      rep[uu] = {s[mv.first], mv.first + 1};
      rep[vv] = {s[mv.second], mv.second - 1};
    }
  std::function<void(int)> dfs = [&](int u) {
    static int col[610];
    col[u] = 1;
    for (int i = 0; i < g[u].size(); ++i) {
      int v = g[u][i].first, p = g[i][i].second;
      if (!col[v]) {
        s[p] = v;
        dfs(v);
      }
    }
  };
  for (int i = 1; i <= nn; ++i)
    if (fin(i) == i) {
      s[rep[i].second] = rep[i].first;
      dfs(rep[i].first);
    }
  for (int i = 1; i <= n; ++i)
    if (s[i] == 0) {
      if (s[i + 1] == 0) {
        s[i] = s[i + 1] = getU();
      } else {
        s[i] = 1;
      }
    }
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &s[i]);
  }
  solve(n);
  for (int i = 1; i <= n; ++i) {
    printf("%d ", s[i]);
  }
  puts("");
  return 0;
}
