#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int t, n, k, fa[N], mn[N];
vector<int> v;
struct node {
  int x, y, t, num;
} a[N];
bool cmp1(node x, node y) {
  if (x.x != y.x) return x.x < y.x;
  return x.y < y.y;
}
bool cmp2(node x, node y) {
  if (x.y != y.y) return x.y < y.y;
  return x.x < y.x;
}
int find(int x) {
  if (x == fa[x]) return x;
  return fa[x] = find(fa[x]);
}
void unionn(int x, int y) {
  int xx = find(x), yy = find(y);
  if (xx != yy) {
    fa[xx] = yy;
    mn[yy] = min(mn[yy], mn[xx]);
  }
}
bool check(int mid) {
  int res = 0;
  for (int i : v)
    if (mn[i] > mid) res++;
  return res <= mid + 1;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
      scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].t), fa[i] = i, mn[i] = a[i].t,
                                                  a[i].num = i;
    sort(a + 1, a + n + 1, cmp1);
    for (int i = 2; i <= n; i++) {
      if (a[i].x != a[i - 1].x) continue;
      if (a[i].y - a[i - 1].y <= k) unionn(a[i].num, a[i - 1].num);
    }
    sort(a + 1, a + n + 1, cmp2);
    for (int i = 2; i <= n; i++) {
      if (a[i].y != a[i - 1].y) continue;
      if (a[i].x - a[i - 1].x <= k) unionn(a[i].num, a[i - 1].num);
    }
    for (int i = 1; i <= n; i++)
      if (i == find(i)) v.push_back(i);
    int l = 0, r = n, ans = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (check(mid))
        ans = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    v.clear();
    printf("%d\n", ans);
  }
  return 0;
}
