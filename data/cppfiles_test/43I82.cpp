#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
int n, m, ans = 2147483643;
int d[N << 6];
int mark[N << 6];
struct node {
  int l, r;
  int val;
} a[N];
void push(int x) {
  if (!mark[x]) return;
  d[(x << 1)] += mark[x];
  mark[(x << 1)] += mark[x];
  d[(x << 1 | 1)] += mark[x];
  mark[(x << 1 | 1)] += mark[x];
  mark[x] = 0;
  return;
}
void qc(int x, int l, int r, int st, int ed, int k) {
  if (st <= l && r <= ed) {
    d[x] += k;
    mark[x] += k;
    return;
  }
  push(x);
  if (st <= ((l + r) >> 1)) qc((x << 1), l, ((l + r) >> 1), st, ed, k);
  if (ed > ((l + r) >> 1)) qc((x << 1 | 1), ((l + r) >> 1) + 1, r, st, ed, k);
  d[x] = min(d[(x << 1)], d[(x << 1 | 1)]);
  return;
}
bool cmp(node x, node y) { return x.val < y.val; }
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  m--;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].l >> a[i].r >> a[i].val;
    a[i].r--;
  }
  sort(a + 1, a + 1 + n, cmp);
  int l = 0, r = 0;
  while (1) {
    while (r + 1 <= n && !d[1]) {
      r++;
      qc(1, 1, m, a[r].l, a[r].r, 1);
    }
    if (!d[1]) break;
    while (l + 1 <= r && d[1] > 0) {
      l++;
      qc(1, 1, m, a[l].l, a[l].r, -1);
    }
    ans = min(ans, a[r].val - a[l].val);
  }
  cout << ans;
  return 0;
}
