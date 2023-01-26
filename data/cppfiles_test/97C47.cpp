#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
int n, q, f[MAXN];
int L[MAXN], R[MAXN], tot;
long long sum[MAXN], sz[MAXN];
int fa[MAXN], vis[MAXN];
vector<int> e[MAXN];
struct Qry {
  int v, k, idx;
  long long ans;
} qry[MAXN];
struct BIT {
  long long tree[MAXN];
  void update(int x, long long val) {
    for (; x <= n; x += (x & -x)) tree[x] += val;
  }
  long long query(int x) {
    long long ret = 0;
    for (; x; x -= (x & -x)) ret += tree[x];
    return ret;
  }
  long long query(int L, int R) { return query(R) - query(L - 1); }
} t1, t2;
struct Node {
  long long val;
  int idx;
  bool operator<(const Node& n2) const { return val < n2.val; }
};
priority_queue<Node> pq;
bool cmp1(const Qry& q1, const Qry& q2) { return q1.k > q2.k; }
bool cmp2(const Qry& q1, const Qry& q2) { return q1.idx < q2.idx; }
int Find(int x) {
  if (fa[x] == x) return x;
  return fa[x] = Find(fa[x]);
}
void Merge(int x, int y) {
  if (Find(x) == Find(y)) return;
  fa[Find(x)] = Find(y);
}
long long D(long long x, long long y) {
  if (y < 0) x = -x, y = -y;
  return (x < 0) ? (-((-x + y - 1) / y)) : (x / y);
}
void dfs(int u) {
  L[u] = ++tot;
  for (auto v : e[u]) {
    if (v == f[u]) continue;
    f[v] = u;
    dfs(v);
    sum[u]++;
  }
  R[u] = tot;
}
void solve() {
  dfs(1);
  for (int i = (1); i <= (n); i++) {
    fa[i] = i;
    sz[i] = 1;
  }
  for (int i = (1); i <= (n); i++) {
    pq.push((Node){D(sum[i] - sz[i], sz[i]), i});
  }
  for (int i = (1); i <= (q); i++) {
    Qry& now = qry[i];
    while (pq.size()) {
      Node cur = pq.top();
      if (cur.val < now.k) break;
      pq.pop();
      if (vis[cur.idx]) continue;
      vis[cur.idx] = 1;
      if (cur.idx == 1) continue;
      Merge(cur.idx, f[cur.idx]);
      int top = Find(cur.idx);
      long long nsz = sz[cur.idx] + t1.query(L[cur.idx], R[cur.idx]);
      long long nsum = sum[cur.idx] + t2.query(L[cur.idx], R[cur.idx]);
      t1.update(L[f[cur.idx]], nsz);
      if (f[top]) t1.update(L[f[top]], -nsz);
      t2.update(L[f[cur.idx]], nsum);
      if (f[top]) t2.update(L[f[top]], -nsum);
      if (vis[top]) continue;
      nsz = sz[top] + t1.query(L[top], R[top]);
      nsum = sum[top] + t2.query(L[top], R[top]);
      pq.push((Node){D(nsum - nsz, nsz), top});
    }
    int u = now.v;
    long long nsz = sz[u] + t1.query(L[u], R[u]);
    long long nsum = sum[u] + t2.query(L[u], R[u]);
    now.ans = nsum - nsz * now.k + now.k - nsz + 1;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n - 1); i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  scanf("%d", &q);
  for (int i = (1); i <= (q); i++) {
    scanf("%d%d", &qry[i].v, &qry[i].k);
    qry[i].idx = i;
  }
  sort(qry + 1, qry + 1 + q, cmp1);
  solve();
  sort(qry + 1, qry + 1 + q, cmp2);
  for (int i = (1); i <= (q); i++) {
    printf("%lld\n", qry[i].ans);
  }
  return 0;
}
