#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e6 + 5;
const int inf = 1e9;
int id = -1;
struct segtree {
  int tree[4 * mxn];
  void init(int n) {
    for (int i = 1; i <= 4 * n; i++) tree[i] = 0;
  }
  void update(int node, int b, int e, int p, int v) {
    if (e < p || b > p) return;
    if (b == e) {
      tree[node] += v;
      return;
    }
    int mid = b + e >> 1;
    int left = node << 1;
    int right = left | 1;
    update(left, b, mid, p, v);
    update(right, mid + 1, e, p, v);
    tree[node] = tree[left] + tree[right];
  }
  int query(int node, int b, int e, int l, int r) {
    if (e < l || b > r) return 0;
    if (b >= l && e <= r) return tree[node];
    int mid = b + e >> 1;
    int left = node << 1;
    int right = left | 1;
    return query(left, b, mid, l, r) + query(right, mid + 1, e, l, r);
  }
  int kth(int node, int b, int e, int k) {
    if (b == e) {
      if (k - tree[node] <= 0) return b;
      return -1;
    }
    int mid = b + e >> 1;
    int left = node << 1;
    int right = left | 1;
    if (tree[left] >= k) return kth(left, b, mid, k);
    return kth(right, mid + 1, e, k - tree[left]);
  }
} st;
int a[mxn];
vector<int> adj[mxn];
vector<tuple<int, int, int> > con[mxn];
int res[mxn];
int cnt[mxn] = {};
set<int> CV[mxn];
int n;
void dfs(int u) {
  st.update(1, 1, n, cnt[a[u]], -1);
  CV[cnt[a[u]]].erase(a[u]);
  cnt[a[u]]++;
  CV[cnt[a[u]]].insert(a[u]);
  st.update(1, 1, n, cnt[a[u]], 1);
  for (auto [l, k, i] : con[u]) {
    id = -1;
    int pv = st.query(1, 1, n, 1, l - 1);
    int x = st.kth(1, 1, n, k + pv);
    if (x != -1) {
      assert(!CV[x].empty());
      res[i] = *CV[x].begin();
    }
  }
  for (int v : adj[u]) {
    dfs(v);
  }
  st.update(1, 1, n, cnt[a[u]], -1);
  CV[cnt[a[u]]].erase(a[u]);
  cnt[a[u]]--;
  CV[cnt[a[u]]].insert(a[u]);
  st.update(1, 1, n, cnt[a[u]], 1);
}
void solve() {
  int q;
  scanf("%d%d", &n, &q);
  st.init(n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    con[i].clear();
    CV[i].clear();
    cnt[i] = 0;
    adj[i].clear();
  }
  for (int i = 2; i <= n; i++) {
    int x;
    scanf("%d", &x);
    adj[x].push_back(i);
  }
  for (int i = 1; i <= q; i++) {
    int v, l, k;
    scanf("%d%d%d", &v, &l, &k);
    con[v].push_back({l, k, i});
    res[i] = -1;
  }
  dfs(1);
  for (int i = 1; i <= q; i++) {
    printf("%d ", res[i]);
  }
  printf("\n");
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
