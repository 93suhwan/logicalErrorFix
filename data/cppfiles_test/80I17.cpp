#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + c - '0';
  x *= f;
}
int t, n, m;
int a[N], b[N], lsh[N], tot;
int ra[N];
int bit[N];
long long ans;
struct misaka {
  int min, tag;
} seg[N << 2];
void upd(int o, int x) {
  for (; o <= tot; o += o & -o) bit[o] += x;
}
int ask(int o) {
  int res = 0;
  for (; o; o -= o & -o) res += bit[o];
  return res;
}
void pushdown(int u) {
  seg[(u << 1)].min += seg[u].tag;
  seg[(u << 1)].tag += seg[u].tag;
  seg[(u << 1 | 1)].min += seg[u].tag;
  seg[(u << 1 | 1)].tag += seg[u].tag;
  seg[u].tag = 0;
}
void build(int u, int l, int r) {
  seg[u].tag = 0;
  if (l == r) {
    seg[u].min = l;
    return;
  }
  int mid = l + r >> 1;
  build((u << 1), l, mid);
  build((u << 1 | 1), mid + 1, r);
  seg[u].min = min(seg[(u << 1)].min, seg[(u << 1 | 1)].min);
}
void update(int u, int l, int r, int ql, int qr, int k) {
  if (l >= ql && r <= qr) {
    seg[u].min += k, seg[u].tag += k;
    return;
  }
  if (seg[u].tag) pushdown(u);
  int mid = l + r >> 1;
  if (ql <= mid) update((u << 1), l, mid, ql, qr, k);
  if (qr > mid) update((u << 1 | 1), mid + 1, r, ql, qr, k);
  seg[u].min = min(seg[(u << 1)].min, seg[(u << 1 | 1)].min);
}
void print(int u, int l, int r) {
  if (l == r) {
    printf("%d ", seg[u].min);
    return;
  }
  if (seg[u].tag) pushdown(u);
  int mid = l + r >> 1;
  print((u << 1), l, mid);
  print((u << 1 | 1), mid + 1, r);
}
void solve() {
  read(n), read(m);
  for (int i = 1; i <= n; i++) read(a[i]);
  for (int i = 1; i <= m; i++) read(b[i]);
  tot = ans = 0;
  for (int i = 1; i <= n; i++) lsh[++tot] = a[i];
  for (int i = 1; i <= m; i++) lsh[++tot] = b[i];
  sort(lsh + 1, lsh + tot + 1);
  tot = unique(lsh + 1, lsh + tot + 1) - lsh - 1;
  for (int i = 1; i <= n; i++)
    a[i] = lower_bound(lsh + 1, lsh + tot + 1, a[i]) - lsh;
  for (int i = 1; i <= m; i++)
    b[i] = lower_bound(lsh + 1, lsh + tot + 1, b[i]) - lsh;
  sort(b + 1, b + m + 1);
  for (int i = 1; i <= n; i++) ra[a[i]] = i;
  for (int i = 1; i <= n; i++) {
    ans += i - 1 - ask(a[i]);
    upd(a[i], 1);
  }
  sort(a + 1, a + n + 1);
  build(1, 0, n);
  int now1 = 1, now2 = 1;
  for (int i = 1; i <= m; i++) {
    while (now1 <= n && a[now1] <= b[i]) {
      update(1, 0, n, ra[a[now1]], n, -1);
      now1++;
    }
    while (now2 <= n && a[now2] < b[i]) {
      update(1, 0, n, 0, ra[a[now2]] - 1, 1);
      now2++;
    }
    ans += seg[1].min;
  }
  for (int i = 1; i <= tot; i++) bit[i] = 0;
  printf("%lld\n", ans);
}
int main() {
  read(t);
  while (t--) solve();
  return 0;
}
