#include <bits/stdc++.h>
using namespace std;
int n, i, j, a[100001], b[515], c[515], h, k, g;
vector<int> f[3][515];
int main() {
  scanf("%d", &n);
  b[0] = 1;
  for (i = 1; i <= n; i = i + 1) scanf("%d", &a[i]);
  for (i = 1; i <= n; i = i + 1) {
    for (j = 0; j <= 500; j = j + 1) f[(i + 1) % 2][j].clear();
    for (j = 0; j <= a[i]; j = j + 1)
      for (g = 0; g < f[i % 2][j].size(); g = g + 1) {
        f[(i + 1) % 2][j].push_back(f[i % 2][j][g]);
        f[(i + 1) % 2][a[i]].push_back(a[i] ^ f[i % 2][j][g]);
        b[f[i % 2][j][g] ^ a[i]] = 1;
      }
    for (j = a[i] + 1; j <= 500; j = j + 1)
      for (g = 0; g < f[i % 2][j].size(); g = g + 1)
        f[(i + 1) % 2][j].push_back(f[i % 2][j][g]);
    f[(i + 1) % 2][a[i]].push_back(a[i]);
    b[a[i]] = 1;
  }
  for (i = 0; i <= 500; i = i + 1)
    if (b[i] == 1) c[++k] = i;
  printf("%lld\n", k);
  for (i = 1; i <= k; i = i + 1) printf("%lld ", c[i]);
  return 0;
}
