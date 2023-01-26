#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long max_n = 200005, max_q = 200005;
long long timer = 0;
long long n, q;
long long enj[max_n];
long long a[max_n], b[max_n], c[max_n], t[max_n];
vector<pair<long long, long long> > adj[max_n];
long long sz[max_q], st[max_q];
long long tin[max_n], tout[max_n], depth[max_n];
pair<long long, long long> jump[max_n][25];
long long dsu[max_n], max_enjoyment[max_n], max_pos[max_n], max_inside[max_n];
vector<pair<long long, long long> > queries;
pair<long long, long long> ans[max_q];
bool custom_comp(pair<long long, long long> a_, pair<long long, long long> b_) {
  long long cap_a, cap_b;
  if (a_.first == 1)
    cap_a = c[a_.second];
  else
    cap_a = sz[a_.second];
  if (b_.first == 1)
    cap_b = c[b_.second];
  else
    cap_b = sz[b_.second];
  if (cap_a != cap_b) return cap_a > cap_b;
  return a_.first < b_.first;
}
void dfs(long long u, long long p) {
  depth[u] = depth[p] + 1;
  tin[u] = timer++;
  for (long long i = 1; i < 20; i++) {
    jump[u][i].first = jump[jump[u][i - 1].first][i - 1].first;
    jump[u][i].second =
        max(jump[u][i - 1].second, jump[jump[u][i - 1].first][i - 1].second);
  }
  for (auto e : adj[u]) {
    long long v = e.first, w = e.second;
    if (v == p) continue;
    jump[v][0] = make_pair(u, w);
    dfs(v, u);
  }
  tout[u] = timer++;
}
bool anc(long long u, long long v) {
  return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}
long long lca(long long u, long long v) {
  if (anc(u, v)) return u;
  if (anc(v, u)) return v;
  for (long long i = 19; i >= 0; i--) {
    if (!anc(jump[u][i].first, v)) u = jump[u][i].first;
  }
  return jump[u][0].first;
}
long long query_path(long long u, long long v) {
  long long l = lca(u, v);
  long long du = depth[u] - depth[l], dv = depth[v] - depth[l];
  long long mx = 0;
  for (long long i = 19; i >= 0; i--) {
    if ((du >> i) & 1) {
      mx = max(mx, jump[u][i].second);
      u = jump[u][i].first;
    }
    if ((dv >> i) & 1) {
      mx = max(mx, jump[v][i].second);
      v = jump[v][i].first;
    }
  }
  return mx;
}
long long find_root(long long u) {
  if (dsu[u] < 0) return u;
  return dsu[u] = find_root(dsu[u]);
}
void join(long long u, long long v) {
  u = find_root(u);
  v = find_root(v);
  if (dsu[u] > dsu[v]) swap(u, v);
  dsu[u] += dsu[v];
  dsu[v] = u;
  if (max_enjoyment[u] < max_enjoyment[v]) {
    max_enjoyment[u] = max_enjoyment[v];
    max_pos[u] = max_pos[v];
    max_inside[u] = max_inside[v];
  } else if (max_enjoyment[u] == max_enjoyment[v]) {
    max_inside[u] = max(max(max_inside[u], max_inside[v]),
                        query_path(max_pos[u], max_pos[v]));
  }
}
pair<long long, long long> query(long long start) {
  long long root = find_root(start);
  return make_pair(max_enjoyment[root],
                   max(max_inside[root], query_path(start, max_pos[root])));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (long long i = 1; i <= n; i++) cin >> enj[i];
  for (long long i = 1; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i] >> t[i];
    adj[a[i]].emplace_back(b[i], t[i]);
    adj[b[i]].emplace_back(a[i], t[i]);
    queries.emplace_back(1, i);
  }
  for (long long i = 1; i <= q; i++) {
    cin >> sz[i] >> st[i];
    queries.emplace_back(2, i);
  }
  tin[0] = -1;
  dfs(1, 0);
  tout[0] = tout[1] + 1;
  for (long long i = 1; i <= n; i++) {
    dsu[i] = -1;
    max_enjoyment[i] = enj[i];
    max_pos[i] = i;
  }
  sort(queries.begin(), queries.end(), custom_comp);
  for (auto qr : queries) {
    long long type = qr.first, id = qr.second;
    if (type == 1)
      join(a[id], b[id]);
    else
      ans[id] = query(st[id]);
  }
  for (long long i = 1; i <= q; i++)
    cout << ans[i].first << " " << ans[i].second << "\n";
}
