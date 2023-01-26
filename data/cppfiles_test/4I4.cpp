#include <bits/stdc++.h>
using namespace std;
int tree[2][210000];
long long ans = 0;
vector<int> del;
void update(long long &x, long long y) {
  x += y;
  if (x > 1000000007) x -= 1000000007;
}
int lowbit(int x) { return x & (-x); }
void insert(int typ, int x) {
  x++;
  if (x <= 0) return;
  while (x < 210000) {
    del.push_back(x);
    tree[typ][x]++;
    x += lowbit(x);
  }
}
long long get(int typ, int x) {
  x++;
  if (x <= 0) return 0;
  long long ret = 0;
  while (x) {
    update(ret, tree[typ][x]);
    x -= lowbit(x);
  }
  return ret;
}
struct EDGE {
  int adj, next, w, valid;
} edge[2 * 210000];
int gh[210000], n, k, w[210000], top, maxdist, sizz[210000], son[210000];
void addedge(int x, int y, int w) {
  edge[++top].adj = y;
  edge[top].valid = 1;
  edge[top].w = w;
  edge[top].next = gh[x];
  gh[x] = top;
}
void get_size(int x, int root = 0) {
  sizz[x] = 1;
  son[x] = 0;
  int dd = 0;
  for (int p = gh[x]; p; p = edge[p].next)
    if (edge[p].adj != root && edge[p].valid) {
      get_size(edge[p].adj, x);
      sizz[x] += sizz[edge[p].adj];
      if (sizz[edge[p].adj] > dd) {
        dd = sizz[edge[p].adj];
        son[x] = edge[p].adj;
      }
    }
}
int getroot(int x) {
  get_size(x);
  int sz = sizz[x];
  while (sizz[son[x]] > sz / 2) x = son[x];
  return x;
}
vector<pair<long long, int> > q[210000][2];
void dfs(int x, int pre, int prec, long long sum, int cnt, int typ, int root) {
  if (cnt > k) return;
  update(sum, w[x]);
  q[root][typ].push_back(make_pair(sum, cnt));
  maxdist = max(maxdist, cnt + 5);
  for (int p = gh[x]; p; p = edge[p].next) {
    if (edge[p].valid == 0) continue;
    if (edge[p].adj == pre) continue;
    dfs(edge[p].adj, x, edge[p].w, sum, cnt + (edge[p].w != prec), typ, root);
  }
}
void dc(int x) {
  x = getroot(x);
  static int list[210000], ltop;
  ltop = 0;
  for (int p = gh[x]; p; p = edge[p].next)
    if (edge[p].valid) list[++ltop] = edge[p].adj;
  maxdist = 0;
  for (int p = gh[x]; p; p = edge[p].next) {
    if (edge[p].valid == 0) continue;
    q[edge[p].adj][0].clear();
    q[edge[p].adj][1].clear();
    dfs(edge[p].adj, x, edge[p].w, 0, 0, edge[p].w, edge[p].adj);
    for (auto t : q[edge[p].adj][0]) update(ans, t.first + w[x]);
    for (auto t : q[edge[p].adj][1]) update(ans, t.first + w[x]);
  }
  update(ans, w[x]);
  for (int t = 0; t <= 1; t++) {
    if (t == 1) reverse(list + 1, list + ltop + 1);
    del.clear();
    for (int i = 1; i <= ltop; i++) {
      long long delta = 0;
      if (t == 0) delta = w[x];
      for (auto p : q[list[i]][0])
        update(ans, (p.first + delta) *
                        (get(0, k - p.second) + get(1, k - p.second - 1)) %
                        1000000007);
      for (auto p : q[list[i]][1])
        update(ans, (p.first + delta) *
                        (get(1, k - p.second) + get(0, k - p.second - 1)) %
                        1000000007);
      for (auto p : q[list[i]][0]) insert(0, p.second);
      for (auto p : q[list[i]][1]) insert(1, p.second);
    }
    for (auto p : del) tree[0][p] = tree[1][p] = 0;
  }
  for (int p = gh[x]; p; p = edge[p].next)
    if (edge[p].valid) {
      edge[p].valid = 0;
      edge[p ^ 1].valid = 0;
      dc(edge[p].adj);
    }
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
  top = 1;
  for (int i = 1; i < n; i++) {
    int x, y, w;
    scanf("%d%d%d", &x, &y, &w);
    addedge(x, y, w);
    addedge(y, x, w);
  }
  dc(1);
  cout << ans << endl;
  return 0;
}
