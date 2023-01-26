#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
template <typename T>
vector<T>& operator--(vector<T>& v) {
  for (auto& i : v) --i;
  return v;
}
template <typename T>
vector<T>& operator++(vector<T>& v) {
  for (auto& i : v) ++i;
  return v;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& i : v) is >> i;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
  for (auto& i : v) os << i << ' ';
  return os;
}
template <typename T, typename U>
pair<T, U>& operator--(pair<T, U>& p) {
  --p.first;
  --p.second;
  return p;
}
template <typename T, typename U>
pair<T, U>& operator++(pair<T, U>& p) {
  ++p.first;
  ++p.second;
  return p;
}
template <typename T, typename U>
istream& operator>>(istream& is, pair<T, U>& p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, pair<T, U> p) {
  os << p.first << ' ' << p.second;
  return os;
}
template <typename T, typename U>
pair<T, U> operator-(pair<T, U> a, pair<T, U> b) {
  return make_pair(a.first - b.first, a.second - b.second);
}
template <typename T, typename U>
pair<T, U> operator+(pair<T, U> a, pair<T, U> b) {
  return make_pair(a.first + b.first, a.second + b.second);
}
template <typename T, typename U>
void umin(T& a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
void umax(T& a, U b) {
  if (a < b) a = b;
}
using COST_T = long long;
struct mfmc_edge {
  int from, to;
  long long mx;
  long long cost;
};
pair<ll, COST_T> max_flow_min_cost(
    vector<vector<pair<int, pair<ll, COST_T>>>> g_main, int s, int t,
    ll k = -1) {
  int n = g_main.size();
  vector<vector<int>> g(n);
  vector<mfmc_edge> e;
  for (int u = 0; u < n; ++u) {
    for (auto p : g_main[u]) {
      int v = p.first;
      ll w = p.second.first, c = p.second.second;
      g[u].push_back(e.size());
      e.push_back({u, v, w, c});
      g[v].push_back(e.size());
      e.push_back({v, u, 0, -c});
    }
  }
  const ll inf = 1e18l * 4;
  vector<COST_T> p(n, inf);
  p[s] = 0;
  vector<int> par(n, -1);
  for (int i = 0; i < n; ++i) {
    bool change = false;
    for (int j = 0; j < e.size(); ++j) {
      auto edge = e[j];
      if (edge.mx > 0 && p[edge.from] != inf) {
        if (p[edge.to] > p[edge.from] + edge.cost) {
          p[edge.to] = p[edge.from] + edge.cost;
          par[edge.to] = j;
          change = true;
        }
      }
    }
    if (!change) break;
  }
  pair<ll, COST_T> ans = {0, 0};
  vector<ll> d = p;
  while (true) {
    if (par[t] == -1) break;
    if (ans.first == k) break;
    int v = t;
    ll flow = (k == -1 ? (ll)4e18 : k - ans.first), cost = 0;
    while (v != s) {
      flow = min(flow, e[par[v]].mx);
      cost += e[par[v]].cost;
      v = e[par[v]].from;
    }
    v = t;
    while (v != s) {
      e[par[v]].mx -= flow;
      e[par[v] ^ 1].mx += flow;
      v = e[par[v]].from;
    }
    ans.first += flow;
    ans.second += cost * flow;
    par.assign(n, -1);
    d.assign(n, inf);
    d[s] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
        pq;
    pq.push({0, s});
    while (!pq.empty()) {
      int v = pq.top().second;
      ll ds = pq.top().first;
      pq.pop();
      if (ds > d[v]) continue;
      for (auto i : g[v]) {
        if (e[i].mx > 0 &&
            d[e[i].to] > d[v] + e[i].cost + p[e[i].from] - p[e[i].to]) {
          d[e[i].to] = d[v] + e[i].cost + p[e[i].from] - p[e[i].to];
          par[e[i].to] = i;
          pq.push({d[e[i].to], e[i].to});
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      if (d[v] == inf || p[v] == inf)
        p[v] = inf;
      else
        p[v] += d[v];
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  vector<int> a(1 << n);
  cin >> a;
  vector<pair<int, pair<int, int>>> best;
  for (int i = 0; i < (1 << n); ++i) {
    for (int j = 0; j < n; ++j) {
      int i2 = i ^ (1 << j);
      if (i2 > j) continue;
      best.emplace_back(a[i] + a[i2], make_pair(i, i2));
    }
  }
  sort(best.rbegin(), best.rend());
  void(0);
  vector<int> has(1 << n, 0);
  int cur = 0;
  int ind = 0;
  for (auto [_, uv] : best) {
    ++ind;
    auto [u, v] = uv;
    if (has[u] || has[v]) {
      continue;
    }
    has[u] = has[v] = 1;
    ++cur;
    if (cur >= k * 2 + 5 && false) break;
  }
  for (int i = 0; i < ind; ++i) {
    auto [u, v] = best[i].second;
    has[u] = has[v] = 1;
  }
  vector<int> left, right;
  for (int i = 0; i < has.size(); ++i) {
    if (has[i]) {
      if (__builtin_popcount(i) % 2)
        left.push_back(i);
      else
        right.push_back(i);
    }
  }
  vector<vector<pair<int, pair<ll, ll>>>> g(left.size() + right.size() + 2);
  for (int i = 0; i < left.size(); ++i) {
    for (int b = 0; b < n; ++b) {
      int j = (left[i] ^ (1 << b));
      if (!has[j]) continue;
      int ind =
          (lower_bound((right).begin(), (right).end(), (j)) - (right).begin());
      assert(ind < right.size() && right[ind] == j);
      g[i + 2].emplace_back(left.size() + 2 + ind,
                            make_pair(1, -(a[left[i]] + a[j])));
    }
    g[0].emplace_back(i + 2, make_pair(1, 0));
  }
  for (int i = 0; i < right.size(); ++i) {
    g[left.size() + 2 + i].emplace_back(1, make_pair(1, 0));
  }
  void(0);
  void(0);
  void(0);
  auto [flow, cost] = max_flow_min_cost(g, 0, 1, k);
  void(0);
  cout << -cost << '\n';
  return 0;
}
