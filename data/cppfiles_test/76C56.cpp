#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int maxm = 50;
int edge[maxm + 1][maxm + 1];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (u <= maxm && v <= maxm) edge[u][v] = edge[v][u] = 1;
  }
  for (int i = 1; i <= min(n, maxm); ++i) {
    for (int j = i + 1; j <= min(n, maxm); ++j) {
      for (int k = j + 1; k <= min(n, maxm); ++k) {
        if (!(edge[i][j] && edge[i][k] && edge[j][k] ||
              !edge[i][j] && !edge[i][k] && !edge[j][k]))
          continue;
        for (int h = k + 1; h <= min(n, maxm); ++h) {
          if (!(edge[i][j] && edge[i][h] && edge[j][h] && edge[k][h] ||
                !edge[i][j] && !edge[i][h] && !edge[j][h] && !edge[k][h]))
            continue;
          for (int l = h + 1; l <= min(n, maxm); ++l) {
            if (!(edge[i][j] && edge[i][l] && edge[j][l] && edge[k][l] &&
                      edge[h][l] ||
                  !edge[i][j] && !edge[i][l] && !edge[j][l] && !edge[k][l] &&
                      !edge[h][l]))
              continue;
            return printf("%d %d %d %d %d\n", i, j, k, h, l), 0;
          }
        }
      }
    }
  }
  printf("-1\n");
}
