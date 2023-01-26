#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10, M = 1e6 + 10, mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int P = 131;
int n, m;
int sum[M * 4], lz[M * 4];
struct node {
  int l, r, w;
  bool operator<(const node &t) const { return w < t.w; }
} seg[N];
void pushdown(int rt) {
  int ls = rt << 1, rs = rt << 1 | 1;
  if (lz[rt]) {
    sum[ls] += lz[rt];
    lz[ls] += lz[rt];
    sum[rs] += lz[rt];
    lz[rs] += lz[rt];
    lz[rt] = 0;
  }
}
void update(int rt, int l, int r, int first, int second, int v) {
  if (l >= first && r <= second) {
    lz[rt] += v;
    sum[rt] += v;
    return;
  }
  pushdown(rt);
  int mid = l + r >> 1;
  if (first <= mid) update(rt << 1, l, mid, first, second, v);
  if (second > mid) update(rt << 1 | 1, mid + 1, r, first, second, v);
  sum[rt] = min(sum[rt << 1], sum[rt << 1 | 1]);
}
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> seg[i].l >> seg[i].r >> seg[i].w, seg[i].r--;
  sort(seg + 1, seg + n + 1);
  int res = INF;
  int j = 0;
  for (int i = 1; i <= n; i++) {
    while (j < n && sum[1] <= 0) {
      j++;
      update(1, 1, m - 1, seg[j].l, seg[j].r, 1);
    }
    if (j >= i && sum[1]) res = min(res, seg[j].w - seg[i].w);
    update(1, 1, m - 1, seg[i].l, seg[i].r, -1);
  }
  cout << res << "\n";
}
int main() {
  cin.tie(0), ios::sync_with_stdio(false);
  { solve(); }
  return 0;
}
