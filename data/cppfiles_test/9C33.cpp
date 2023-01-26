#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m, k, a[1010][1010], c, ans[N];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 1; i <= k; ++i) {
    scanf("%d", &c);
    int x = 1, y = c;
    while (x <= n) {
      if (a[x][y] == 1) {
        a[x][y] = 2;
        y++;
      } else if (a[x][y] == 2) {
        x++;
      } else {
        a[x][y] = 2;
        y--;
      }
    }
    ans[i] = y;
  }
  for (int i = 1; i <= k; ++i) {
    printf("%d%c", ans[i], i == k ? '\n' : ' ');
  }
}
