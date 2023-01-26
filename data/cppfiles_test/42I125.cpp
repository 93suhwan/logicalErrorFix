#include <bits/stdc++.h>
using namespace std;
int read() {
  int p = 0, f = 1;
  char c = getchar();
  while (c < 48 || c > 57) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= 48 && c <= 57) p = (p << 1) + (p << 3) + (c ^ 48), c = getchar();
  return p * f;
}
int n, m;
struct LINE {
  int l, r, w;
} line[300010];
int st[1000010 << 2], tag[1000010 << 2];
void pushdown(int rt) {
  tag[rt << 1] += tag[rt];
  tag[rt << 1 | 1] += tag[rt];
  st[rt] += tag[rt];
  tag[rt] = 0;
}
void pushup(int rt) { st[rt] = min(st[rt << 1], st[rt << 1 | 1]); }
void upd(int rt, int l, int r, int ql, int qr, int c) {
  pushdown(rt);
  if (l >= r) return;
  if (ql <= l && r <= qr) {
    tag[rt] += c;
    pushdown(rt);
    return;
  }
  int mid = (l + r) >> 1;
  upd(rt << 1, l, min(mid, r), ql, qr, c);
  upd(rt << 1 | 1, max(mid + 1, l), r, ql, qr, c);
  pushup(rt);
}
bool cmp(LINE x, LINE y) { return x.w < y.w; }
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) {
    line[i].l = read(), line[i].r = read(), line[i].w = read();
  }
  sort(line + 1, line + n + 1, cmp);
  int j = 1;
  int ans = 0x7fffffff;
  for (int i = 1; i <= n; i++) {
    while (j <= n && st[1] + tag[1] == 0) {
      upd(1, 1, m, line[j].l, line[j].r, 1);
      j++;
    }
    if (st[1] + tag[1] == 0) break;
    ans = min(ans, line[j - 1].w - line[i].w);
    upd(1, 1, m, line[i].l, line[i].r, -1);
  }
  printf("%d", ans);
  return 0;
}
