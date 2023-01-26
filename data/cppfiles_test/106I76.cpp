#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9;
struct graph {
  struct edge {
    long long src, dst;
    long long capacity, flow;
    long long cost;
    size_t rev;
  };
  vector<edge> edges;
  void add_edge(long long src, long long dst, long long cap, long long cost) {
    adj[src].push_back({src, dst, cap, 0, cost, adj[dst].size()});
    adj[dst].push_back({dst, src, 0, 0, -cost, adj[src].size() - 1});
  }
  long long n;
  vector<vector<edge>> adj;
  graph(long long n) : n(n), adj(n) {}
  pair<long long, long long> min_cost_max_flow(long long s, long long t) {
    long long flow = 0;
    long long cost = 0;
    for (long long u = 0; u < n; ++u)
      for (auto &e : adj[u]) e.flow = 0;
    vector<long long> p(n, 0);
    auto rcost = [&](edge e) { return e.cost + p[e.src] - p[e.dst]; };
    for (long long iter = 0;; ++iter) {
      vector<long long> prev(n, -1);
      prev[s] = 0;
      vector<long long> dist(n, INF);
      dist[s] = 0;
      if (iter == 0) {
        vector<long long> count(n);
        count[s] = 1;
        queue<long long> que;
        for (que.push(s); !que.empty();) {
          long long u = que.front();
          que.pop();
          count[u] = -count[u];
          for (auto &e : adj[u]) {
            if (e.capacity > e.flow && dist[e.dst] > dist[e.src] + rcost(e)) {
              dist[e.dst] = dist[e.src] + rcost(e);
              prev[e.dst] = e.rev;
              if (count[e.dst] <= 0) {
                count[e.dst] = -count[e.dst] + 1;
                que.push(e.dst);
              }
            }
          }
        }
      } else {
        priority_queue<pair<long long, long long>,
                       vector<pair<long long, long long>>,
                       greater<pair<long long, long long>>>
            que;
        que.push({0, s});
        while (!que.empty()) {
          pair<long long, long long> a = que.top();
          que.pop();
          if (a.second == t) break;
          if (dist[a.second] > a.first) continue;
          for (auto e : adj[a.second]) {
            if (e.capacity > e.flow && dist[e.dst] > a.first + rcost(e)) {
              dist[e.dst] = dist[e.src] + rcost(e);
              prev[e.dst] = e.rev;
              que.push({dist[e.dst], e.dst});
            }
          }
        }
      }
      if (prev[t] == -1) break;
      for (long long u = 0; u < n; ++u)
        if (dist[u] < dist[t]) p[u] += dist[u] - dist[t];
      function<long long(long long, long long)> augment = [&](long long u,
                                                              long long cur) {
        if (u == s) return cur;
        edge &r = adj[u][prev[u]], &e = adj[r.dst][r.rev];
        long long f = augment(e.src, min(e.capacity - e.flow, cur));
        e.flow += f;
        r.flow -= f;
        return f;
      };
      long long f = augment(t, INF);
      flow += f;
      cost += f * (p[t] - p[s]);
    }
    return {flow, cost};
  }
};
long long n, k;
long long a[1 << 20];
long long m;
vector<pair<int32_t, pair<int32_t, int32_t>>> v;
void quickselect(long long a, long long b) {
  if (a >= b) return;
  long long p = rand() % (b - a + 1) + a;
  swap(v[p], v[b]);
  long long s = a;
  for (long long i = a; i < b; ++i) {
    if (v[i] > v[b]) {
      swap(v[s], v[i]);
      s++;
    }
  }
  swap(v[s], v[b]);
  if (m == s)
    return;
  else if (m < s)
    quickselect(a, s - 1);
  else
    quickselect(s + 1, b);
}
long long pcount(long long a) {
  long long r = 0;
  while (a) {
    r += a % 2;
    a /= 2;
  }
  return r;
}
int32_t main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (long long i = 0; i < (1 << n); ++i) cin >> a[i];
  m = min((long long)1 << n, k * n * 2) - 1;
  k = min(k, (long long)1 << (n - 1));
  for (long long i = 0; i < (1 << n); ++i)
    for (long long j = 0; j < n; ++j) {
      long long x = i ^ (1 << j);
      if (x < i) continue;
      bool sw = pcount(i) % 2;
      v.push_back({a[i] + a[x], {sw ? i : x, sw ? x : i}});
    }
  quickselect(0, v.size() - 1);
  long long c = 3;
  map<long long, long long> s[2];
  for (long long i = 0; i < m; ++i) {
    long long x = v[i].second.first, y = v[i].second.second;
    if (s[0].count(x) == 0) s[0][x] = c++;
    if (s[1].count(y) == 0) s[1][y] = c++;
  }
  graph g(c);
  g.add_edge(0, 1, k, 0);
  for (auto a : s[0]) g.add_edge(1, a.second, 1, 0);
  for (auto a : s[1]) g.add_edge(a.second, 2, 1, 0);
  for (long long i = 0; i < m; ++i) {
    long long x = v[i].second.first, y = v[i].second.second;
    g.add_edge(s[0][x], s[1][y], 1, 1e9 - v[i].first);
  }
  cout << k * 1e9 - g.min_cost_max_flow(0, 2).second << "\n";
}
