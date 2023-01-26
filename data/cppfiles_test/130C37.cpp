#include <bits/stdc++.h>
using namespace std;
int t, n, a[4000], p0, p1, b0, b1, ans[10010], lb[4000], ub[4000];
int qry(int x, int y, int z) {
  printf("? %d %d %d\n", x, y, z);
  fflush(stdout);
  scanf("%d", &x);
  return x;
}
int main() {
  cin >> t;
  for (int tn = 0; tn < t; ++tn) {
    cin >> n;
    for (int i = 1; i <= n; ++i) ans[i] = 0;
    for (int i = 1; i <= n; i += 3) {
      a[(i + 2) / 3] = qry(i, i + 1, i + 2);
      lb[(i + 2) / 3] = i;
      ub[(i + 2) / 3] = i + 2;
    }
    for (int i = 1; i <= n / 3 - 1; ++i)
      if (a[i] != a[i + 1]) {
        int x = qry(i * 3 - 1, i * 3, i * 3 + 1),
            y = qry(i * 3, i * 3 + 1, i * 3 + 2);
        if (a[i] != x) {
          p0 = i * 3 - 2;
          p1 = i * 3 + 1;
          if (a[i] == 1) swap(p0, p1);
        } else if (x != y) {
          p0 = i * 3 - 1;
          p1 = i * 3 + 2;
          if (x == 1) swap(p0, p1);
        } else {
          p0 = i * 3;
          p1 = i * 3 + 3;
          if (y == 1) swap(p0, p1);
        }
        break;
      }
    ans[p1] = 1;
    b0 = (p0 + 2) / 3;
    b1 = (p1 + 2) / 3;
    for (int i = lb[b0]; i <= ub[b0]; ++i)
      if (i != p0 && i != p1) ans[i] = qry(p0, p1, i);
    for (int i = lb[b1]; i <= ub[b1]; ++i)
      if (i != p0 && i != p1) ans[i] = qry(p0, p1, i);
    for (int i = 1; i <= n / 3; ++i)
      if (i != b0 && i != b1) {
        if (a[i] == 0) {
          if (qry(lb[i], lb[i] + 1, p1) == 1) {
            if (qry(lb[i], p0, p1) == 1)
              ans[lb[i]] = 1;
            else
              ans[lb[i] + 1] = 1;
          } else
            ans[ub[i]] = qry(ub[i], p0, p1);
        } else {
          if (qry(lb[i], lb[i] + 1, p0) == 0) {
            if (qry(lb[i], p0, p1) == 0)
              ans[lb[i] + 1] = 1;
            else
              ans[lb[i]] = 1;
            ans[ub[i]] = 1;
          } else
            ans[ub[i]] = qry(ub[i], p0, p1), ans[lb[i]] = ans[lb[i] + 1] = 1;
        }
      }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) cnt += (ans[i] ^ 1);
    printf("! %d ", cnt);
    for (int i = 1; i <= n; ++i)
      if (ans[i] == 0) printf("%d ", i);
    puts("");
    fflush(stdout);
  }
  return 0;
}
