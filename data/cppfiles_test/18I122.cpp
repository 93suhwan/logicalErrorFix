#include <bits/stdc++.h>
using namespace std;
long long lowbit(long long x) { return x & -x; }
inline long long read() {
  char ch = getchar();
  long long p = 1, data = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') p = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    data = data * 10 + (ch ^ 48);
    ch = getchar();
  }
  return p * data;
}
void exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b)
    x = 1, y = 0;
  else {
    exgcd(b, a % b, y, x);
    y -= x * (a / b);
  }
}
inline long long qpow(long long a, long long b) {
  long long r = 1;
  while (b) {
    if (b & 1) r = a * r;
    a = a * a;
    b >>= 1;
  }
  return r;
}
const int mod = 1e9 + 7, maxn = 2e6 + 5;
int a[maxn], nxt[maxn];
int n, d;
struct SegmentTree {
  int tr[maxn << 2];
  inline void pushup(int rt) { tr[rt] = max(tr[rt << 1], tr[rt << 1 | 1]); }
  inline void build(int l, int r, int rt) {
    if (l == r) {
      tr[rt] = nxt[l - 1];
      return;
    }
    int mid = l + r >> 1;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
    pushup(rt);
  }
  inline int query(int l, int r, int rt, int L, int R) {
    if (L <= l && r <= R) return tr[rt];
    int mid = l + r >> 1, ret = 0;
    if (L <= mid) ret = max(ret, query(l, mid, rt << 1, L, R));
    if (mid < R) ret = max(ret, query(mid + 1, r, rt << 1 | 1, L, R));
    return ret;
  }
} St;
int main() {
  int T = read();
  while (T--) {
    n = read(), d = read();
    for (int i = 0; i < n; i++) a[i + n] = a[i] = read();
    nxt[2 * n] = 0x3f3f3f3f;
    for (int i = 2 * n - 1; i >= 0; i--)
      if (!a[i])
        nxt[i] = 0;
      else
        nxt[i] = nxt[min(2 * n, i + d)] + 1;
    St.build(1, 2 * n, 1);
    int ans = 0x3f3f3f3f;
    for (int i = 0; i < n; i++)
      ans = min(ans, St.query(1, 2 * n, 1, i + 1, i + 1 + n));
    printf("%d\n", ans >= 0x3f3f3f3f ? -1 : ans);
  }
  return 0;
}
