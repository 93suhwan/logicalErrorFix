#include <bits/stdc++.h>
using namespace std;
const int NR = 5e5 + 10;
int T, n;
int a[NR], num[NR];
struct arr {
  int mx, pos;
} t[NR * 4];
void build(int x, int lx, int rx) {
  if (lx == rx) {
    t[x].mx = a[lx];
    t[x].pos = lx;
    return;
  }
  int mid = (lx + rx) >> 1;
  build(x * 2, lx, mid);
  build(x * 2 + 1, mid + 1, rx);
  if (t[x * 2].mx > t[x * 2 + 1].mx)
    t[x] = t[x * 2];
  else
    t[x] = t[x * 2 + 1];
}
void add(int x, int lx, int rx, int p, int k) {
  if (lx == rx) {
    t[x].mx = k;
    t[x].pos = lx;
    return;
  }
  int mid = (lx + rx) >> 1;
  if (p <= mid)
    add(x * 2, lx, mid, p, k);
  else
    add(x * 2 + 1, mid + 1, rx, p, k);
  if (t[x * 2].mx > t[x * 2 + 1].mx)
    t[x] = t[x * 2];
  else
    t[x] = t[x * 2 + 1];
}
int main() {
  scanf("%d", &T);
  while (T--) {
    int flag = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) num[i] = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      num[a[i]]++;
      if (num[a[i]] >= 2) flag = 1;
    }
    if (flag) {
      printf("YES\n");
      continue;
    }
    build(1, 1, n);
    flag = 1;
    for (int i = n; i >= 1; i--) {
      int x = t[1].pos, y = 1;
      if (x == i) {
        add(1, 1, n, i, 0);
        continue;
      }
      if (x == 1 && i == 1) break;
      if (x == 1 && i == 2 && a[1] > a[2]) {
        flag = 0;
        break;
      }
      if (x == 1) y = 2;
      int tmp = a[x];
      a[x] = a[y];
      a[y] = a[i];
      a[i] = tmp;
      add(1, 1, n, x, a[y]);
      add(1, 1, n, y, a[i]);
      add(1, 1, n, i, 0);
    }
    if (flag)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
