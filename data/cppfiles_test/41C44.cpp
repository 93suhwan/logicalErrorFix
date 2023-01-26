#include <bits/stdc++.h>
const int N = 1000;
int n, k, col[N][N];
void run(int l, int r, int d) {
  if (r - l == 1) return;
  int len = (r - l - 1) / k + 1;
  for (int i = l; i < r; i += len) {
    for (int j = i + len; j < r; j += len)
      for (int from = i; from < i + len; ++from)
        for (int to = j; to < std::min(r, j + len); ++to) col[from][to] = d;
    run(i, std::min(r, i + len), d + 1);
  }
}
int main() {
  scanf("%d%d", &n, &k);
  int c = 1;
  for (int t = k; t < n; ++c, t *= k)
    ;
  printf("%d\n", c);
  run(0, n, 0);
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j) printf("%d ", col[i][j] + 1);
  printf("\n");
  return 0;
}
