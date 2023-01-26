#include <bits/stdc++.h>
using namespace std;
const int maxn = 300005;
int n, m, need[maxn];
vector<pair<int, int> > row[maxn];
int dp[maxn], tr[maxn];
pair<int, int> tree[maxn * 8];
pair<int, int> lazy[maxn * 8];
void PushUp(int node) {
  if (tree[node * 2] > tree[node * 2 + 1])
    tree[node] = tree[node * 2];
  else
    tree[node] = tree[node * 2 + 1];
}
void PushDown(int node, int l, int r) {
  if (tree[node].first < lazy[node].first) tree[node] = lazy[node];
  if (l == r) return;
  if (lazy[node * 2].first < lazy[node].first) {
    lazy[node * 2] = lazy[node];
  }
  if (lazy[node * 2 + 1].first < lazy[node].first) {
    lazy[node * 2 + 1] = lazy[node];
  }
  lazy[node] = {0, 0};
}
void Update(int node, int l, int r, int u, int v, int id, int val) {
  PushDown(node, l, r);
  if (l > v || r < u) return;
  if (l >= u && r <= v) {
    if (tree[node].first < val) {
      tree[node] = {val, id};
    }
    if (lazy[node].first < val) {
      lazy[node] = {val, id};
    }
    return;
  }
  int mid = (l + r) >> 1;
  Update(node * 2, l, mid, u, v, id, val);
  Update(node * 2 + 1, mid + 1, r, u, v, id, val);
  PushUp(node);
}
pair<int, int> Get(int node, int l, int r, int u, int v) {
  PushDown(node, l, r);
  if (l > v || r < u) return {0, 0};
  if (l >= u && r <= v) return tree[node];
  int mid = (l + r) >> 1;
  pair<int, int> L = Get(node * 2, l, mid, u, v);
  pair<int, int> R = Get(node * 2 + 1, mid + 1, r, u, v);
  if (L.first > R.first) return L;
  return R;
}
void Solve(int Test) {
  cin >> n >> m;
  vector<int> v;
  for (int i = 1; i <= m; ++i) {
    int id, l, r;
    cin >> id >> l >> r;
    v.push_back(l), v.push_back(r);
    row[id].push_back({l, r});
  }
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  m = v.size();
  for (int i = 1; i <= n; ++i) {
    for (auto &p : row[i]) {
      int &l = p.first, &r = p.second;
      l = lower_bound(v.begin(), v.end(), l) - v.begin() + 1;
      r = lower_bound(v.begin(), v.end(), r) - v.begin() + 1;
      pair<int, int> cur = Get(1, 1, m, l, r);
      if (dp[i] < cur.first + 1) {
        dp[i] = cur.first + 1;
        tr[i] = cur.second;
      }
    }
    for (auto p : row[i]) {
      int l = p.first, r = p.second;
      Update(1, 1, m, l, r, i, dp[i]);
    }
  }
  int pos = 0;
  for (int i = 1; i <= n; ++i) {
    if (dp[i] > dp[pos]) {
      pos = i;
    }
  }
  int res = 0;
  while (pos) {
    need[pos] = 1;
    pos = tr[pos];
    res++;
  }
  cout << n - res << "\n";
  for (int i = 1; i <= n; ++i) {
    if (!need[i]) cout << i << " ";
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  if (fopen("CF"
            ".inp",
            "r")) {
    freopen(
        "CF"
        ".inp",
        "r", stdin);
    freopen(
        "CF"
        ".out",
        "w", stdout);
  }
  int test = 1;
  for (int i = 1; i <= test; ++i) {
    Solve(i);
  }
}
