#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int n, m, a[N + 10], b[N + 10], p[N + 10];
int mi[N * 4 + 10], add[N * 4 + 10];
long long ans;
void pushdown(int p) {
  add[p * 2] += add[p], add[p * 2 + 1] += add[p];
  mi[p * 2] += add[p], mi[p * 2 + 1] += add[p];
  add[p] = 0;
}
void build(int p, int l, int r) {
  add[p] = 0;
  if (l == r) {
    mi[p] = l;
    return;
  }
  int mid = (l + r) >> 1;
  build(p * 2, l, mid);
  build(p * 2 + 1, mid + 1, r);
  mi[p] = min(mi[p * 2], mi[p * 2 + 1]);
}
void update(int p, int l, int r, int x, int y, int v) {
  if (x <= l && r <= y) {
    mi[p] += v, add[p] += v;
    return;
  }
  pushdown(p);
  int mid = (l + r) >> 1;
  if (x <= mid) update(p * 2, l, mid, x, y, v);
  if (y > mid) update(p * 2 + 1, mid + 1, r, x, y, v);
  mi[p] = min(mi[p * 2], mi[p * 2 + 1]);
}
bool cmp(int x, int y) { return a[x] < a[y]; }
int bit[N + 10], lsh[N + 10];
void Add(int x) {
  for (; x <= n; x += (x & -x)) bit[x]++;
}
int Ask(int x) {
  int ans = 0;
  for (; x; x -= (x & -x)) ans += bit[x];
  return ans;
}
void solve() {
  cin >> n >> m;
  ans = 0;
  for (int i = 1; i <= n; i++) bit[i] = 0;
  for (int i = 1; i <= n; i++) cin >> a[i], p[i] = i, lsh[i] = a[i];
  sort(lsh + 1, lsh + n + 1);
  int tot = unique(lsh + 1, lsh + n + 1) - lsh - 1;
  for (int i = 1; i <= n; i++) {
    int x = lower_bound(lsh + 1, lsh + tot + 1, a[i]) - lsh;
    ans += i - 1 - Ask(x);
    Add(x);
  }
  for (int j = 1; j <= m; j++) cin >> b[j];
  build(1, 0, n);
  sort(b + 1, b + m + 1);
  sort(p + 1, p + n + 1, cmp);
  for (int i = 1, j = 1, k = 1; i <= m; i++) {
    while (j <= n && a[p[j]] <= b[i]) update(1, 0, n, p[j++], n, -1);
    while (k <= n && a[p[k]] < b[i]) update(1, 0, n, 0, p[k++] - 1, 1);
    ans += mi[1];
  }
  printf("%lld\n", ans);
}
int main() {
  std::ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
}
