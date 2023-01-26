#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;
struct node {
  int l, r, mn, add;
} s[maxn * 4];
inline void pushup(int pos) {
  s[pos].mn = min(s[(pos << 1)].mn, s[(pos << 1 | 1)].mn);
}
inline void apptag(int pos, int add) {
  s[pos].add += add;
  s[pos].mn += add;
}
inline void pushdown(int pos) {
  if (!s[pos].add) return;
  apptag((pos << 1), s[pos].add);
  apptag((pos << 1 | 1), s[pos].add);
  s[pos].add = 0;
}
void build(int l, int r, int pos) {
  s[pos] = {l, r, 0, 0};
  if (l == r) return;
  int mid = l + r >> 1;
  build(l, mid, (pos << 1));
  build(mid + 1, r, (pos << 1 | 1));
}
void update(int l, int r, int add, int pos) {
  if (s[pos].l == l && s[pos].r == r) {
    apptag(pos, add);
    return;
  }
  pushdown(pos);
  int mid = s[pos].l + s[pos].r >> 1;
  if (r <= mid)
    update(l, r, add, (pos << 1));
  else if (l > mid)
    update(l, r, add, (pos << 1 | 1));
  else
    update(l, mid, add, (pos << 1)), update(mid + 1, r, add, (pos << 1 | 1));
  pushup(pos);
}
struct line {
  int l, r, w;
  bool operator<(const line &a) const { return w < a.w; }
} p[maxn];
int main() {
  int n, m;
  scanf("%d", &n);
  scanf("%d", &m);
  build(1, m - 1, 1);
  for (int i = (1); i <= (n); i++)
    scanf("%d", &p[i].l), scanf("%d", &p[i].r), scanf("%d", &p[i].w);
  sort(p + 1, p + n + 1);
  int ans = 1e9, j = 0;
  for (int i = (1); i <= (n); i++) {
    while (j + 1 <= n && s[1].mn <= 0) {
      j++;
      update(p[j].l, p[j].r - 1, 1, 1);
    }
    if (s[1].mn > 0) ans = min(ans, p[j].w - p[i].w);
    update(p[i].l, p[i].r - 1, -1, 1);
  }
  cout << ans;
}
