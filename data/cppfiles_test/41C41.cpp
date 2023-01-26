#include <bits/stdc++.h>
using namespace std;
int n, k;
int ans[1005][1005];
int maxc = 0;
void solve(int l, int r, int c) {
  if (l == r) return;
  maxc = max(maxc, c);
  int blksiz =
      ((r - l + 1) % (k) == 0 ? (r - l + 1) / (k) : ((r - l + 1) / (k)) + 1);
  for (int i = l; i <= r; i++) {
    int blk1 = (i - l) / blksiz;
    for (int j = l + 1; j <= r; j++) {
      int blk2 = (j - l) / blksiz;
      if (blk1 != blk2) {
        ans[i][j] = c;
      }
    }
  }
  for (int i = l; i <= r; i += blksiz) {
    solve(i, min(r, i + blksiz - 1), c + 1);
  }
}
int main() {
  scanf("%d%d", &n, &k);
  solve(1, n, 1);
  printf("%d\n", maxc);
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      printf("%d ", ans[i][j]);
    }
  }
  return 0;
}
