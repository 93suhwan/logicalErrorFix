#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
int n;
int a[MAXN];
struct pt {
  int dest, offset, pos, ans;
} pts[MAXN], tmp[MAXN];
bool cmp_dest(const pt &a, const pt &b) { return a.dest < b.dest; }
bool cmp_offset(const pt &a, const pt &b) { return a.offset < b.offset; }
bool cmp_pos(const pt &a, const pt &b) { return a.pos < b.pos; }
inline int lowbit(int x) { return x & (-x); }
int tree[MAXN];
void add(int x, int p) {
  p++;
  while (p < MAXN) {
    tree[p] = max(tree[p], x);
    p += lowbit(p);
  }
}
void rem(int p) {
  p++;
  while (p < MAXN) {
    tree[p] = 0;
    p += lowbit(p);
  }
}
int query(int p) {
  int ret = 0;
  p++;
  while (p > 0) {
    ret = max(ret, tree[p]);
    p -= lowbit(p);
  }
  return ret;
}
void cdq(int l, int r) {
  if (l + 1 == r) return;
  int mid = (l + r) / 2;
  sort(pts + l, pts + mid, cmp_pos);
  cdq(l, mid);
  sort(pts + l, pts + mid, cmp_dest);
  sort(pts + mid, pts + r, cmp_dest);
  int ll = l;
  for (int i = mid; i < r; i++) {
    while (ll < mid && pts[ll].dest < pts[i].dest) {
      if (pts[ll].offset >= 0) add(pts[ll].ans, pts[ll].offset);
      ll++;
    }
    if (pts[i].offset >= 0)
      pts[i].ans = max(pts[i].ans, query(pts[i].offset) + 1);
  }
  for (int i = l; i < ll; i++)
    if (pts[i].offset >= 0) rem(pts[i].offset);
  sort(pts + mid, pts + r, cmp_pos);
  cdq(mid, r);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &pts[i].dest);
    pts[i].offset = i - pts[i].dest;
    pts[i].pos = i;
    if (pts[i].offset >= 0) pts[i].ans = 1;
  }
  cdq(1, n + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (pts[i].ans > ans) ans = pts[i].ans;
  printf("%d", ans);
  return 0;
}
