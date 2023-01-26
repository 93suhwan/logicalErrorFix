#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, ans, m1, m2, fa1[N], fa2[N], mark1[N], mark2[N], a[N], b[N];
int find1(int x) { return fa1[x] = fa1[x] == x ? x : find1(fa1[x]); }
int find2(int x) { return fa2[x] = fa2[x] == x ? x : find2(fa2[x]); }
int main() {
  scanf("%d%d%d", &n, &m1, &m2);
  for (int i = 1; i <= n; i++) fa1[i] = fa2[i] = i;
  for (int i = 1; i <= m1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x = find1(x);
    y = find1(y);
    if (x < y) swap(x, y);
    fa1[x] = y;
  }
  for (int i = 1; i <= m2; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x = find2(x);
    y = find2(y);
    if (x < y) swap(x, y);
    fa2[x] = y;
  }
  for (int i = 2; i <= n; i++) {
    int f1 = find1(i), f2 = find2(i);
    if (f1 != 1 && f2 != 1) {
      fa1[f1] = fa2[f2] = 1;
      a[++ans] = 1, b[ans] = i;
    }
  }
  for (int i = 1, j = 1; i <= n; i++) {
    if (find1(i) == 1 || mark1[find1(i)]) continue;
    while ((find2(j) == 1 || mark2[find2(j)]) && j <= n) j++;
    if (j <= n) mark1[find1(i)] = mark2[find2(j)] = 1, a[++ans] = i, b[ans] = j;
  }
  printf("%d\n", ans);
  for (int i = 1; i <= ans; i++) printf("%d %d\n", a[i], b[i]);
  return 0;
}
