#include <bits/stdc++.h>
using namespace std;
map<string, int> id;
int vis[10][10], vis2[10][10];
int dx[8] = {0, 0, -1, 1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int main() {
  id["Right"] = 0;
  id["Left"] = 1;
  id["Up"] = 2;
  id["Down"] = 3;
  id["Down-Right"] = 4;
  id["Down-Left"] = 5;
  id["Up-Left"] = 6;
  id["Up-Right"] = 7;
  id["Done"] = 8;
  string s;
  int t;
  scanf("%d", &t);
  while (t--) {
    s.clear();
    int n = 8;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        vis[i][j] = 0;
      }
    }
    for (int cas = 1; cas <= 130; cas++) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          if (!vis[i][j]) {
            vis[i][j] = 1;
            printf("%d %d\n", i, j);
            fflush(stdout);
            cin >> s;
            if (id[s] == 8) break;
            for (int k = 1; k <= n; k++) {
              for (int l = 1; l <= n; l++) {
                if (k == i || l == j || i + j == k + l || i - j == k - l) {
                  vis2[k][l] = 1;
                } else {
                  vis2[k][l] = 0;
                }
              }
            }
            for (int k = 1; k <= n; k++) {
              for (int l = 1; l <= n; l++) {
                int x = k + dx[id[s]], y = l + dy[id[s]];
                if (x >= 1 && x <= n && y >= 1 && y <= n) {
                  if (vis2[x][y]) vis[k][l] = 1;
                } else {
                  vis[k][l] = 1;
                }
              }
            }
          }
        }
        if (id[s] == 8) break;
      }
      assert(cas < 130);
      if (id[s] == 8) break;
    }
  }
  return 0;
}
