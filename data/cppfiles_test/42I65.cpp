#include <bits/stdc++.h>
using namespace std;
const int N = 444444;
const int MO = 1e9 + 7;
void ad(int& x, int y) {
  x += y;
  if (x >= MO) x -= MO;
}
int n, m, a[N], b[N], c[N], f[N], g[N];
pair<int, int> p[N];
int ta[N], tb[N], s[N];
void modifya(int x, int y) {
  while (x <= n * 2) {
    ad(ta[x], y);
    x += x & -x;
  }
}
int querya(int x) {
  int y = 0;
  while (x) {
    ad(y, ta[x]);
    x -= x & -x;
  }
  return y;
}
void modifyb(int x, int y) {
  while (x <= n * 2) {
    ad(tb[x], y);
    x += x & -x;
  }
}
int queryb(int x) {
  int y = 0;
  while (x) {
    ad(y, tb[x]);
    x -= x & -x;
  }
  return y;
}
void modify2(int x, int i) {
  x = n * 2 + 1 - x;
  while (x <= n * 2) {
    if (b[s[x]] < b[i]) s[x] = i;
    x += x & -x;
  }
}
int query2(int x) {
  x = n * 2 + 1 - x;
  int i = 0;
  while (x) {
    if (b[s[x]] > b[i]) i = s[x];
    x -= x & -x;
  }
  return i;
}
int main() {
  int i, j, x, y;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d%d", a + i, b + i), a[i]++, b[i]++;
  n++, a[n] = 1, b[n] = n * 2;
  scanf("%d", &m);
  for (i = 1; i <= m; i++) {
    scanf("%d", &x);
    c[x] = 1;
  }
  for (i = 1; i <= n; i++) p[i] = make_pair(b[i], i);
  sort(p + 1, p + n + 1);
  for (i = 1; i <= n; i++) {
    j = p[i].second;
    f[j] = querya(b[j]) + 1;
    ad(f[j], MO - querya(a[j]));
    x = query2(a[j]);
    if (c[j]) g[j] = 1;
    if (x) {
      ad(g[j], queryb(b[x] - 1));
      ad(g[j], MO - queryb(a[j]));
      ad(g[j], g[x]);
    }
    modifya(a[j], f[j]);
    modifyb(b[j], f[j]);
    if (c[j]) modify2(a[j], j);
  }
  printf("%d\n", g[n] % MO);
  return 0;
}
