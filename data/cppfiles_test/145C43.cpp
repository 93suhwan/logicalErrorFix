#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
const int N = 2e5 + 5;
int T, n, k, x[N], y[N], t[N], id[N], fa[N], rk[N], min_t[N];
void dsu_init(int n) {
  for (int i = 0; i <= n; ++i) fa[i] = i, rk[i] = 0;
}
inline int dsu_find(int x) {
  if (fa[x] == x)
    return x;
  else
    return fa[x] = dsu_find(fa[x]);
}
inline void dsu_merge(int x, int y) {
  x = dsu_find(x);
  y = dsu_find(y);
  if (x == y) return;
  if (rk[x] < rk[y])
    fa[x] = y;
  else if (rk[y] < rk[x])
    fa[y] = x;
  else
    fa[y] = x, rk[x]++;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%d %d %d", &x[i], &y[i], &t[i]);
      id[i] = i;
      min_t[i] = n;
    }
    dsu_init(n);
    sort(id + 1, id + n + 1, [&](int a, int b) {
      if (x[a] == x[b])
        return y[a] < y[b];
      else
        return x[a] < x[b];
    });
    for (int i = 2; i <= n; ++i) {
      if (x[id[i]] == x[id[i - 1]] && y[id[i]] - y[id[i - 1]] <= k) {
        dsu_merge(id[i], id[i - 1]);
      }
    }
    sort(id + 1, id + n + 1, [&](int a, int b) {
      if (y[a] == y[b])
        return x[a] < x[b];
      else
        return y[a] < y[b];
    });
    for (int i = 2; i <= n; ++i) {
      if (y[id[i]] == y[id[i - 1]] && x[id[i]] - x[id[i - 1]] <= k) {
        dsu_merge(id[i], id[i - 1]);
      }
    }
    for (int i = 1; i <= n; ++i) {
      int first = dsu_find(i);
      min_t[first] = min(min_t[first], t[i]);
    }
    vector<int> vc;
    for (int i = 1; i <= n; ++i) {
      if (fa[i] == i) {
        vc.emplace_back(min_t[i]);
      }
    }
    sort(vc.begin(), vc.end());
    reverse(vc.begin(), vc.end());
    int ans = -1;
    for (int i = 0; i < vc.size(); ++i) {
      if (i <= vc[i]) {
        ++ans;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
