#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, q;
int pre[N], nxt[N];
int sq;
int num;
int cnt;
int now;
int c[N], f[N], t[N];
vector<int> need_resolve;
int calc_nxt(int x) {
  int k = sq;
  for (; k--;) {
    x = nxt[x];
  }
  return x;
}
int calc_pre(int x) {
  int k = sq;
  for (; k--;) {
    x = pre[x];
  }
  return x;
}
int main() {
  scanf("%d%d", &n, &q);
  sq = sqrt(n);
  sq = min(sq, 150);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", nxt + i);
    pre[nxt[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    f[i] = calc_nxt(i);
  }
  while (q--) {
    int op, x, y;
    scanf("%d%d%d", &op, &x, &y);
    int nx = nxt[x], ny = nxt[y];
    if (op == 1) {
      need_resolve.clear();
      need_resolve.emplace_back(calc_pre(x));
      need_resolve.emplace_back(calc_pre(y));
      need_resolve.emplace_back(calc_pre(nx));
      need_resolve.emplace_back(calc_pre(ny));
      nxt[x] = ny;
      pre[ny] = x;
      nxt[y] = nx;
      pre[nx] = y;
      need_resolve.emplace_back(calc_pre(nx));
      need_resolve.emplace_back(calc_pre(ny));
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
  return 0;
}
