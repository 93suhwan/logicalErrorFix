#include <bits/stdc++.h>
using namespace std;
const int iu = 17;
int n, q;
long long e[200001];
int anc[200001][18];
long long pto[200001][18];
long long d[200001];
vector<pair<long long, int> > adj[200001];
pair<long long, pair<int, int> > ed[200001];
void dfs(int id) {
  for (auto c : adj[id]) {
    if (c.second == anc[id][0]) continue;
    d[c.second] = d[id] + 1;
    anc[c.second][0] = id;
    pto[c.second][0] = c.first;
    for (int i = 0; i < iu; i++) {
      anc[c.second][i + 1] = anc[anc[c.second][i]][i];
      pto[c.second][i + 1] = max(pto[c.second][i], pto[anc[c.second][i]][i]);
    }
    dfs(c.second);
  }
}
int kth(int x, int k) {
  for (int i = iu; i >= 0; i--) {
    if ((k >> i) & 1) x = anc[x][i];
  }
  return x;
}
long long go(int x, int k) {
  long long res = 0;
  for (int i = iu; i >= 0; i--) {
    if ((k >> i) & 1) {
      res = max(res, pto[x][i]);
      x = anc[x][i];
    }
  }
  return res;
}
int lca(int x, int y) {
  if (d[x] < d[y]) swap(x, y);
  x = kth(x, d[x] - d[y]);
  if (x == y) return x;
  for (int i = iu; i >= 0; i--) {
    if (anc[x][i] != anc[y][i]) {
      x = anc[x][i];
      y = anc[y][i];
    }
  }
  return anc[x][0];
}
long long get_toll(int x, int y) {
  int z = lca(x, y);
  return max(go(x, d[x] - d[z]), go(y, d[y] - d[z]));
}
pair<pair<long long, int>, int> qr[200001];
long long ans1[200001], ans2[200001];
int p[200001];
int king[200001];
long long city[200001];
int find(int x) {
  if (p[x] != x) p[x] = find(p[x]);
  return p[x];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> e[i];
  for (int i = 1; i < n; i++) {
    int u, v;
    long long c, t;
    cin >> u >> v >> c >> t;
    adj[u].push_back({t, v});
    adj[v].push_back({t, u});
    ed[i] = {c, {u, v}};
  }
  dfs(1);
  sort(ed + 1, ed + n);
  reverse(ed + 1, ed + n);
  for (int i = 1; i <= q; i++) {
    cin >> qr[i].first.first >> qr[i].first.second;
    qr[i].second = i;
  }
  sort(qr + 1, qr + q + 1);
  reverse(qr + 1, qr + q + 1);
  int ptr = 0;
  for (int i = 1; i <= n; i++) {
    p[i] = i;
    king[i] = i;
    city[i] = 0;
  }
  for (int i = 1; i <= q; i++) {
    while (ptr < n - 1 && ed[ptr + 1].first >= qr[i].first.first) {
      ++ptr;
      int u = ed[ptr].second.first;
      int v = ed[ptr].second.second;
      u = find(u);
      v = find(v);
      if (e[king[u]] != e[king[v]]) {
        if (e[king[u]] < e[king[v]])
          p[u] = v;
        else
          p[v] = u;
      } else {
        p[v] = u;
        city[u] = max(max(city[u], city[v]), get_toll(king[u], king[v]));
      }
    }
    int x = qr[i].first.second;
    int y = find(x);
    long long res = max(get_toll(x, king[y]), city[y]);
    ans1[qr[i].second] = e[king[y]];
    ans2[qr[i].second] = res;
  }
  for (int i = 1; i <= q; i++) cout << ans1[i] << ' ' << ans2[i] << '\n';
}
