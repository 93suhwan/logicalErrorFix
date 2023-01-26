#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &num) {
  T x = 0, f = 1;
  char ch = getchar();
  for (; ch > '9' || ch < '0'; ch = getchar())
    if (ch == '-') f = -1;
  for (; ch <= '9' && ch >= '0'; ch = getchar())
    x = (x << 3) + (x << 1) + (ch ^ '0');
  num = x * f;
}
const int inf = 0x3f3f3f3f;
int n, a[400005], b[400005], dp[400005], val[400005], lst[400005];
vector<int> v[400005];
struct segtree {
  int tr[400005 << 2];
  void build(int p, int l, int r) {
    if (l == r) return tr[p] = l, void();
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    tr[p] = l;
  }
  void update(int p, int l, int r, int x) {
    if (l == r) return tr[p] = l, void();
    int mid = (l + r) >> 1;
    if (x <= mid)
      update(p << 1, l, mid, x);
    else
      update(p << 1 | 1, mid + 1, r, x);
    tr[p] = val[tr[p << 1]] < val[tr[p << 1 | 1]] ? tr[p << 1] : tr[p << 1 | 1];
  }
  inline void upd(int &x, int y) {
    if (val[x] > val[y]) x = y;
  }
  int query(int p, int l, int r, int x, int y) {
    if (x <= l && r <= y) return tr[p];
    int mid = (l + r) >> 1, ret = 0;
    if (x <= mid) upd(ret, query(p << 1, l, mid, x, y));
    if (mid < y) upd(ret, query(p << 1 | 1, mid + 1, r, x, y));
    return ret;
  }
} T;
int main() {
  read(n);
  for (int i = 1; i <= n; i++) read(a[i]);
  for (int i = 1; i <= n; i++) read(b[i]);
  for (int i = 1; i <= n; i++) {
    v[i + b[i]].push_back(i);
  }
  memset(val, 0x3f, sizeof(val));
  memset(dp, 0x3f, sizeof(dp));
  T.build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    if (a[i] == i) {
      dp[i] = 1, lst[i] = 0;
    } else {
      int l = i - a[i] + b[i], r = i - 1;
      if (l > r) continue;
      int j = T.query(1, 1, n, l, r);
      if (val[j] != inf) {
        dp[i] = val[j] + 1;
        lst[i] = j;
      }
    }
    if (dp[i] != inf)
      for (auto j : v[i]) {
        val[j] = dp[i];
        T.update(1, 1, n, j);
      }
  }
  if (dp[n] == inf) return puts("-1"), 0;
  printf("%d\n", dp[n]);
  for (int i = n; i; i = lst[i]) {
    printf("%d ", lst[i]);
  }
  return 0;
}
