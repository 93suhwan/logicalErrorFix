#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10, inf = 1e9;
int n, m, tot, rt, ans[N];
struct Node {
  int lc, rc, mn, mx, val;
} t[N];
void up_(int o, int k) {
  t[o].val = t[o].mx = t[o].mn = inf;
  if (t[o].lc) {
    t[o].val = min(t[o].val, t[t[o].lc].val);
    t[o].mn = min(t[o].mn, t[t[o].lc].mn);
    t[o].mx = min(t[o].mx, t[t[o].lc].mx + (1 << k - 1));
  }
  if (t[o].rc) {
    t[o].val = min(t[o].val, t[t[o].rc].val);
    t[o].mn = min(t[o].mn, t[t[o].rc].mn + (1 << k - 1));
    t[o].mx = min(t[o].mx, t[t[o].rc].mx);
  }
  if (t[o].lc && t[o].rc)
    t[o].val = min(t[o].val, t[t[o].lc].mx + t[t[o].rc].mn);
}
void insert_(int &o, int k, int x) {
  if (!o) o = ++tot;
  if (!k) {
    t[o].mn = t[o].mx = 0, t[o].val = inf;
    return;
  }
  if ((x >> k - 1) & 1)
    insert_(t[o].rc, k - 1, x);
  else
    insert_(t[o].lc, k - 1, x);
  up_(o, k);
}
void upd_(int o, int k, int d) {
  if (k == d) {
    swap(t[o].lc, t[o].rc), up_(o, k);
    return;
  }
  if (t[o].lc) upd_(t[o].lc, k - 1, d);
  if (t[o].rc) upd_(t[o].rc, k - 1, d);
  up_(o, k);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int x, i = 1; i <= n; i++) scanf("%d", &x), insert_(rt, m, x);
  ans[0] = t[rt].val;
  for (int i = 1; i < (1 << m); i++) {
    for (int j = 0; j < m; j++)
      if ((i ^ (i - 1)) & (1 << j)) upd_(rt, m, m - j);
    int cur = 0;
    for (int j = 0; j < m; j++)
      if (i & (1 << j)) cur |= 1 << m - j - 1;
    ans[cur] = t[rt].val;
  }
  for (int i = 0; i < (1 << m); i++) printf("%d ", ans[i] + 1);
}
