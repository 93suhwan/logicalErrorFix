#include <bits/stdc++.h>
using namespace std;
struct node {
  int l, r, w;
} len[1000017];
int n, m, lazy[1000017 << 2], sum[1000017 << 2];
bool cmp(node A, node B) {
  if (A.w == B.w) {
    if (A.l == B.l)
      return A.r < B.r;
    else
      return A.l < B.l;
  } else
    return A.w < B.w;
}
void modify(int k, int l, int r, int ql, int qr, int v) {
  if (l >= ql && r <= qr) {
    lazy[k] = v;
    sum[k] = v * (r - l + 1);
    return;
  }
  int mid = (l + r) >> 1;
  if (lazy[k] != -1) {
    lazy[k << 1] = lazy[k << 1 | 1] = lazy[k];
    sum[k << 1] = lazy[k] * (mid - l + 1);
    sum[k << 1 | 1] = lazy[k] * (r - mid);
    lazy[k] = -1;
  }
  if (ql <= mid) modify(k << 1, l, mid, ql, qr, v);
  if (mid < qr) modify(k << 1 | 1, mid + 1, r, ql, qr, v);
  sum[k] = sum[k << 1] + sum[k << 1 | 1];
}
bool check(int lim) {
  memset(lazy, -1, sizeof(lazy));
  memset(sum, 0, sizeof(sum));
  int nxt;
  for (int l = 1, r = 1; l <= n; l += 1) {
    while (len[r].w - len[l].w <= lim && r <= n) {
      if (len[r].r != m)
        nxt = len[r].r - 1;
      else
        nxt = m;
      modify(1, 1, m, len[r].l, nxt, 1);
      r++;
    }
    if (sum[1] == m) return 1;
    if (len[l].r != m)
      nxt = len[l].r - 1;
    else
      nxt = m;
    modify(1, 1, m, len[l].l, nxt, 0);
  }
  return 0;
}
int two_fen() {
  int l = 0, r = 1e6, opt = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (opt == mid) break;
    opt = mid;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  int minn = min(l, r), maxn = max(l, r);
  if (check(minn))
    return minn;
  else
    return maxn;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i += 1)
    scanf("%d%d%d", &len[i].l, &len[i].r, &len[i].w);
  sort(len + 1, len + n + 1, cmp);
  printf("%d\n", two_fen());
  return 0;
}
