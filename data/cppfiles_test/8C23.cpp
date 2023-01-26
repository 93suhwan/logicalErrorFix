#include <bits/stdc++.h>
using namespace std;
const long long M = 1e5 + 1, m = 17;
vector<vector<long long> > g(M), bl(M, vector<long long>(m, 0));
vector<long long> vis(M), st(M), lt(M), depth(M), d(M), v(M);
long long timer, n;
class lazySegTreeForSum {
 public:
  class node {
   public:
    long long sum, lazySet, lazyIncrement;
    bool setAll;
    node() {
      sum = 0;
      setAll = false;
      lazyIncrement = 0;
    }
    void reset() {
      setAll = false;
      lazyIncrement = 0;
    }
  };
  long long n;
  vector<node> tree;
  lazySegTreeForSum(vector<long long> v) {
    n = (long long)1 << (long long)ceil(log2((long long)v.size()));
    tree.assign(2 * n, node());
    for (long long i = 0; i < (long long)v.size(); i++) {
      tree[i + n].sum = v[i];
    }
    build(1);
  }
  void build(long long u) {
    if (u < n) {
      build(2 * u);
      build(2 * u + 1);
      tree[u].sum = tree[2 * u].sum + tree[2 * u + 1].sum;
    }
  }
  void pushToChild(long long par, long long child) {
    if (tree[par].setAll) {
      tree[child].setAll = true;
      tree[child].lazySet = tree[par].lazySet;
      tree[child].lazyIncrement = tree[par].lazyIncrement;
    } else {
      tree[child].lazyIncrement += tree[par].lazyIncrement;
    }
  }
  void push(long long index, long long x, long long y) {
    if (tree[index].setAll) {
      tree[index].sum = (y - x + 1) * tree[index].lazySet;
    }
    tree[index].sum += (y - x + 1) * tree[index].lazyIncrement;
    if (x != y) {
      pushToChild(index, 2 * index);
      pushToChild(index, 2 * index + 1);
    }
    tree[index].reset();
  }
  void rangeSet(long long l, long long r, long long val) {
    lazySet(l, r, 1, 0, n - 1, val);
  }
  void rangeUpdate(long long l, long long r, long long val) {
    lazyUpdate(l, r, 1, 0, n - 1, val);
  }
  long long rangeSum(long long l, long long r) {
    return lazySum(l, r, 1, 0, n - 1);
  }
  void lazySet(long long a, long long b, long long index, long long x,
               long long y, long long val) {
    if (x > b || y < a) return;
    if (x >= a && y <= b) {
      tree[index].setAll = true;
      tree[index].lazySet = val;
      tree[index].lazyIncrement = 0;
      return;
    }
    push(index, x, y);
    long long mid = (x + y) / 2;
    lazySet(a, b, 2 * index, x, mid, val);
    lazySet(a, b, 2 * index + 1, mid + 1, y, val);
    push(2 * index, x, mid);
    push(2 * index + 1, mid + 1, y);
    tree[index].sum = tree[2 * index].sum + tree[2 * index + 1].sum;
  }
  void lazyUpdate(long long a, long long b, long long index, long long x,
                  long long y, long long val) {
    if (x > b || y < a) return;
    if (x >= a && y <= b) {
      tree[index].lazyIncrement += val;
      return;
    }
    push(index, x, y);
    long long mid = (x + y) / 2;
    lazyUpdate(a, b, 2 * index, x, mid, val);
    lazyUpdate(a, b, 2 * index + 1, mid + 1, y, val);
    push(2 * index, x, mid);
    push(2 * index + 1, mid + 1, y);
    tree[index].sum = tree[2 * index].sum + tree[2 * index + 1].sum;
  }
  long long lazySum(long long a, long long b, long long index, long long x,
                    long long y) {
    if (x > b || y < a) {
      return 0;
    }
    push(index, x, y);
    if (x >= a && y <= b) {
      return tree[index].sum;
    }
    long long mid = (x + y) / 2;
    return lazySum(a, b, 2 * index, x, mid) +
           lazySum(a, b, 2 * index + 1, mid + 1, y);
  }
};
void buildbl() {
  for (long long i = 1; i < m; i++) {
    for (long long j = 1; j <= n; j++) {
      bl[j][i] = bl[bl[j][i - 1]][i - 1];
    }
  }
}
void dfs(long long u) {
  vis[u] = 1;
  st[u] = ++timer;
  for (auto x : g[u]) {
    if (vis[x]) continue;
    d[x] = d[u] + v[x];
    bl[x][0] = u;
    depth[x] = depth[u] + 1;
    dfs(x);
  }
  lt[u] = timer;
}
long long getanc(long long a, long long k) {
  long long cur = a;
  for (long long i = m - 1; i >= 0; i--) {
    if (k & ((long long)1 << i)) {
      cur = bl[cur][i];
    }
  }
  return cur;
}
long long lca(long long a, long long b) {
  if (depth[a] != depth[b]) {
    if (depth[a] > depth[b]) {
      a = getanc(a, depth[a] - depth[b]);
    } else {
      b = getanc(b, depth[b] - depth[a]);
    }
  }
  if (a == b) {
    return a;
  }
  for (long long i = m - 1; i >= 0; i--) {
    if (bl[a][i] == bl[b][i]) {
      continue;
    }
    a = bl[a][i];
    b = bl[b][i];
  }
  return bl[a][0];
}
void solve() {
  long long q;
  cin >> n >> q;
  for (long long i = 1; i <= n; i++) {
    cin >> v[i];
    v[i] = abs(v[i]);
  }
  for (long long i = 0; i < n - 1; i++) {
    long long u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  d[1] = v[1];
  dfs(1);
  buildbl();
  timer++;
  vector<long long> temp(timer, 0);
  for (long long i = 1; i <= n; i++) {
    temp[st[i]] = d[i];
  }
  lazySegTreeForSum sg(temp);
  while (q--) {
    long long option;
    cin >> option;
    if (option == 1) {
      long long ind, val;
      cin >> ind >> val;
      sg.rangeUpdate(st[ind], lt[ind], abs(val) - v[ind]);
      v[ind] = abs(val);
    } else {
      long long a, b;
      cin >> a >> b;
      long long k = lca(a, b);
      long long ans = 0;
      ans += sg.rangeSum(st[a], st[a]);
      ans += sg.rangeSum(st[b], st[b]);
      ans -= 2 * sg.rangeSum(st[k], st[k]);
      ans += v[k];
      ans *= 2;
      ans -= v[a];
      ans -= v[b];
      cout << ans << '\n';
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tc;
  tc = 1;
  for (int i = 1; i <= tc; i++) {
    solve();
  }
  return 0;
}
