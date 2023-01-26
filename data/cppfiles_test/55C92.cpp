#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9;
const long long mod = 1e9 + 7;
struct node {
  long long id, l, r;
} a[300005];
struct node1 {
  pair<long long, long long> val, lazy;
} tree[2400005];
long long b[600005], pre[300005];
bool vis[300005];
vector<pair<long long, long long> > g[300005];
bool cmp(node a, node b) { return a.id < b.id; }
void up(long long p) {
  tree[p].val = max(tree[2 * p].val, tree[2 * p + 1].val);
}
void pushdown(long long p) {
  if (tree[p].lazy.first != 0) {
    tree[2 * p].lazy = tree[2 * p + 1].lazy = tree[p].lazy;
    tree[2 * p].val = tree[2 * p + 1].val = tree[p].lazy;
    tree[p].lazy = {0, 0};
  }
}
void update(long long l, long long r, long long p, pair<long long, long long> d,
            long long cl, long long cr) {
  if (cl > r || cr < l)
    return;
  else if (cl >= l && cr <= r) {
    tree[p].val = d;
    tree[p].lazy = d;
  } else {
    pushdown(p);
    long long mid = (cl + cr) / 2;
    update(l, r, 2 * p, d, cl, mid);
    update(l, r, 2 * p + 1, d, mid + 1, cr);
    up(p);
  }
}
pair<long long, long long> query(long long l, long long r, long long p,
                                 long long cl, long long cr) {
  if (cl > r || cr < l)
    return {0, 0};
  else if (cl >= l && cr <= r) {
    return tree[p].val;
  } else {
    pushdown(p);
    long long mid = (cl + cr) / 2;
    return max(query(l, r, 2 * p, cl, mid),
               query(l, r, 2 * p + 1, mid + 1, cr));
  }
}
void solve() {
  long long n, m, cnt = 0, ans = 0, flag = 0;
  cin >> n >> m;
  for (long long i = 1; i <= m; i++) {
    cin >> a[i].id >> a[i].l >> a[i].r;
    b[++cnt] = a[i].l, b[++cnt] = a[i].r;
  }
  sort(b + 1, b + 1 + cnt);
  cnt = unique(b + 1, b + 1 + cnt) - b - 1;
  for (long long i = 1; i <= m; i++) {
    a[i].l = lower_bound(b + 1, b + 1 + cnt, a[i].l) - b;
    a[i].r = lower_bound(b + 1, b + 1 + cnt, a[i].r) - b;
    g[a[i].id].push_back(make_pair(a[i].l, a[i].r));
  }
  for (long long i = 1; i <= n; i++) {
    long long ma = -1;
    for (auto c : g[i]) {
      pair<long long, long long> t = query(c.first, c.second, 1, 1, cnt);
      if (t.first > ma) {
        ma = t.first;
        pre[i] = t.second;
      }
    }
    if (ma + 1 > ans) {
      ans = ma + 1;
      flag = i;
    }
    for (auto c : g[i]) {
      update(c.first, c.second, 1, {ma + 1, i}, 1, cnt);
    }
  }
  cout << n - ans << '\n';
  while (flag != 0) {
    vis[flag] = 1;
    flag = pre[flag];
  }
  for (long long i = 1; i <= n; i++) {
    if (vis[i] == 0) cout << i << ' ';
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
