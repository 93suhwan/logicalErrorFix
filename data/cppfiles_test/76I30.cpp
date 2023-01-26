#include <bits/stdc++.h>
const int maxn = 2e5 + 10;
int vis[41][41];
int arr[6];
int n, m;
bool solve() {
  for (int p1 = 1; p1 <= n; p1++) {
    arr[1] = p1;
    for (int p2 = p1 + 1; p2 <= n; p2++) {
      arr[2] = p2;
      for (int p3 = p2 + 1; p3 <= n; p3++) {
        arr[3] = p3;
        for (int p4 = p3 + 1; p4 <= n; p4++) {
          arr[4] = p4;
          for (int p5 = p4 + 1; p5 <= n; p5++) {
            arr[5] = p5;
            int cnt = 0;
            for (int i = 1; i <= 5; i++) {
              for (int j = i + 1; j <= 5; j++) {
                if (vis[arr[i]][arr[j]]) ++cnt;
              }
            }
            if (!cnt || cnt == 10) {
              for (int i = 1; i <= 5; i++) {
                printf("%d%c", arr[i], " \n"[i == 5]);
              }
              return true;
            }
          }
        }
      }
    }
  }
  return false;
}
int main() {
  scanf("%d%d", &n, &m);
  n = std::min(n, 40);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (u > n || v > n) continue;
    vis[u][v] = vis[v][u] = 1;
  }
  if (!solve()) {
    printf("-1\n");
  }
  return 0;
}
