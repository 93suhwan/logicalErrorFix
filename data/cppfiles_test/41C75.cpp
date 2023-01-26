#include <bits/stdc++.h>
using namespace std;
int n, k, a[1001][1001], ans, i, j;
void solve(int l, int r, int t) {
  if (r - l + 1 <= k) {
    int i, j;
    for (i = l; i <= r; i++)
      for (j = l + 1; j <= r; j++) a[i][j] = t;
    ans = max(ans, t);
    return;
  }
  int m = (r - l + 1) / k, c = (r - l + 1) % k;
  vector<int> v[1000];
  int i, j, p, q, g = l;
  for (i = 0; i < k - c; i++)
    for (j = 1; j <= m; j++) v[i].push_back(g++);
  for (i = k - c; i < k; i++)
    for (j = 1; j <= m + 1; j++) v[i].push_back(g++);
  for (i = 0; i < k; i++) solve(v[i].front(), v[i].back(), t + 1);
  for (i = 0; i < k; i++)
    for (j = i + 1; j < k; j++)
      for (p = 0; p < v[i].size(); p++)
        for (q = 0; q < v[j].size(); q++) a[v[i][p]][v[j][q]] = t;
}
int main() {
  scanf("%d%d", &n, &k);
  solve(1, n, 1);
  printf("%d\n", ans);
  for (i = 1; i <= n; i++)
    for (j = i + 1; j <= n; j++) printf("%d ", a[i][j]);
}
