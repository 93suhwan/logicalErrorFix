#include <bits/stdc++.h>
using namespace std;
int read() {
  int ans = 0, o = 1;
  char c = getchar();
  for (; (c < '0' || c > '9') && c != '-'; c = getchar())
    ;
  if (c == '-') o *= -1, c = getchar();
  for (; '0' <= c && c <= '9'; c = getchar()) ans = ans * 10 + c - '0';
  return ans * o;
}
struct xd {
  int l, r, w;
};
int n, m;
xd a[300005];
bool cmp(xd x, xd y) { return x.w < y.w; }
struct point {
  int l, r;
  int data, lazy;
};
point t[4000005];
void build(int x, int a, int b) {
  int mid;
  t[x].l = a;
  t[x].r = b;
  if (a == b) return;
  mid = (a + b) / 2;
  build(2 * x, a, mid);
  build(2 * x + 1, mid + 1, b);
}
void down(int x) {
  int a, b;
  a = 2 * x;
  b = 2 * x + 1;
  t[a].data += t[x].lazy;
  t[b].data += t[x].lazy;
  t[a].lazy += t[x].lazy;
  t[b].lazy += t[x].lazy;
  t[x].lazy = 0;
}
void ins(int a, int b, int x) {
  if (a <= t[x].l && b >= t[x].r) {
    t[x].data++;
    t[x].lazy++;
    return;
  }
  int mid = (t[x].l + t[x].r) / 2;
  if (t[x].lazy != 0) down(x);
  if (a <= mid && b >= t[x].l) ins(a, b, 2 * x);
  if (a <= t[x].r && b >= mid + 1) ins(a, b, 2 * x + 1);
  t[x].data = min(t[2 * x].data, t[2 * x + 1].data);
}
void del(int a, int b, int x) {
  if (a <= t[x].l && b >= t[x].r) {
    t[x].data--;
    t[x].lazy--;
    return;
  }
  int mid = (t[x].l + t[x].r) / 2;
  if (t[x].lazy != 0) down(x);
  if (a <= mid && b >= t[x].l) del(a, b, 2 * x);
  if (a <= t[x].r && b >= mid + 1) del(a, b, 2 * x + 1);
  t[x].data = min(t[2 * x].data, t[2 * x + 1].data);
}
bool q() {
  if (t[1].data > 0)
    return true;
  else
    return false;
}
void Ins(int x) { ins(a[x].l, a[x].r - 1, 1); }
void Del(int x) { del(a[x].l, a[x].r - 1, 1); }
int main() {
  n = read(), m = read();
  build(1, 1, m - 1);
  for (int i = 1; i <= n; i++)
    a[i].l = read(), a[i].r = read(), a[i].w = read();
  sort(a + 1, a + n + 1, cmp);
  int j = 1;
  Ins(1);
  int ans = 1 << 30;
  for (int i = 1; i <= n; i++) {
    while (!q() && j < n) Ins(++j);
    if (!q()) break;
    ans = min(ans, a[j].w - a[i].w);
    Del(i);
  }
  printf("%d\n", ans);
  return 0;
}
