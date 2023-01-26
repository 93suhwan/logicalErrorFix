#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
struct debug {
  ~debug() { cerr << endl; }
  template <class c>
  debug& operator<<(c x) {
    cerr << x;
    return *this;
  }
  template <class c, class d>
  debug& operator<<(pair<c, d> x) {
    *this << "(" << x.first << ", " << x.second << ")";
    return *this;
  }
  template <class c>
  debug& operator<<(vector<c> x) {
    *this << "[";
    int f = 0;
    for (auto it : x) {
      *this << (f ? ", " : "");
      *this << it;
      f = 1;
    }
    *this << "]";
    return *this;
  };
};
struct SegTree {
  vector<i64> tree;
  i64 n;
  SegTree(i64 _n) {
    n = _n;
    tree = vector<i64>(4 * n + 4);
  }
  i64 merge(i64 a, i64 b) { return a + b; }
  void update(i64 uIdx, i64 val, i64 idx, i64 l, i64 r) {
    if (l == r) {
      tree[idx] = val;
      return;
    }
    i64 mid = (l + r) / 2;
    if (uIdx <= mid)
      update(uIdx, val, 2 * idx, l, mid);
    else
      update(uIdx, val, 2 * idx + 1, mid + 1, r);
    tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
  }
  void update(i64 pos, i64 val) { update(pos, val, 1, 1, n); }
  i64 query(i64 ql, i64 qr, i64 idx, i64 l, i64 r) {
    if (ql > qr) return 0;
    if (ql == l && qr == r) {
      return tree[idx];
    }
    i64 mid = (l + r) / 2;
    return merge(query(ql, min(qr, mid), 2 * idx, l, mid),
                 query(max(ql, mid + 1), qr, 2 * idx + 1, mid + 1, r));
  }
  i64 query(i64 ql, i64 qr) { return query(ql, qr, 1, 1, n); }
};
const int N = 1e5 + 5;
vector<int> G[N];
vector<int> start(N);
vector<int> finish(N);
int timer = 1;
int lca[N][24];
void dfs(int cur, int p = 0) {
  lca[cur][0] = p;
  for (int i = 1; i < 22; i++) {
    lca[cur][i] = lca[lca[cur][i - 1]][i - 1];
  }
  start[cur] = timer++;
  for (int to : G[cur]) {
    if (to != p) {
      dfs(to, cur);
    }
  }
  finish[cur] = timer++;
}
bool isAncestor(int u, int v) {
  return start[u] <= start[v] && finish[u] >= finish[v];
}
int findLca(int u, int v) {
  if (isAncestor(u, v)) return u;
  if (isAncestor(v, u)) return v;
  for (int i = 21; i >= 0; i--) {
    if (!isAncestor(lca[u][i], v)) {
      u = lca[u][i];
    }
  }
  return lca[u][0];
}
int main() {
  finish[0] = 1000000000;
  int n, q;
  scanf("%d%d", &n, &q);
  vector<int> a(n + 3);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    a[i] = abs(a[i]);
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1);
  SegTree tree(2 * n + 2);
  for (int i = 1; i <= n; i++) {
    tree.update(start[i], a[i]);
    tree.update(finish[i], -a[i]);
  }
  while (q--) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int u, c;
      scanf("%d%d", &u, &c);
      c = abs(c);
      a[u] = c;
      tree.update(start[u], c);
      tree.update(finish[u], -c);
    } else {
      int u, v;
      scanf("%d%d", &u, &v);
      if (u == v) {
        puts("0");
      } else if (isAncestor(u, v)) {
        printf("%lld\n",
               a[u] + a[v] + 2 * tree.query(start[u] + 1, start[v] - 1));
      } else if (isAncestor(v, u)) {
        printf("%lld\n",
               a[u] + a[v] + 2 * tree.query(start[v] + 1, start[u] - 1));
      } else {
        int l = findLca(u, v);
        i64 ans = a[u] + a[l] + 2 * tree.query(start[l] + 1, start[u] - 1);
        ans += a[l] + a[v] + 2 * tree.query(start[l] + 1, start[v] - 1);
        printf("%lld\n", ans);
      }
    }
  }
}
