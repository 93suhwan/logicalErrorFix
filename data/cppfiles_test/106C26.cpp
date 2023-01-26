#include <bits/stdc++.h>
using namespace std;
template <int maxn, int inf>
struct Flow {
  vector<pair<int, pair<int, int> > > v[maxn];
  vector<int> rv[maxn];
  int arr[maxn], ds[maxn], pt[maxn];
  bool inq[maxn];
  void add(int a, int b, int c, int d) {
    rv[a].push_back((int(v[b].size())));
    rv[b].push_back((int(v[a].size())));
    v[a].push_back({b, {c, d}});
    v[b].push_back({a, {0, -d}});
  }
  bool spfa(int src, int snk) {
    fill(ds, ds + maxn, inf);
    memset(inq, 0, sizeof inq);
    int L = 0, R = 0;
    arr[R++] = src;
    ds[src] = 0;
    inq[src] = 1;
    while (L != R) {
      int u = arr[L++];
      if (L == maxn) L = 0;
      inq[u] = 0;
      for (auto x : v[u]) {
        if (x.second.first == 0) continue;
        if (ds[x.first] <= ds[u] + x.second.second) continue;
        ds[x.first] = ds[u] + x.second.second;
        if (inq[x.first] == 0)
          inq[x.first] = 1, arr[R++] = x.first, R = (R == maxn ? 0 : R);
      }
    }
    return ds[snk] != inf;
  }
  pair<int, int> dfs(int u, int snk, int f) {
    if (u == snk) return {f, 0};
    inq[u] = 1;
    int &i = pt[u];
    int ff = 0, cc = 0;
    while (i < (int(v[u].size()))) {
      int y = v[u][i].first, &w = v[u][i].second.first,
          &w2 = v[y][rv[u][i]].second.first, c = v[u][i].second.second;
      if (w > 0 && ds[u] + c == ds[y] && !inq[y]) {
        pair<int, int> p = dfs(y, snk, min(w, f - ff));
        cc += p.second + p.first * c;
        ff += p.first;
        w -= p.first, w2 += p.first;
        if (f == ff) break;
      }
      i++;
    }
    inq[u] = 0;
    return {ff, cc};
  }
  int flow(int src, int snk) {
    int cst = 0;
    while (spfa(src, snk)) {
      memset(pt, 0, sizeof pt);
      cst += dfs(src, snk, inf).second;
    }
    return cst;
  }
  int flow_with_limit(int src, int snk, int k) {
    int cst = 0;
    while (k > 0 && spfa(src, snk)) {
      memset(pt, 0, sizeof pt);
      pair<int, int> ret = dfs(src, snk, k);
      k -= ret.first;
      cst += ret.second;
    }
    return cst;
  }
};
const int maxn = 20;
const int maxN = (1 << maxn) + 10;
const int maxw = 2e6 + 10;
const int maxk = 210;
const int inf = 1e9;
vector<pair<int, int> > weight_eds[maxw];
int a[maxN];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < (1 << n); i++) cin >> a[i];
  for (int msk = 0; msk < (1 << n); msk++) {
    for (int i = 0; i < n; i++) {
      if ((((msk) >> (i)) & 1))
        weight_eds[a[msk] + a[msk ^ (1 << i)]].push_back({msk, msk ^ (1 << i)});
    }
  }
  vector<pair<int, int> > candidate_edges;
  vector<int> vertices;
  int candidate_limit = 2 * n * k + 5;
  int choose_w = maxw - 1;
  while (candidate_limit) {
    while (choose_w >= 0 && weight_eds[choose_w].empty()) choose_w--;
    if (choose_w < 0) break;
    pair<int, int> e = weight_eds[choose_w].back();
    weight_eds[choose_w].pop_back();
    candidate_edges.push_back(e);
    vertices.push_back(e.first);
    vertices.push_back(e.second);
    candidate_limit--;
  }
  sort(vertices.begin(), vertices.end());
  vertices.resize(unique(vertices.begin(), vertices.end()) - vertices.begin());
  int src = vertices.size(), snk = vertices.size() + 1;
  Flow<2 * maxn * maxk * 2 + 5, inf> flw;
  for (pair<int, int> e : candidate_edges) {
    int x = e.first, y = e.second;
    if (__builtin_popcount(x) & 1) swap(x, y);
    x = lower_bound(vertices.begin(), vertices.end(), x) - vertices.begin();
    y = lower_bound(vertices.begin(), vertices.end(), y) - vertices.begin();
    flw.add(x, y, 1, 0);
  }
  for (int i = 0; i < vertices.size(); i++) {
    int x = vertices[i];
    if (__builtin_popcount(x) & 1)
      flw.add(i, snk, 1, -a[x]);
    else
      flw.add(src, i, 1, -a[x]);
  }
  return cout << -flw.flow_with_limit(src, snk, k) << endl, 0;
}
