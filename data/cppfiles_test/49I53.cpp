#include <bits/stdc++.h>
using namespace std;
int n, tree[10000001], a[1000001];
int get(int node, int l, int r, int x, int y) {
  if (x > y) return 0;
  if (l == x && r == y) return tree[node];
  int mid = (l + r) >> 1;
  if (y <= mid) return get(node << 1, l, mid, x, y);
  if (x > mid) return get(node << 1 | 1, mid + 1, r, x, y);
  return get(node << 1, l, mid, x, mid) +
         get(node << 1 | 1, mid + 1, r, mid + 1, y);
}
void add(int node, int l, int r, int x, int val) {
  tree[node] += val;
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (x <= mid)
    add(node << 1, l, mid, x, val);
  else
    add(node << 1 | 1, mid + 1, r, x, val);
}
int find(int node, int l, int r, int val) {
  if (val > tree[node]) return -1;
  if (l == r) return l;
  int mid = (l + r) >> 1, cl = tree[node << 1];
  if (val <= cl) return find(node << 1, l, mid, val);
  return find(node << 1 | 1, mid + 1, r, val - cl);
}
vector<int> e[1000001];
vector<tuple<int, int, int>> query[1000001];
int ans[1000001], c[1000001];
set<int> s[1000001];
void dfs(int x) {
  if (c[a[x]]) {
    s[c[a[x]]].erase(a[x]);
    add(1, 1, n, c[a[x]], -1);
  }
  s[++c[a[x]]].insert(a[x]);
  add(1, 1, n, c[a[x]], 1);
  for (auto t : query[x]) {
    int id, l, k;
    tie(id, l, k) = t;
    int tans = find(1, 1, n, k + get(1, 1, n, 1, l - 1));
    if (tans == -1)
      ans[id] = -1;
    else
      ans[id] = *s[tans].begin();
  }
  for (int nex : e[x]) dfs(nex);
  s[c[a[x]]].erase(a[x]);
  add(1, 1, n, c[a[x]], -1);
  if (--c[a[x]]) {
    s[c[a[x]]].insert(a[x]);
    add(1, 1, n, c[a[x]], 1);
  }
}
inline void TC() {
  int q;
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) e[i].clear(), query[i].clear();
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 2; i <= n; i++) {
    int p;
    scanf("%d", &p);
    e[p].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    int v, l, k;
    scanf("%d%d%d", &v, &l, &k);
    query[v].emplace_back(i, l, k);
  }
  dfs(1);
  for (int i = 1; i <= q; i++) printf("%d ", ans[i]);
  putchar('\n');
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) TC();
  return 0;
}
