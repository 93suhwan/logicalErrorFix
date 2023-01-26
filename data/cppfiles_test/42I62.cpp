#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
const int maxn = 2e5 + 100;
const int mode = 1e9 + 7;
typedef struct ta {
  int a, b, id;
  bool operator<(const ta& o) const { return b < o.b; }
} per;
typedef struct tb {
  int l, r, sum;
} node;
typedef struct tc {
  int a, b, id;
  bool operator<(const tc& o) const { return a > o.a; }
} rr;
node shu[maxn * 4 * 20];
per si[maxn], se[maxn];
int t, n, dp[maxn], vis[maxn], sum[maxn], rk[maxn], top, root[maxn];
int clone(int p) {
  shu[++top] = shu[p];
  return top;
}
int change(int p, int l, int r, int pos, int x) {
  p = clone(p);
  shu[p].sum += x;
  if (l != r) {
    int mid = (l + r) / 2;
    if (pos <= mid)
      shu[p].l = change(shu[p].l, l, mid, pos, x);
    else
      shu[p].r = change(shu[p].r, mid + 1, r, pos, x);
  }
  return p;
}
int query(int p, int l, int r, int al, int ar) {
  if (ar < al) return 0;
  if (l >= al && r <= ar) return shu[p].sum;
  int temp = 0;
  int mid = (l + r) / 2;
  if (al <= mid) temp += query(shu[p].l, l, mid, al, ar);
  if (ar > mid) temp += query(shu[p].r, mid + 1, r, al, ar);
  return temp;
}
int build(int l, int r) {
  int p = ++top;
  shu[p].sum = 0;
  if (l == r) return p;
  int mid = (l + r) / 2;
  shu[p].l = build(l, mid);
  shu[p].r = build(mid + 1, r);
  return p;
}
signed main() {
  n = read();
  for (int i = 1; i <= n; ++i) {
    si[i].a = read();
    si[i].b = read();
    si[i].id = i;
  }
  t = read();
  int cnt = t;
  for (int i = 1; i <= t; ++i) {
    se[i].id = read();
    vis[se[i].id] = 1;
    se[i].a = si[se[i].id].a;
    se[i].b = si[se[i].id].b;
  }
  sort(se + 1, se + 1 + t);
  sort(si + 1, si + 1 + n);
  for (int i = 1; i <= n; ++i) rk[si[i].id] = i;
  priority_queue<rr> que;
  for (int i = 1; i <= t; ++i) {
    que.push((rr){se[i].a, se[i].b, se[i].id});
  }
  root[0] = build(1, n * 2);
  root[1] = change(root[0], 1, 2 * n, si[1].a, 1);
  dp[1] = 1;
  if (vis[si[1].id]) cnt--;
  if (cnt == 0) {
    cout << 1;
    return 0;
  }
  sum[1] = 1;
  int ans = 0;
  for (int i = 2; i <= n; ++i) {
    dp[i] = (query(root[i - 1], 1, 2 * n, si[i].a + 1, 2 * n) + 1) % mode;
    sum[i] = (sum[i - 1] + dp[i]) % mode;
    root[i] = change(root[i - 1], 1, 2 * n, si[i].a, dp[i]);
  }
  int temp = se[t].a, sign = rk[se[t].id];
  ans = sum[rk[se[t].id] - 1];
  while (!que.empty() && que.top().a <= temp) {
    vis[que.top().id] = 0;
    que.pop();
  }
  for (int i = t - 1; i >= 1; --i) {
    if (vis[se[i].id] == 0) continue;
    int tl = temp + 1, tr = n * 2;
    ans = (ans + 1 + query(root[rk[se[i].id] - 1], 1, 2 * n, tl, tr)) % mode;
    temp = se[i].a;
    vis[se[i].id] = 0;
    while (!que.empty() && que.top().a <= temp) {
      vis[que.top().id] = 0;
      que.pop();
    }
  }
  cout << ans + 1;
}
