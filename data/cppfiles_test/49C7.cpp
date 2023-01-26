#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
const int mod = 1e9 + 7;
const int oo = 1e9 + 7;
const long long lloo = 1e18 + 7;
const int N = 1e6 + 7;
void solve();
int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
int n;
vector<pair<pair<int, int>, int>> queries[N];
int ans[N];
int freq[N];
int a[N];
set<int> freqto[N];
vector<int> g[N];
const int MAX_VAL = N + 9;
int BITTree[MAX_VAL] = {0};
int seg[N * 4];
struct node {
  int l, r, mid, id;
  node(){};
  node(int l, int r, int id) : l(l), r(r), id(id) { mid = (l + r) >> 1; }
  node left() { return node(l, mid, id * 2); }
  node right() { return node(mid + 1, r, id * 2 + 1); }
  void add(int x, int val) {
    if (l == r) {
      seg[id] += val;
      return;
    }
    if (x <= mid)
      left().add(x, val);
    else
      right().add(x, val);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
  }
  int range(int L, int R) {
    if (l > R || r < L) return 0;
    if (l >= L && r <= R) return seg[id];
    return left().range(L, R) + right().range(L, R);
  }
  int query(int k) {
    if (l == r) {
      if (seg[id] == 0) return -1;
      return l;
    }
    if (seg[id * 2] >= k) return left().query(k);
    return right().query(k - seg[id * 2]);
  }
};
node segtree;
void add(int x) {
  segtree.add(freq[x], -1);
  if (freqto[freq[x]].find(x) != freqto[freq[x]].end())
    freqto[freq[x]].erase(x);
  freq[x]++;
  segtree.add(freq[x], +1);
  freqto[freq[x]].insert(x);
}
void del(int x) {
  segtree.add(freq[x], -1);
  if (freqto[freq[x]].find(x) != freqto[freq[x]].end())
    freqto[freq[x]].erase(x);
  freq[x]--;
  segtree.add(freq[x], +1);
  freqto[freq[x]].insert(x);
}
void dfs(int u, int p = -1, int len = 0) {
  add(a[u]);
  for (auto qq : queries[u]) {
    int id = qq.first.first;
    int l = qq.first.second;
    int k = qq.second;
    k += segtree.range(0, l - 1);
    int x = segtree.query(k);
    if (x == -1)
      ans[id] = -1;
    else
      ans[id] = *freqto[x].begin();
  }
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u, len + 1);
  }
  del(a[u]);
}
void solve() {
  int q;
  scanf("%d %d", &n, &q);
  segtree = node(0, N - 1, 1);
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    queries[i].clear();
  }
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 0; i < n - 1; i++) {
    int pi;
    scanf("%d", &pi);
    g[i + 2].push_back(pi);
    g[pi].push_back(i + 2);
  }
  for (int i = 0; i < q; i++) {
    int u, l, k;
    scanf("%d %d %d", &u, &l, &k);
    queries[u].push_back({{i, l}, k});
  }
  dfs(1);
  for (int i = 0; i < q; i++) printf("%d ", ans[i]);
  puts("");
}
