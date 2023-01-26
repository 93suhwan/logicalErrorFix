#include <bits/stdc++.h>
using namespace std;
vector<int> edges[100005];
int parent[100005][20], sz[100005], depth[100005], in[100005], out[100005], sn;
bool visited[100005];
int t = 0;
void init(int s) {
  memset(visited, 0, sizeof(visited));
  sn = s;
}
int dfs(int u = 0) {
  sz[u] = 1;
  visited[u] = true;
  in[u] = t++;
  for (int i = 0; i < edges[u].size(); i++) {
    int c = edges[u][i];
    if (visited[c]) continue;
    visited[c] = true;
    parent[c][0] = u;
    depth[c] = depth[u] + 1;
    sz[u] += dfs(c);
  }
  out[u] = t;
  return sz[u];
}
void preCompSparseMatrix() {
  for (int i = 1; i < 20; i++) {
    for (int j = 0; j < sn; j++) {
      parent[j][i] = parent[parent[j][i - 1]][i - 1];
    }
  }
}
int LCA(int u, int v) {
  if (depth[v] < depth[u]) return LCA(v, u);
  int dif = depth[v] - depth[u];
  for (int i = 0; i < 20; i++) {
    if ((dif >> i) & 1) {
      v = parent[v][i];
    }
  }
  if (u == v) {
    return u;
  }
  for (int i = 19; i >= 0; i--) {
    if (parent[u][i] != parent[v][i]) {
      u = parent[u][i];
      v = parent[v][i];
    }
  }
  return parent[u][0];
}
long long st[4 * 100005], lazy[4 * 100005];
void update(int x, int y, long long v, int l, int r, int p) {
  if (lazy[p]) {
    st[p] += 1ll * (r - l + 1) * lazy[p];
    if (l != r) {
      lazy[2 * p + 1] += lazy[p];
      lazy[2 * p + 2] += lazy[p];
    }
    lazy[p] = 0;
  }
  if (l > y || r < x) return;
  if (l >= x && r <= y) {
    st[p] += 1ll * (r - l + 1) * v;
    if (l != r) {
      lazy[2 * p + 1] += v;
      lazy[2 * p + 2] += v;
    }
    return;
  }
  int m = (l + r) >> 1;
  update(x, y, v, l, m, 2 * p + 1);
  update(x, y, v, m + 1, r, 2 * p + 2);
  st[p] = st[2 * p + 1] + st[2 * p + 2];
  return;
}
void update(int x, int y, long long v) { update(x, y, v, 0, 100005, 0); }
long long getSum(int a, int b, int l, int r, int p) {
  if (lazy[p]) {
    st[p] += lazy[p] * (r - l + 1);
    if (l != r) {
      lazy[2 * p + 1] += lazy[p];
      lazy[2 * p + 2] += lazy[p];
    }
    lazy[p] = 0;
  }
  if (l > b || r < a) return 0;
  if (l >= a && r <= b) return st[p];
  int m = (l + r) >> 1;
  return getSum(a, b, l, m, 2 * p + 1) + getSum(a, b, m + 1, r, 2 * p + 2);
}
long long getSum(int a, int b) { return getSum(a, b, 0, 100005, 0); }
int N, Q;
long long arr[100005];
long long get(int a, int b) {
  int l = LCA(a, b);
  return getSum(in[a], in[a]) + getSum(in[b], in[b]) -
         2 * getSum(in[l], in[l]) + arr[l];
}
void change(int a, long long b) {
  update(in[a], out[a] - 1, b);
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> Q;
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    arr[i] = abs(arr[i]);
  }
  for (int i = 0; i < N - 1; ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  init(20);
  dfs(0);
  preCompSparseMatrix();
  for (int i = 0; i < N; ++i) {
    change(i, arr[i]);
  }
  for (int i = 0; i < Q; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    c = abs(c);
    if (a == 1) {
      b--;
      change(b, c - arr[b]);
      arr[b] = c;
    } else {
      b--;
      c--;
      cout << 2ll * get(b, c) - arr[b] - arr[c] << "\n";
    }
  }
  return 0;
}
