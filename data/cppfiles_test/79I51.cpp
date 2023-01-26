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
int a[N], b[N], pnt[N], pos[N], fd[N];
struct line {
  int ed, nxt, w;
} li[40 * N];
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
    id[k] = l;
    fd[l] = k;
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
      if (w == 1) {
        if (dis[v] <= dis[u] + 1 || flg[v]) continue;
        dis[v] = dis[u] + 1;
        q.push_back(v);
        ppre[v] = u;
      } else {
        if (dis[v] <= dis[u] || flg[v]) continue;
        dis[v] = dis[u];
        q.push_front(v);
        ppre[v] = u;
      }
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
  pre(1, 1, n);
  build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    join(1, 1, n, max(1, i - a[i]), i - 1, i);
  }
  bfs();
  int ans = INF, lst = 0;
  for (int i = 1; i <= n; i++) {
    if (i - a[i] <= 0 && dis[mx + pos[i]] != INF &&
        ans > dis[mx + pos[i]] + 1) {
      ans = dis[mx + pos[i]] + 1;
      lst = mx + pos[i];
    }
  }
  if (ans == INF) {
    puts("-1");
    return 0;
  }
  printf("%d\n", ans);
  pth.emplace_back(0);
  int num = 0;
  for (int nw = lst; nw; nw = ppre[nw]) {
    if (id[nw] != 0 && id[nw] != n) {
      pth.emplace_back(id[nw]);
      num++;
    }
  }
  if (pth.size() != ans) {
    cout << lst << " " << mx << " " << fd[83389] << endl;
  }
  reverse(pth.begin(), pth.end());
  for (auto x : pth) printf("%d ", x);
  puts("");
  return 0;
}
