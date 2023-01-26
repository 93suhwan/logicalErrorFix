#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
struct node {
  int x, y, id;
} a[N];
int t, fa[N], n, k, b[N], cnt, tim[N];
bool cmp1(const node &a, const node &b) {
  return a.x == b.x ? a.y < b.y : a.x < b.x;
}
bool cmp2(const node &a, const node &b) {
  return a.y == b.y ? a.x < b.x : a.y < b.y;
}
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void merge(int x, int y) {
  x = find(x);
  y = find(y);
  fa[x] = y;
  tim[y] = min(tim[y], tim[x]);
}
bool check(int x) {
  int p = upper_bound(b + 1, b + cnt + 1, x) - b;
  return (cnt - p <= x);
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &k);
    cnt = 0;
    for (int i = 1; i <= n; ++i) fa[i] = i, a[i].id = i;
    for (int i = 1; i <= n; ++i) scanf("%d%d%d", &a[i].x, &a[i].y, &tim[i]);
    sort(a + 1, a + n + 1, cmp1);
    for (int i = 1; i < n; ++i)
      if (a[i].x == a[i + 1].x && abs(a[i].y - a[i + 1].y) <= k)
        merge(a[i].id, a[i + 1].id);
    sort(a + 1, a + n + 1, cmp2);
    for (int i = 1; i < n; ++i)
      if (a[i].y == a[i + 1].y && abs(a[i].x - a[i + 1].x) <= k)
        merge(a[i].id, a[i + 1].id);
    for (int i = 1; i <= n; ++i)
      if (fa[i] == i) b[++cnt] = tim[i];
    sort(b + 1, b + cnt + 1);
    int l = 0, r = 1e9, mid, ans;
    while (l <= r) {
      mid = (l + r) >> 1;
      if (check(mid))
        ans = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}
