#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e16;
struct Edge {
  int u, v;
  long long w;
  bool operator<(const Edge& rhs) const {
    return w == rhs.w ? tie(u, v) < tie(rhs.u, rhs.v) : w < rhs.w;
  }
};
int n, m;
set<Edge> e;
map<pair<int, int>, long long> weight;
set<Edge> adj[200005];
map<long long, int> t1;
long long find_other(const Edge& ed) {
  for (auto [u, v, w] : e) {
    if (u != ed.u && u != ed.v && v != ed.u && v != ed.v) return w;
  }
  return INF;
}
long long sum_3(int u) {
  auto it = adj[u].begin();
  long long res = 0;
  for (int i = 0; i < 3; ++i, it++) res += it->w;
  return res;
}
void add_edge(int u, int v, long long w) {
  if (u < v) weight[{u, v}] = w;
  if (adj[u].size() < 3) {
    adj[u].insert({u, v, w});
    e.insert({u, v, w});
    if (((int)adj[u].size()) == 3) ++t1[sum_3(u)];
  } else {
    auto it = adj[u].begin();
    ++it;
    ++it;
    adj[u].insert({u, v, w});
    if (it->w > w) {
      long long s3 = sum_3(u);
      if (--t1[s3] == 0) t1.erase(s3);
      e.erase({it->u, it->v, it->w});
      e.erase({it->v, it->u, it->w});
      e.insert({u, v, w});
      ++t1[sum_3(u)];
    }
  }
}
bool present(int u, int v) {
  auto it = adj[u].begin();
  for (int i = 0; i < 3 && it != adj[u].end(); it++, i++) {
    if (it->v == v) return true;
  }
  return false;
}
void del_edge(int u, int v, long long w) {
  if (u < v) {
    weight.erase({u, v});
    e.erase({u, v, w});
    e.erase({v, u, w});
  }
  if (((int)adj[u].size()) < 3) {
    adj[u].erase(adj[u].find({u, v, w}));
  } else {
    long long s3 = sum_3(u);
    if (--t1[s3] == 0) t1.erase(s3);
    if (present(u, v)) {
      adj[u].erase(adj[u].find({u, v, w}));
      if (((int)adj[u].size()) >= 3) {
        ++t1[sum_3(u)];
        auto it = adj[u].begin();
        it++;
        it++;
        if (present(it->v, it->u)) {
          e.insert(*it);
          e.insert({it->v, it->u, it->w});
        }
      }
      return;
    }
    adj[u].erase(adj[u].find({u, v, w}));
    if (adj[u].size() >= 3) ++t1[sum_3(u)];
  }
}
long long get() {
  long long res = INF;
  if (!t1.empty()) res = t1.begin()->first;
  auto& [u, v, w] = *e.begin();
  int iter = 6;
  for (auto ed : adj[u]) {
    res = min(res, find_other(ed) + ed.w);
    iter--;
    if (iter == 0) break;
  }
  iter = 6;
  for (auto ed : adj[v]) {
    res = min(res, find_other(ed) + ed.w);
    iter--;
    if (iter == 0) break;
  }
  return res;
}
void fix(int u, int v, long long w) {
  if (e.find({u, v, w}) == e.end() || e.find({v, u, w}) == e.end()) {
    e.erase({u, v, w});
    e.erase({v, u, w});
  }
}
void solve(int case_id) {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int u, v;
    long long w;
    cin >> u >> v >> w;
    add_edge(u, v, w);
    add_edge(v, u, w);
    fix(u, v, w);
  }
  cout << get() << endl;
  int q;
  cin >> q;
  for (int i = 1; i <= q; ++i) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int u, v;
      long long w;
      cin >> u >> v >> w;
      add_edge(u, v, w);
      add_edge(v, u, w);
      fix(u, v, w);
    } else {
      int u, v;
      cin >> u >> v;
      long long w = weight[{min(u, v), max(u, v)}];
      del_edge(u, v, w);
      del_edge(v, u, w);
    }
    cout << get() << endl;
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(false);
  int t = 1;
  for (int i = 1; i <= t; ++i) solve(i);
}
