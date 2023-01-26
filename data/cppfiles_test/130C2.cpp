#include <bits/stdc++.h>
const int N = 10005;
int a[N], ans[N], T, n;
int qry(int x, int y, int z) {
  printf("? %d %d %d\n", x, y, z);
  fflush(stdout);
  int ans;
  scanf("%d", &ans);
  return ans ^ 1;
}
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) ans[i] = 0;
  int x, y;
  for (int i = 1; i <= n; i += 3) {
    a[i] = qry(i, i + 1, i + 2);
    if (a[i] == 1)
      x = i;
    else
      y = i;
  }
  int im, cr;
  if (qry(x, x + 1, y) && qry(x, x + 1, y + 1))
    im = x;
  else
    im = x + 2;
  if (qry(y, y + 1, x) || qry(y, y + 1, x + 1) || qry(y, y + 1, x + 2))
    cr = y + 2;
  else
    cr = y;
  for (int i = 1; i <= n; i += 3) {
    if (a[i] == 0) {
      int t1 = qry(im, i, i + 1), t2 = qry(im, i + 1, i + 2);
      if (t1 == 1 && t2 == 1)
        ans[i + 1] = 1;
      else if (t1 == 1)
        ans[i] = 1;
      else if (t2 == 1)
        ans[i + 2] = 1;
    } else {
      ans[i] = ans[i + 1] = ans[i + 2] = 1;
      int t1 = qry(cr, i, i + 1), t2 = qry(cr, i + 1, i + 2);
      if (t1 == 0 && t2 == 0)
        ans[i + 1] = 0;
      else if (t1 == 0)
        ans[i] = 0;
      else if (t2 == 0)
        ans[i + 2] = 0;
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) cnt += ans[i];
  printf("! %d ", cnt);
  for (int i = 1; i <= n; i++)
    if (ans[i]) printf("%d ", i);
  puts("");
  fflush(stdout);
}
int main() {
  scanf("%d", &T);
  while (T--) {
    solve();
  }
}
