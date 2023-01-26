#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> edges;
int fa[200001], h[200001], t, in[200001], out[200001], val[200001], re[200001],
    tag[200001], v[200001];
int tree[800001], best[800001];
void dfs(int x, int pre) {
  fa[x] = pre;
  h[x] = h[pre] + 1;
  in[x] = ++t;
  re[t] = x;
  for (int &nex : edges[x]) {
    if (nex != pre) dfs(nex, x);
  }
  out[x] = t;
  if (t == in[x]) val[t] = h[x];
}
void build(int node, int l, int r) {
  if (l == r) {
    tree[node] = val[l];
    best[node] = l;
    return;
  }
  int mid = (l + r) >> 1;
  build(node << 1, l, mid);
  build(node << 1 | 1, mid + 1, r);
  if (tree[node << 1] >= tree[node << 1 | 1]) {
    tree[node] = tree[node << 1];
    best[node] = best[node << 1];
  } else {
    tree[node] = tree[node << 1 | 1];
    best[node] = best[node << 1 | 1];
  }
}
void erase(int node, int l, int r, int x) {
  if (l == r) {
    tree[l] = 0;
    return;
  }
  tag[node << 1] += tag[node];
  tag[node << 1 | 1] += tag[node];
  tag[node] = 0;
  int mid = (l + r) >> 1;
  if (x <= mid)
    erase(node << 1, l, mid, x);
  else
    erase(node << 1 | 1, mid + 1, r, x);
  if (tree[node << 1] + tag[node << 1] >=
      tree[node << 1 | 1] + tag[node << 1]) {
    tree[node] = tree[node << 1] + tag[node << 1];
    best[node] = best[node << 1];
  } else {
    tree[node] = tree[node << 1 | 1] + tag[node << 1 | 1];
    best[node] = best[node << 1 | 1];
  }
}
void dec(int node, int l, int r, int x, int y) {
  if (l == x && r == y) {
    tag[node]--;
    return;
  }
  tag[node << 1] += tag[node];
  tag[node << 1 | 1] += tag[node];
  tag[node] = 0;
  int mid = (l + r) >> 1;
  if (y <= mid)
    dec(node << 1, l, mid, x, y);
  else if (x > mid)
    dec(node << 1 | 1, mid + 1, r, x, y);
  else
    dec(node << 1, l, mid, x, mid), dec(node << 1 | 1, mid + 1, r, mid + 1, y);
  if (tree[node << 1] + tag[node << 1] >=
      tree[node << 1 | 1] + tag[node << 1]) {
    tree[node] = tree[node << 1] + tag[node << 1];
    best[node] = best[node << 1];
  } else {
    tree[node] = tree[node << 1 | 1] + tag[node << 1 | 1];
    best[node] = best[node << 1 | 1];
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  edges.resize(n + 1);
  long long ans = LLONG_MIN;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    edges[x].push_back(y);
    edges[y].push_back(x);
  }
  dfs(1, 0);
  build(1, 1, n);
  int w = 0;
  for (int i = 1; i <= k; i++) {
    int x = best[1];
    w += max(0, tree[1] + tag[1] - 1);
    w = min(n - i, w);
    ans = max(ans, (long long)w * (i - (n - w - i)));
    erase(1, 1, n, x);
    x = re[x];
    while (x && !v[x]) {
      v[x] = 1;
      dec(1, 1, n, in[x], out[x]);
      x = fa[x];
    }
  }
  cout << ans;
  return 0;
}
