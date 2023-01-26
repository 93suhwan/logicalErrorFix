#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
const int INF = 1e7;
struct info {
  pair<int, int> x = {-INF, -1};
};
struct segtree {
  int n;
  vector<info> t;
  segtree(int n) {
    this->n = n;
    t.resize(n * 4);
  }
  void Merge(info &node, info &l, info &r) { node.x = max(l.x, r.x); }
  void update(int node, int l, int r, int i, int j, int add) {
    if (l > j || r < i) {
      return;
    }
    if (l >= i && r <= j) {
      t[node].x = {add, i};
      return;
    }
    int mid = (l + r) / 2;
    update(node * 2, l, mid, i, j, add);
    update(node * 2 + 1, mid + 1, r, i, j, add);
    Merge(t[node], t[node * 2], t[node * 2 + 1]);
  }
  void update(int l, int add) { update(1, 0, n - 1, l, l, add); }
  info query(int node, int l, int r, int i, int j) {
    if (l > j || r < i) {
      info x;
      return x;
    }
    if (l >= i && r <= j) {
      return t[node];
    }
    int mid = (l + r) / 2;
    info x = query(node * 2, l, mid, i, j);
    info y = query(node * 2 + 1, mid + 1, r, i, j);
    info ret;
    Merge(ret, x, y);
    return ret;
  }
  pair<int, int> query(int l, int r) {
    info ret = query(1, 0, n - 1, l, r);
    return ret.x;
  }
};
int n;
int a[N];
int b[N];
int dist[N][2];
vector<int> adj[N];
bool vis[N][2];
int p[N][2];
int go[N][2];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  segtree seg(n + 1);
  for (int i = 0; i <= n; i++) {
    dist[i][0] = INF;
    dist[i][1] = INF;
    seg.update(i, INF);
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  priority_queue<pair<int, pair<int, int> > > pq;
  pq.push({0, {n, 0}});
  dist[n][0] = 0;
  dist[n][1] = 0;
  seg.update(n, 0);
  while (!pq.empty()) {
    pair<int, pair<int, int> > t = pq.top();
    pq.pop();
    int v = t.second.first;
    int state = t.second.second;
    if (vis[v][state]) continue;
    vis[v][state] = 1;
    if (state == 1) {
      int koi = v + b[v];
      if (dist[koi][0] > dist[v][1]) {
        dist[koi][0] = dist[v][1];
        go[koi][0] = v;
        pq.push({-dist[koi][0], {koi, 0}});
      }
      continue;
    }
    int l = v - a[v];
    int r = v;
    while (true) {
      pair<int, int> x = seg.query(l, r);
      if (x.first <= dist[v][0] + 1) {
        break;
      }
      int koi = x.second;
      dist[koi][1] = dist[v][0] + 1;
      go[koi][1] = v;
      seg.update(koi, dist[koi][1]);
      pq.push({-dist[koi][1], {koi, 1}});
    }
  }
  if (dist[0][0] >= INF) {
    cout << "-1\n";
    return 0;
  }
  cout << dist[0][0] << "\n";
  pair<int, int> now = {0, 0};
  vector<int> ans;
  while (1) {
    if (now.second == 1) {
      ans.push_back(now.first);
    }
    if (now.first == n) {
      break;
    }
    now.first = go[now.first][now.second];
    now.second ^= 1;
  };
  reverse(ans.begin(), ans.end());
  for (int i : ans) cout << i << " ";
  cout << "\n";
  return 0;
}
