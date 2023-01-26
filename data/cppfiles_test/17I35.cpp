#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], b[maxn];
int tr[maxn << 2];
void build(int l, int r, int p) {
  tr[p] = 0;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(l, mid, p << 1);
  build(mid + 1, r, p << 1 | 1);
}
void update(int l, int r, int p, int x) {
  if (l == r) {
    tr[p]++;
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid)
    update(l, mid, p << 1, x);
  else
    update(mid + 1, r, p << 1 | 1, x);
  tr[p] = tr[p << 1] + tr[p << 1 | 1];
}
int query1(int l, int r, int p, int x) {
  if (l == r) return 0;
  int mid = (l + r) >> 1;
  if (x <= mid)
    return query1(l, mid, p << 1, x);
  else
    return tr[p << 1] + query1(mid + 1, r, p << 1 | 1, x);
}
int query2(int l, int r, int p, int x) {
  if (l == r) return 0;
  int mid = (l + r) >> 1;
  if (x <= mid)
    return tr[p << 1 | 1] + query2(l, mid, p << 1, x);
  else
    return query2(mid + 1, r, p << 1 | 1, x);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i), b[i] = a[i];
    sort(b, b + n);
    int len = unique(b, b + n) - b;
    int ans = 0;
    build(1, len, 1);
    for (int i = 0; i < n; ++i) {
      int pos = lower_bound(b, b + len, a[i]) - b + 1;
      update(1, len, 1, pos);
      ans += min(query1(1, len, 1, pos), query2(1, len, 1, pos));
    }
    printf("%d\n", ans);
  }
  return 0;
}
