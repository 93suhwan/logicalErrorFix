#include <bits/stdc++.h>
using namespace std;
int n, a[300010], b[300010];
int dp[300010], tre[300010 << 2], id[300010], lst[300010], vis[300010];
void change(int l, int r, int p, int pos, int v) {
  if (l == r) {
    if (!tre[p] || dp[tre[p] + b[tre[p]]] <= dp[v + b[v]]) {
      tre[p] = v;
    }
    return;
  }
  int mid = (l + r >> 1);
  if (pos <= mid)
    change(l, mid, p << 1, pos, v);
  else
    change(mid + 1, r, p << 1 | 1, pos, v);
  if (!tre[p << 1])
    tre[p] = tre[p << 1 | 1];
  else if (!tre[p << 1 | 1])
    tre[p] = tre[p << 1];
  else
    tre[p] = (dp[tre[p << 1] + b[tre[p << 1]]] <
              dp[tre[p << 1 | 1] + b[tre[p << 1 | 1]]])
                 ? tre[p << 1]
                 : tre[p << 1 | 1];
  return;
}
int query(int ll, int rr, int l, int r, int p) {
  if (ll <= l && r <= rr) {
    return tre[p];
  }
  int mid = (l + r >> 1), x = 0, y = 0;
  if (ll <= mid) x = query(ll, rr, l, mid, p << 1);
  if (rr >= mid + 1) y = query(ll, rr, mid + 1, r, p << 1 | 1);
  if (!x)
    return y;
  else if (!y)
    return x;
  else
    return (dp[x + b[x]] < dp[y + b[y]]) ? x : y;
}
vector<int> v[300010];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++)
    scanf("%d", &b[i]), id[i] = i, v[i + b[i]].push_back(i);
  sort(id + 1, id + n + 1, [](int x, int y) { return x - a[x] < y - a[y]; });
  for (int t = 1; t <= n; t++) {
    int i = id[t];
    vis[i] = 1;
    if (a[i] == i)
      dp[i] = 1;
    else {
      lst[i] = query(i - a[i], i, 1, n, 1);
      if (!lst[i])
        lst[i] = dp[i] = -1;
      else
        dp[i] = dp[lst[i] + b[lst[i]]] + 1;
    }
    if (dp[i] != -1) {
      for (auto j : v[i]) change(1, n, 1, j, j);
    }
  }
  if (dp[n] == -1)
    puts("-1");
  else {
    printf("%d\n", dp[n]);
    int x = n;
    while (dp[x] != 1) {
      printf("%d ", lst[x]);
      x = lst[x] + b[lst[x]];
    }
    puts("0");
  }
}
