#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream &operator<<(ostream &out, vector<T> &v) {
  out << "[";
  for (auto k : v) out << k << ",";
  out << "]"
      << "\n";
  return out;
}
template <class T>
ostream &operator<<(ostream &out, set<T> s) {
  out << "{";
  for (auto k : s) out << k << ",";
  out << "}"
      << "\n";
  return out;
}
template <class T, class U>
ostream &operator<<(ostream &out, pair<T, U> p) {
  out << "[ " << p.first << " , " << p.second << " ] ";
  return out;
}
template <class T, class U>
istream &operator>>(istream &in, pair<T, U> &p) {
  in >> p.first >> p.second;
  return in;
}
const long long INFFLOW = 1e9;
const long long INFCOST = 1e9;
struct MCF {
  int n;
  vector<long long> prio, pot;
  vector<long long> curflow;
  vector<int> prevedge, prevnode;
  priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                 greater<pair<long long, int>>>
      q;
  struct edge {
    int to, rev;
    long long f, cap;
    long long cost;
  };
  vector<vector<edge>> g;
  MCF(int n)
      : n(n), prio(n), curflow(n), prevedge(n), prevnode(n), pot(n), g(n) {}
  void add_edge(int s, int t, long long cap, long long cost) {
    g[s].push_back((edge){t, int(g[t].size()), 0, cap, cost});
    g[t].push_back((edge){s, int(g[s].size()) - 1, 0, 0, -cost});
  }
  long long get_flow(int s, int t) {
    long long flow = 0;
    long long flowcost = 0;
    long long res = 0;
    while (1) {
      q.push({0, s});
      fill(prio.begin(), prio.end(), INFCOST);
      prio[s] = 0;
      curflow[s] = INFFLOW;
      while (!q.empty()) {
        auto cur = q.top();
        long long d = cur.first;
        int u = cur.second;
        q.pop();
        if (d != prio[u]) continue;
        for (int i = 0; i < int(g[u].size()); ++i) {
          edge &e = g[u][i];
          int v = e.to;
          if (e.cap <= e.f) continue;
          long long nprio = prio[u] + e.cost + pot[u] - pot[v];
          if (prio[v] > nprio) {
            prio[v] = nprio;
            q.push({nprio, v});
            prevnode[v] = u;
            prevedge[v] = i;
            curflow[v] = min(curflow[u], e.cap - e.f);
          }
        }
      }
      if (prio[t] == INFCOST) break;
      for (int i = int(0); i < int(n); i++) pot[i] += prio[i];
      long long df = min(curflow[t], INFFLOW - flow);
      flow += df;
      for (int v = t; v != s; v = prevnode[v]) {
        edge &e = g[prevnode[v]][prevedge[v]];
        e.f += df;
        g[v][e.rev].f -= df;
        flowcost += df * e.cost;
      }
      res = min(res, flowcost);
    }
    return res;
  }
};
const int maxv = 2e6 + 1000;
vector<pair<int, int>> ars[maxv];
int a[maxv];
struct getId {
  unordered_map<int, int> m;
  int &operator[](int &x) {
    auto &v = m[x];
    if (v == 0) v = m.size();
    return v;
  }
};
bitset<maxv> used;
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  int tam = 1 << n;
  for (int i = 0; i < int(tam); i++) {
    cin >> a[i];
  }
  for (int i = 0; i < int(tam); i++) {
    for (int j = 0; j < int(n); j++)
      if (((i >> (1 * (j)) & ((1 << 1) - 1))) == 0) {
        int i2 = (((i & ~(((1 << 1) - 1) << (1 * (j)))) | (1 << (1 * (j)))));
        if ((__builtin_popcount(i)) % 2 == 0)
          ars[a[i] + a[i2]].push_back({i, i2});
        else
          ars[a[i] + a[i2]].push_back({i2, i});
      }
  }
  int cant = (2 * n) * k + 1;
  int ini = 2 * cant + 1, fin = 2 * cant + 2;
  MCF g(2 * cant + 10);
  getId ids;
  for (int i = int(maxv) - 1; i >= 0; i--) {
    for (auto p : ars[i])
      if (cant) {
        int a = ids[p.first];
        int b = ids[p.second];
        if (!used[a]) {
          used[a] = true;
          g.add_edge(ini, a, 1, 0);
        }
        if (!used[b]) {
          used[b] = true;
          g.add_edge(b, fin, 1, 0);
        }
        g.add_edge(a, b, 1, -i);
        cant--;
      }
    if (!cant) break;
  }
  int ini2 = fin + 1;
  g.add_edge(ini2, ini, k, 0);
  auto res = g.get_flow(ini2, fin);
  cout << -res << '\n';
}
