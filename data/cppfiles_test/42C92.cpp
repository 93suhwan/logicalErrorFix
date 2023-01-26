#include <bits/stdc++.h>
using namespace std;
int n, m;
struct node {
  int l, r, w;
} a[300010];
bool cmp(node x, node y) { return x.w < y.w; }
int tree[4000010], tag[4000010];
void pushdown(int now) {
  tag[now << 1] += tag[now];
  tag[now << 1 | 1] += tag[now];
  tree[now << 1] += tag[now];
  tree[now << 1 | 1] += tag[now];
  tag[now] = 0;
}
void modify(int now, int l, int r, int ql, int qr, int val) {
  if (ql <= l && qr >= r) {
    tree[now] += val, tag[now] += val;
    return;
  }
  pushdown(now);
  int mid = (l + r) >> 1;
  if (ql <= mid) modify(now << 1, l, mid, ql, qr, val);
  if (mid < qr) modify(now << 1 | 1, mid + 1, r, ql, qr, val);
  tree[now] = min(tree[now << 1], tree[now << 1 | 1]);
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i].l >> a[i].r >> a[i].w;
  sort(a + 1, a + 1 + n, cmp);
  int lb, rb;
  lb = 1, rb = 1;
  modify(1, 1, m - 1, a[1].l, a[1].r, 1);
  int ans = 114514114;
  while (rb <= n) {
    if (tree[1] > 0) {
      ans = min(ans, a[rb].w - a[lb].w);
      if (ans == 0) {
        cout << 0;
        return 0;
      }
      modify(1, 1, m - 1, a[lb].l, a[lb].r - 1, -1);
      lb++;
    } else {
      rb++;
      if (rb <= n) modify(1, 1, m - 1, a[rb].l, a[rb].r - 1, 1);
    }
  }
  cout << ans << endl;
  return 0;
}
