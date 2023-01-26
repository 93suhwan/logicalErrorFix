#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int ans[N][2];
int fa1[N];
int fa2[N];
int s1[N], s2[N];
int find(int fa[], int x) { return x == fa[x] ? x : fa[x] = find(fa, fa[x]); }
void merge(int fa[], int x, int y) {
  int fx = find(fa, x);
  int fy = find(fa, y);
  fa[fx] = fy;
}
void init(int fa[], int n) {
  for (int i = 1; i <= n; ++i) fa[i] = i;
}
int main() {
  int n, m1, m2;
  scanf("%d %d %d", &n, &m1, &m2);
  init(fa1, n);
  init(fa2, n);
  for (int i = 1; i <= m1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    merge(fa1, u, v);
  }
  for (int i = 1; i <= m2; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    merge(fa2, u, v);
  }
  int ct = 0;
  for (int i = 2; i <= n; ++i) {
    if (find(fa1, 1) != find(fa1, i) && find(fa2, 1) != find(fa2, i)) {
      ans[++ct][0] = 1;
      ans[ct][1] = i;
      merge(fa1, i, 1);
      merge(fa2, i, 1);
    }
  }
  int sz1 = 0, sz2 = 0;
  for (int i = 2; i <= n; ++i) {
    if (fa1[i] == i && fa1[i] != find(fa1, 1)) s1[sz1++] = i;
    if (fa2[i] == i && fa2[i] != find(fa2, 1)) s2[sz2++] = i;
  }
  for (int i = 0, j = 0; i < sz1 && j < sz2; ++i, ++j) {
    ans[++ct][0] = s1[i];
    ans[ct][1] = s2[j];
  }
  printf("%d\n", ct);
  for (int i = 1; i <= ct; ++i) printf("%d %d\n", ans[i][0], ans[i][1]);
  return 0;
}
