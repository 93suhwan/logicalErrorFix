#include <bits/stdc++.h>
using namespace std;
int abc;
mt19937 rnd(time(0));
int rd(int l, int r) {
  uniform_int_distribution<> ee(l, r);
  return ee(rnd);
}
const int mxn = 2e5 + 3, sq = 433;
int n, a[mxn], b[mxn], m, ee[sq][sq], ti[mxn], s[mxn], ans[mxn];
void add(int x, int l, int t) {
  if (x > m) return;
  x = max(x, l);
  s[x] += t;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) abc = scanf("%d%d", a + i, b + i);
  for (int t = 1; t <= m; ++t) {
    int o, x;
    abc = scanf("%d%d", &o, &x);
    if (o == 1) {
      ti[x] = t;
      int h = a[x] + b[x];
      if (h >= sq) {
        for (int e = t + a[x]; e <= m; e += h)
          add(e, 0, 1), add(e + b[x], 0, -1);
      } else {
        for (int i = t + a[x], j = i % h; i < t + h;
             ++i, ++j, j = j == h ? 0 : j)
          ++ee[h][j];
      }
    } else {
      int tt = ti[x], h = a[x] + b[x];
      if (h >= sq) {
        for (int e = tt + a[x]; e <= m; e += h)
          add(e, t, -1), add(e + b[x], t, 1);
      } else {
        for (int i = tt + a[x], j = i % h; i < tt + h;
             ++i, ++j, j = j == h ? 0 : j)
          --ee[h][j];
      }
    }
    s[t] += s[t - 1];
    int re = s[t];
    for (int i = 1; i < sq; ++i) re += ee[i][t % i];
    ans[t] = re;
    if (1.0 * clock() / CLOCKS_PER_SEC > 0.9) return cout << t << endl, 0;
  }
  for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
  return 0;
}
