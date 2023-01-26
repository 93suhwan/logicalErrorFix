#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 1; i <= k; i++) {
    int sy;
    scanf("%d", &sy);
    for (int i = 1; i <= n; i++) {
      if (a[i][sy] == 1) {
        a[i][sy] = 2;
        sy++;
      } else if (a[i][sy] == 2) {
      } else {
        a[i][sy] = 2;
        sy--;
      }
    }
    printf("%d ", sy);
  }
  return 0;
}
