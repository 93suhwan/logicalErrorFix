#include <bits/stdc++.h>
int count(int a) { return a == 0 ? 0 : count(a & a - 1) ^ 1; }
int ds[200000 * 2], cc[200000];
int find(int i) { return ds[i] < 0 ? i : (ds[i] = find(ds[i])); }
void join(int i, int j) {
  i = find(i);
  j = find(j);
  if (i == j) return;
  if (ds[i] > ds[j])
    ds[i] = j;
  else {
    if (ds[i] == ds[j]) ds[i]--;
    ds[j] = i;
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    static int ii[200000 - 1], jj[200000 - 1];
    int n, m, h, i, j, no;
    scanf("%d%d", &n, &m);
    memset(ds, -1, n * 2 * sizeof *ds);
    for (h = 0; h < n - 1; h++) {
      int v, p;
      scanf("%d%d%d", &i, &j, &v), i--, j--;
      ii[h] = i, jj[h] = j;
      if (v != -1) {
        p = count(v);
        join(i << 1 | 0, j << 1 | p), join(i << 1 | 1, j << 1 | p ^ 1);
      }
    }
    while (m--) {
      int p;
      scanf("%d%d%d", &i, &j, &p), i--, j--;
      join(i << 1 | 0, j << 1 | p), join(i << 1 | 1, j << 1 | p ^ 1);
    }
    no = 0;
    for (i = 0; i < n; i++)
      if (find(i << 1 | 0) == find(i << 1 | 1)) {
        no = 1;
        break;
      }
    if (no)
      printf("NO\n");
    else {
      printf("YES\n");
      for (i = 0; i < n; i++)
        cc[i] = find(i << 1 | 0) < find(i << 1 | 1) ? 0 : 1;
      for (h = 0; h < n - 1; h++) {
        i = ii[h], j = jj[h];
        printf("%d %d %d\n", i + 1, j + 1, cc[i] ^ cc[j]);
      }
    }
  }
  return 0;
}
