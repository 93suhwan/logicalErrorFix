#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10, INF = 0x3f3f3f3f;
inline int read() {
  int w = 0, r = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') r = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    w = (w << 1) + (w << 3) + (ch ^ 48);
    ch = getchar();
  }
  return w * r;
}
int n;
int a[N], b[N], pnt[N], pos[N];
struct line {
  int ed, nxt, w;
} li[64 * N];
int head[8 * N], cnt;
inline void add(int u, int v, int w) {
  li[++cnt] = (line){v, head[u], w};
  head[u] = cnt;
}
int mx;
void pre(int k, int l, int r) {
  mx = max(mx, k);
  if (l == r) {
    pos[l] = k;
    return;
  }
  int mid = (l + r) >> 1;
  pre(k << 1, l, mid);
  pre(k << 1 | 1, mid + 1, r);
}
int id[8 * N], idd[8 * N];
void build(int k, int l, int r) {
  if (l == r) {
    id[k] = l + n;
    idd[k] = pos[pnt[l]];
    add(k, mx + idd[k], 0);
    add(mx + idd[k], idd[k], 0);
    return;
  }
  idd[k] = k;
  int mid = (l + r) >> 1;
  add(k, k << 1, 0);
  add(k, k << 1 | 1, 0);
  build(k << 1, l, mid);
  build(k << 1 | 1, mid + 1, r);
}
void join(int k, int l, int r, int x, int y, int v) {
  if (x > y) return;
  if (x <= l && r <= y) {
    add(mx + pos[v], k, 1);
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid) join(k << 1, l, mid, x, y, v);
  if (y > mid) join(k << 1 | 1, mid + 1, r, x, y, v);
}
deque<int> q;
int dis[8 * N], ppre[8 * N];
bool flg[8 * N];
vector<int> pth;
void bfs() {
  memset(dis, 0x3f, sizeof(dis));
  dis[pos[n]] = 0;
  q.push_front(pos[n]);
  while (!q.empty()) {
    int u = q.front();
    q.pop_front();
    flg[u] = 1;
    for (int i = head[u]; i; i = li[i].nxt) {
      int v = li[i].ed, w = li[i].w;
      if (dis[v] <= dis[u] + w || flg[v]) continue;
      dis[v] = dis[u] + w;
      if (w == 0)
        q.push_front(v);
      else
        q.push_back(v);
      ppre[v] = u;
    }
  }
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++) {
    b[i] = read();
    pnt[i] = i + b[i];
  }
  pre(1, 0, n);
  build(1, 0, n);
  for (int i = 1; i <= n; i++) {
    join(1, 0, n, i - a[i], i, i);
  }
  bfs();
  if (dis[pos[0]] == INF) {
    puts("-1");
    return 0;
  }
  printf("%d\n", dis[pos[0]]);
  for (int nw = pos[0]; nw != pos[n]; nw = ppre[nw]) {
    if (id[nw] != 0) {
      pth.emplace_back(id[nw] - n);
    }
  }
  reverse(pth.begin(), pth.end());
  for (auto x : pth) printf("%d ", x);
  puts("");
  return 0;
}
