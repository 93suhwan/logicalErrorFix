#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, fh = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') fh = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * fh;
}
const int N = 2e6 + 5;
struct Edge {
  int to, next;
  long long val;
} e[N * 10];
int head[N], tot, lt[N], rt[N], rp, root[2], n, m, a[N], b[N], vis[N], pre[N];
int dis[N];
void connect(int x, int y, int v, int o) {
  if (!o) {
    e[++tot] = (Edge){y, head[x], v};
    head[x] = tot;
  } else {
    e[++tot] = (Edge){x, head[y], v};
    head[y] = tot;
  }
}
int build(int l, int r, int o) {
  if (l == r) return l;
  rp++;
  int k = rp, mid = (l + r) >> 1;
  lt[k] = build(l, mid, o), rt[k] = build(mid + 1, r, o);
  connect(k, lt[k], 0, o), connect(k, rt[k], 0, o);
  return k;
}
void add(int x, int y, int v, int l, int r, int L, int R, int o) {
  if (l >= L && r <= R) {
    connect(y, x, v, o);
    return;
  }
  int mid = (l + r) >> 1;
  if (L <= mid) add(lt[x], y, v, l, mid, L, R, o);
  if (R > mid) add(rt[x], y, v, mid + 1, r, L, R, o);
}
void bfs(int s) {
  deque<int> q;
  q.push_front(s);
  for (register int i = 0; i <= 5 * n; ++i) dis[i] = 1e9;
  dis[s] = 0;
  vis[s] = 1;
  while (!q.empty()) {
    int x = q.front();
    q.pop_front();
    for (int i = head[x]; i; i = e[i].next) {
      int p = e[i].to;
      if (vis[p]) continue;
      if (!e[i].val) q.push_front(p), vis[p] = 1, pre[p] = x, dis[p] = dis[x];
    }
    for (int i = head[x]; i; i = e[i].next) {
      int p = e[i].to;
      if (vis[p]) continue;
      if (e[i].val) q.push_back(p), vis[p] = 1, pre[p] = x, dis[p] = dis[x] + 1;
    }
  }
}
void dfs(int x) {
  if (x != 4 * n + n) dfs(pre[x]);
  if (x <= n) printf("%d ", x - 1);
}
int main() {
  cin >> n;
  ++n;
  rp = n;
  for (register int i = 2; i <= n; ++i) a[i] = read();
  for (register int i = 2; i <= n; ++i) b[i] = read();
  root[0] = build(1, n, 0);
  for (register int i = 2; i <= n; ++i)
    add(root[0], 4 * n + i, 1, 1, n, i - a[i], i, 0);
  for (register int i = 2; i <= n; ++i) connect(i, 4 * n + i + b[i], 0, 0);
  bfs(4 * n + n);
  int lim = 100;
  if (dis[1] < dis[0] - lim) {
    cout << dis[1] << endl;
    dfs(1);
  } else
    cout << -1;
  return 0;
}
