#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline long long llread() {
  char ch = getchar();
  long long x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
struct Node {
  int l, r, id, del, f;
  inline bool operator<(const Node& rhs) const { return r < rhs.r; }
} a[200010];
int q[200010 * 8];
int L[200010];
inline void change(int l, int r, int o, int x, int y) {
  if (l == r) {
    q[o] += y;
    if (q[o] >= 1000000007) q[o] -= 1000000007;
    return;
  }
  int mid = l + r >> 1;
  if (x <= mid)
    change(l, mid, o * 2, x, y);
  else
    change(mid + 1, r, o * 2 + 1, x, y);
  q[o] = q[o * 2] + q[o * 2 + 1];
  if (q[o] >= 1000000007) q[o] -= 1000000007;
}
inline int query(int l, int r, int o, int x, int y) {
  if (x <= l && r <= y) {
    return q[o];
  }
  int mid = l + r >> 1, ret = 0;
  if (x <= mid) ret += query(l, mid, o * 2, x, y);
  if (y > mid) ret += query(mid + 1, r, o * 2 + 1, x, y);
  if (ret >= 1000000007) ret -= 1000000007;
  return ret;
}
int main() {
  int n = read();
  for (int i = (1); i <= (n); ++i) {
    a[i].l = read(), a[i].r = read();
    a[i].id = i, a[i].del = 1;
  }
  int m = read();
  for (int i = (1); i <= (m); ++i) {
    int x = read();
    a[x].del = 0;
  }
  sort(a + 1, a + n + 1);
  for (int i = (1); i <= (n); ++i) {
    a[i].f = query(1, 2 * n, 1, a[i].l, a[i].r) + 1;
    if (a[i].f >= 1000000007) a[i].f -= 1000000007;
    change(1, 2 * n, 1, a[i].l, a[i].f);
  }
  int lim = 0;
  for (int i = (n); i >= (1); --i) {
    if (!a[i].del) {
      if (a[i].l >= lim) {
        L[i] = lim;
        lim = a[i].l;
      } else {
        a[i].del = 1;
      }
    }
  }
  memset(q, 0, sizeof(q));
  int ans = 0;
  for (int i = (1); i <= (n); ++i) {
    if (!a[i].del) {
      ans += query(1, 2 * n, 1, L[i] + 1, a[i].r) + 1;
      if (ans >= 1000000007) ans -= 1000000007;
    }
    change(1, 2 * n, 1, a[i].l, a[i].f);
  }
  printf("%d\n", ans);
}
