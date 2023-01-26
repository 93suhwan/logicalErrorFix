#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000010;
int n, m;
int a[MAXN];
int b[MAXN];
int p[MAXN];
void solve(int l, int r, int L, int R) {
  if (l > r) return;
  int mid = (l + r) / 2;
  int tmp = 0;
  for (int i = L + 1; i <= R; ++i)
    if (b[mid] > a[i]) tmp++;
  int minn = tmp, pos = L;
  for (int i = L + 1; i <= R; ++i) {
    if (b[mid] > a[i]) tmp--;
    if (b[mid] < a[i]) tmp++;
    if (tmp < minn) {
      minn = tmp, pos = i;
    }
  }
  p[mid] = pos;
  solve(l, mid - 1, L, pos);
  solve(mid + 1, r, pos + 1, R);
}
struct BIT {
  int len;
  int c[MAXN << 1];
  inline int lowbit(int x) { return x & (-x); }
  void clr(int l) {
    len = l;
    for (int i = 1; i <= len; ++i) c[i] = 0;
  }
  inline void upd(int x, int v) {
    while (x <= len) {
      c[x] += v;
      x += lowbit(x);
    }
  }
  inline int qry(int x) {
    int ret = 0;
    while (x) {
      ret += c[x];
      x -= lowbit(x);
    }
    return ret;
  }
} T;
struct node {
  int pos, val;
  node(int pp = 0, int vv = 0) { pos = pp, val = vv; }
} t[MAXN << 1];
int tot;
bool operator<(node a, node b) {
  return a.val == b.val ? a.pos > b.pos : a.val > b.val;
}
int main() {
  int testcase;
  scanf("%d", &testcase);
  while (testcase--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; ++i) {
      scanf("%d", &b[i]);
    }
    sort(b + 1, b + 1 + m);
    solve(1, m, 0, n);
    T.clr(n + m);
    int now = 1;
    tot = 0;
    for (int i = 1; i <= n; ++i) {
      while (p[now] < i && now <= m) tot++, t[tot] = node(tot, b[now]), now++;
      tot++, t[tot] = node(tot, a[i]);
    }
    while (now <= m) tot++, t[tot] = node(tot, b[now]), now++;
    assert(n + m == tot);
    sort(t + 1, t + 1 + tot);
    long long ans = 0;
    for (int i = 1; i <= tot; ++i) {
      ans += T.qry(t[i].pos);
      T.upd(t[i].pos, 1);
    }
    printf("%lld\n", ans);
  }
}
