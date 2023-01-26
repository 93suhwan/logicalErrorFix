#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 20;
char ar[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int total_ticks_marked = 0, total_ticks = 0, n, m, k;
void paint_tick(int r, int c) {
  if (r < k) return;
  int depth = 0, left_depth = 0, right_depth = 0, lr = r, lc = c, rr = r,
      rc = c;
  while (lr - 1 >= 0 && lc - 1 >= 0 && ar[lr - 1][lc - 1] == '*')
    ++left_depth, --lr, --lc;
  while (rr - 1 >= 0 && rc + 1 < m && ar[rr - 1][rc + 1] == '*')
    ++right_depth, --rr, ++rc;
  if (min(left_depth, right_depth) >= k) {
    for (int i = 0; i <= min(left_depth, right_depth); ++i) {
      if (!visited[r - i][c - i])
        ++total_ticks_marked, visited[r - i][c - i] = true;
      if (!visited[r - i][c + i])
        ++total_ticks_marked, visited[r - i][c + i] = true;
    }
  }
}
int main() {
  int tc;
  scanf("%d", &tc);
  while (tc-- > 0) {
    total_ticks_marked = 0, total_ticks = 0;
    memset(visited, false, MAX_N * MAX_N);
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; ++i) scanf("%s", ar[i]);
    for (int i = n - 1; i >= 0; --i)
      for (int j = 0; j < m; ++j)
        if (ar[i][j] == '*') paint_tick(i, j), ++total_ticks;
    printf("%s\n", total_ticks_marked == total_ticks ? "YES" : "NO");
  }
}
