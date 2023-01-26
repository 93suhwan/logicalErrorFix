#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, q;
int a[N];
int pre[N], nxt[N];
int sq;
int cnt;
int c[N], f[N];
int calc_nxt(int x) {
  int ret = x;
  for (int i = 1; i <= sq; ++i) {
    ret = nxt[ret];
  }
  return ret;
}
int calc_pre(int x) {
  int ret = x;
  for (int i = 1; i <= sq; ++i) {
    ret = pre[ret];
  }
  return ret;
}
void start_over(int x) {
  int cnt = 0;
  for (int i = 1; i <= 2 * sq + 2; ++i) {
    ++cnt;
    c[cnt] = x;
    x = nxt[x];
  }
  for (int i = 1; i <= sq + 2; ++i) {
    int p = c[i], q = c[i + sq];
    f[p] = q;
  }
}
int main() {
  scanf("%d%d", &n, &q);
  sq = sqrt(n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    nxt[i] = a[i];
    pre[a[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    f[i] = calc_nxt(i);
  }
  while (q--) {
    int op, x, y;
    scanf("%d%d%d", &op, &x, &y);
    if (op == 1) {
      int pos1 = calc_pre(x);
      int pos2 = calc_pre(y);
      nxt[x] = a[y];
      pre[a[y]] = x;
      nxt[y] = a[x];
      pre[a[x]] = y;
      swap(a[x], a[y]);
      start_over(pos1);
      start_over(pos2);
    } else {
      int ret = x;
      for (; y > sq; y -= sq) {
        ret = f[ret];
      }
      for (; y; --y) {
        ret = nxt[ret];
      }
      printf("%d\n", ret);
    }
  }
}
