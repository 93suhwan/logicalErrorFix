#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5, M = 5e6;
int n, tot, a[N], b[N], vis[M], d[M], p[M], rev[M];
vector<int> e0[M], e1[M];
void build(int l, int r, int pos) {
  if (pos != 1) e0[n + pos / 2].push_back(n + pos);
  if (l == r) {
    e0[n + pos].push_back(l + b[l]);
    rev[n + pos] = l;
    return;
  }
  int mid = l + r >> 1;
  build(l, mid, pos << 1);
  build(mid + 1, r, pos << 1 | 1);
}
void upd(int l, int r, int pos, int L, int R, int x) {
  if (L <= l && r <= R) return e1[x].push_back(pos + n);
  int mid = l + r >> 1;
  if (L <= mid) upd(l, mid, pos << 1, L, R, x);
  if (R > mid) upd(mid + 1, r, pos << 1 | 1, L, R, x);
}
void print(int x) {
  if (x == n) return;
  print(p[x]);
  if (rev[x]) printf("%d ", rev[x]);
}
signed main() {
  scanf("%d", &n);
  tot = n;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  build(1, n, 1);
  for (int i = 1; i <= n; i++) {
    if (a[i] >= i) e1[i].push_back(0);
    upd(1, n, 1, max(1, i - a[i]), i, i);
  }
  queue<int> q0, q1;
  q0.push(n);
  while (1) {
    if (q0.empty()) return puts("-1"), 0;
    while (!q0.empty()) {
      int x = q0.front();
      q0.pop();
      if (vis[x]) continue;
      vis[x] = 1;
      if (x == 0) {
        printf("%d\n", d[0]);
        print(0);
        puts("0");
        return 0;
      }
      for (int y : e1[x])
        if (!vis[y] && !p[y]) p[y] = x, d[y] = d[x] + 1, q1.push(y);
      for (int y : e0[x])
        if (!vis[y]) p[y] = x, d[y] = d[x], q0.push(y);
    }
    swap(q0, q1);
  }
}
