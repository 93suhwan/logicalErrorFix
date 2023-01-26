#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, q;
int a[N];
int pre[N], nxt[N];
int sq;
int num;
int cnt;
int now;
int c[N], f[N], t[N];
vector<int> need_resolve;
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
int main() {
  scanf("%d%d", &n, &q);
  sq = sqrt(n);
  sq = min(sq, 150);
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
      need_resolve.clear();
      need_resolve.emplace_back(calc_pre(x));
      need_resolve.emplace_back(calc_pre(y));
      need_resolve.emplace_back(calc_pre(a[x]));
      need_resolve.emplace_back(calc_pre(a[y]));
      nxt[x] = a[y];
      pre[a[y]] = x;
      nxt[y] = a[x];
      pre[a[x]] = y;
      swap(a[x], a[y]);
      need_resolve.emplace_back(calc_pre(a[x]));
      need_resolve.emplace_back(calc_pre(a[y]));
      for (auto u : need_resolve) {
        t[1] = u;
        for (int i = 2; i <= 2 * sq + 2; ++i) {
          t[i] = nxt[t[i - 1]];
        }
        for (int i = 1; i <= sq + 2; ++i) {
          f[t[i]] = t[i + sq];
        }
      }
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
