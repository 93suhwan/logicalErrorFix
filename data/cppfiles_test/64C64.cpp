#include <bits/stdc++.h>
using namespace std;
int n, m1, m2, a[200100];
int sta1[200100], s1, fa1[200100];
int sta2[200100], s2, fa2[200100];
int cotx[200100], coty[200100], ans;
int fine(int *fa, int x) { return fa[x] = fa[x] == x ? x : fine(fa, fa[x]); }
int bine(int *fa, int x, int y) {
  if (x > y) swap(x, y);
  fa[y] = x;
}
int main() {
  cin >> n >> m1 >> m2;
  int x, y;
  for (register int i = 1; i <= n; i++) fa1[i] = fa2[i] = i;
  for (register int i = 1; i <= m1; i++)
    scanf("%d%d", &x, &y), bine(fa1, fine(fa1, x), fine(fa1, y));
  for (register int i = 1; i <= m2; i++)
    scanf("%d%d", &x, &y), bine(fa2, fine(fa2, x), fine(fa2, y));
  for (register int i = 1; i <= n; i++) {
    x = fine(fa1, i), y = fine(fa2, i);
    if (x != 1 && y != 1)
      cotx[++ans] = i, coty[ans] = 1, bine(fa1, x, 1), bine(fa2, y, 1);
    if (x == 1 && y != 1) sta1[++s1] = i;
    if (x != 1 && y == 1) sta2[++s2] = i;
  }
  while (1) {
    int flag1 = 1, flag2 = 1;
    while (s1) {
      x = fine(fa1, sta1[s1]), y = fine(fa2, sta1[s1]);
      if (x == 1 && y != 1) {
        flag1 = 0;
        break;
      }
      s1--;
    }
    while (s2) {
      x = fine(fa1, sta2[s2]), y = fine(fa2, sta2[s2]);
      if (x != 1 && y == 1) {
        flag2 = 0;
        break;
      }
      s2--;
    }
    if (flag1 == 0 && flag2 == 0) {
      int x = sta1[s1], y = sta2[s2];
      cotx[++ans] = x, coty[ans] = y;
      bine(fa1, fine(fa1, x), fine(fa1, y));
      bine(fa2, fine(fa2, x), fine(fa2, y));
      s1--, s2--;
    } else
      break;
  }
  cout << ans << '\n';
  for (register int i = 1; i <= ans; i++)
    cout << cotx[i] << ' ' << coty[i] << '\n';
}
