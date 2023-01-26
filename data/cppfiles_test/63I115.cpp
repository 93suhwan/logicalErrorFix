#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m1, m2;
int f[N][2];
inline int find(int x, int opt) {
  return x == f[x][opt] ? x : f[x][opt] = find(f[x][opt], opt);
}
vector<int> edge;
vector<int> Edge;
int main() {
  scanf("%d%d%d", &n, &m1, &m2);
  for (int i = 1; i <= n; ++i) f[i][0] = f[i][1] = i;
  for (int i = 1; i <= m1; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    int fu = find(u, 0);
    int fv = find(v, 0);
    if (fu == fv) continue;
    f[fu][0] = fv;
  }
  for (int i = 1; i <= m2; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    int fu = find(u, 1);
    int fv = find(v, 1);
    if (fu == fv) continue;
    f[fu][1] = fv;
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    int f1 = find(i, 1);
    int f0 = find(i, 0);
    for (int j = 1; j <= n; ++j) {
      int j1 = find(j, 1);
      int j0 = find(j, 0);
      if (j1 == f1 || j0 == f0) continue;
      cnt++;
      Edge.push_back(i);
      edge.push_back(j);
      f[f0][0] = j0;
      f[f1][1] = j1;
    }
  }
  printf("%d\n", cnt);
  for (int i = 0; i < cnt; ++i) printf("%d %d\n", Edge[i], edge[i]);
  return 0;
}
