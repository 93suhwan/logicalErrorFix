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
vector<vector<int> > adj;
vector<pair<int, int> > l[N];
void TEST_CASES() {
  cin >> n;
  adj.resize(n + 1);
  segtree seg(n + 1);
  vector<pair<int, int> > all(n + 1);
  for (int i = 1; i <= n; i++) {
    l[i].push_back({-INF, -1});
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    all[i] = {i - a[i], i};
    l[i - a[i]].push_back({i, i});
  }
  for (int i = 1; i <= n; i++) {
    seg.update(i, l[i].back().first);
    ;
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    adj[i + b[i]].push_back(i);
  };
  vector<int> dp(n + 1, INF);
  dp[0] = 0;
  queue<int> q;
  vector<bool> vis(n + 1, 0);
  vector<int> go(n + 1, -1);
  for (int i = 1; i <= n; i++) {
    if (i - a[i] == 0) {
      for (int j : adj[i]) {
        dp[j] = 1;
        q.push(j);
        go[j] = 0;
      }
    }
  }
  while (!q.empty()) {
    int p = q.front();
    q.pop();
    if (vis[p]) continue;
    vis[p] = 1;
    while (1) {
      pair<int, int> xd = seg.query(1, p);
      if (xd.first < p) {
        break;
      }
      pair<int, int> now = l[xd.second].back();
      l[xd.second].pop_back();
      seg.update(xd.second, l[xd.second].back().first);
      int bal = now.second;
      for (int i : adj[bal]) {
        if (dp[i] > dp[p] + 1) {
          dp[i] = dp[p] + 1;
          q.push(i);
          go[i] = p;
        }
      }
    }
  }
  if (dp[n] >= INF) {
    cout << "-1\n";
    return;
  }
  cout << dp[n] << "\n";
  int now = n;
  while (go[now] != 0) {
    cout << go[now] << " ";
    now = go[now];
  }
  cout << 0 << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  while (t--) {
    TEST_CASES();
  }
  return 0;
}
