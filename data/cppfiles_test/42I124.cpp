#include <bits/stdc++.h>
#pragma warning(disable : 4996);
using namespace std;
const long long int MAXN = 1e5 + 10;
struct Tree {
  long long int l, r;
  long long int sum;
  long long int lazy;
  long long int maxn;
  long long int minn;
} t[MAXN << 2];
void push_up(long long int rt) {
  t[rt].sum = t[rt << 1].sum + t[rt << 1 | 1].sum;
  t[rt].maxn = max(t[rt << 1].maxn, t[rt << 1 | 1].maxn);
  t[rt].minn = min(t[rt << 1].minn, t[rt << 1 | 1].minn);
}
void push_down(long long int rt, long long int m) {
  if (t[rt].lazy) {
    t[rt << 1].lazy += t[rt].lazy;
    t[rt << 1 | 1].lazy += t[rt].lazy;
    t[rt << 1].sum += (m - (m >> 1)) * t[rt].lazy;
    t[rt << 1 | 1].sum += (m >> 1) * t[rt].lazy;
    t[rt << 1].minn += t[rt].lazy;
    t[rt << 1 | 1].minn += t[rt].lazy;
    t[rt << 1].maxn += t[rt].lazy;
    t[rt << 1 | 1].maxn += t[rt].lazy;
    t[rt].lazy = 0;
  }
}
void build(long long int l, long long int r, long long int rt) {
  t[rt].lazy = 0;
  t[rt].l = l;
  t[rt].r = r;
  if (l == r) {
    t[rt].sum = 0;
    t[rt].minn = t[rt].sum;
    t[rt].maxn = t[rt].sum;
    return;
  }
  long long int mid = (l + r) >> 1;
  build(l, mid, rt << 1);
  build(mid + 1, r, rt << 1 | 1);
  push_up(rt);
}
void update(long long int L, long long int R, long long int key,
            long long int rt) {
  if (L <= t[rt].l && R >= t[rt].r) {
    t[rt].sum += (t[rt].r - t[rt].l + 1) * key;
    t[rt].minn += key;
    t[rt].maxn += key;
    t[rt].lazy += key;
    return;
  }
  push_down(rt, t[rt].r - t[rt].l + 1);
  long long int mid = (t[rt].r + t[rt].l) >> 1;
  if (L <= mid) update(L, R, key, rt << 1);
  if (R > mid) update(L, R, key, rt << 1 | 1);
  push_up(rt);
}
long long int query(long long int L, long long int R, long long int rt) {
  if (L <= t[rt].l && R >= t[rt].r) {
    return t[rt].sum;
  }
  push_down(rt, t[rt].r - t[rt].l + 1);
  long long int mid = (t[rt].r + t[rt].l) >> 1;
  long long int ans = 0;
  if (L <= mid) ans += query(L, R, rt << 1);
  if (R > mid) ans += query(L, R, rt << 1 | 1);
  return ans;
}
long long int query_min(long long int L, long long int R, long long int rt) {
  if (L <= t[rt].l && R >= t[rt].r) {
    return t[rt].minn;
  }
  push_down(rt, t[rt].r - t[rt].l + 1);
  long long int mid = (t[rt].r + t[rt].l) >> 1;
  long long int ans = 0x3f3f3f3f;
  if (L <= mid) ans = min(ans, query_min(L, R, rt << 1));
  if (R > mid) ans = min(ans, query_min(L, R, rt << 1 | 1));
  return ans;
}
long long int query_max(long long int L, long long int R, long long int rt) {
  if (L <= t[rt].l && R >= t[rt].r) {
    return t[rt].maxn;
  }
  push_down(rt, t[rt].r - t[rt].l + 1);
  long long int mid = (t[rt].r + t[rt].l) >> 1;
  long long int ans = 0;
  if (L <= mid) ans = max(ans, query_max(L, R, rt << 1));
  if (R > mid) ans = max(ans, query_max(L, R, rt << 1 | 1));
  return ans;
}
struct zz {
  int l, r, w;
};
zz a[100010];
bool cmp(zz x, zz y) { return x.w < y.w; }
int main() {
  int n, m;
  cin >> n >> m;
  build(1, m, 1);
  int res = 2e9;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].l >> a[i].r >> a[i].w;
    a[i].r--;
  }
  sort(a + 1, a + n + 1, cmp);
  int pos = 0;
  while (query_min(1, m - 1, 1) == 0) {
    pos++;
    update(a[pos].l, a[pos].r, 1, 1);
  }
  int l = 1;
  int r = pos;
  while (l <= n && r <= n) {
    res = min(res, a[r].w - a[l].w);
    l++;
    update(a[l].l, a[l].r, -1, 1);
    while (query_min(1, m - 1, 1) == 0 && r <= n) {
      r++;
      update(a[r].l, a[r].r, 1, 1);
    }
  }
  cout << res;
  return 0;
}
