#include <bits/stdc++.h>
using namespace std;
int a[1000][1000];
int main() {
  int n, m, k;
  int s[1000];
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 0; i < m; i++) {
    s[i] = i;
  }
  int t, ans;
  for (int i = 0; i < k; i++) {
    scanf("%d", &t);
    int cur = s[t - 1];
    s[t - 1] += m;
    int tc = s[t - 1];
    while (tc < n * m && a[tc / m][tc % m] == 2) {
      tc += m;
      s[t - 1] = tc;
    }
    while (cur < n * m) {
      int x = cur / m;
      int y = cur % m;
      if (a[x][y] == 1) cur += 1;
      if (a[x][y] == 3) cur -= 1;
      if (a[x][y] == 2) cur += m;
      a[x][y] = 2;
    }
    printf("%d ", cur % m + 1);
  }
  return 0;
}
