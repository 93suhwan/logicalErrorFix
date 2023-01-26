#include <bits/stdc++.h>
using namespace std;
struct ed {
  int x, nx;
} e[200005 << 1];
int res2, res1, cnt;
int nx[200005], ecnt = 1;
int isle[200005], isbu[200005];
int n;
void clear() {
  ecnt = 1;
  res2 = res1 = cnt = 0;
  for (int i = 1; i <= n; i++) {
    nx[i] = 0;
    isle[i] = isbu[i] = 0;
  }
}
void add(int x, int y) {
  e[ecnt] = (ed){y, nx[x]};
  nx[x] = ecnt++;
}
void dfs(int f, int x) {
  int ct = 0, flag1 = 1, flag2 = 1;
  for (int i = nx[x]; i; i = e[i].nx)
    if (e[i].x != f) {
      dfs(x, e[i].x);
      flag1 &= isle[e[i].x];
      flag2 &= isbu[e[i].x];
      if (!isbu[e[i].x]) ct++;
    }
  if (ct == 0) {
    isle[x] = 1;
    res1++;
  } else if (flag1) {
    isbu[x] = 1;
    cnt++;
  } else if (flag2) {
    res2++;
  }
}
int main() {
  int T;
  scanf("%d", &T);
  for (; T--;) {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      add(x, y);
      add(y, x);
    }
    dfs(1, 1);
    if (isbu[1]) {
      printf("%d\n", res1 + res2);
    } else {
      printf("%d\n", res1 + res2 - cnt);
    }
    clear();
  }
  return 0;
}
