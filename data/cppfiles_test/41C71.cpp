#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
int mp[N + 5][N + 5], ans, k;
void Sol(int l, int r, int col) {
  ans = max(ans, col);
  int wth = (r - l + 1 + k - 1) / k, cnt = (r - l + 1 + wth - 1) / wth;
  for (int i = 1; i <= cnt; ++i) {
    for (int j = i + 1; j <= cnt; ++j) {
      for (int ii = 1; ii <= min(wth, r - l + 1 - (i - 1) * wth); ++ii) {
        for (int jj = 1; jj <= min(wth, r - l + 1 - (j - 1) * wth); ++jj) {
          mp[l - 1 + (i - 1) * wth + ii][l - 1 + (j - 1) * wth + jj] = col;
        }
      }
    }
  }
  if (wth != 1)
    for (int i = 1; i <= cnt; ++i) {
      Sol(l + (i - 1) * wth, min(l - 1 + (i * wth), r), col + 1);
    }
  return;
}
int main() {
  int n;
  scanf("%d%d", &n, &k);
  Sol(1, n, 1);
  printf("%d\n", ans);
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      printf("%d ", mp[i][j]);
    }
  }
}
