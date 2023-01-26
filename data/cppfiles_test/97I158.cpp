#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int Gx[4] = {0, 1, 0, -1}, Gy[4] = {1, 0, -1, 0};
int n, m, a[N][N], deg[N][N];
char s[N][N];
void DFS(int i, int j, int val) {
  a[i][j] = val;
  for (int w = 0; w < 4; ++w) {
    int x = i + Gx[w];
    int y = j + Gy[w];
    if (s[x][y] == 'X') {
      deg[x][y] -= val;
      if (deg[x][y] % 4 == 0) {
        for (int w2 = 0; w2 < 4; ++w2) {
          int x2 = x + Gx[w2];
          int y2 = y + Gy[w2];
          if (a[x2][y2] == 0) {
            DFS(x2, y2, 4);
          }
        }
      }
      if (deg[x][y] < 3) {
        for (int w2 = 0; w2 < 4; ++w2) {
          int x2 = x + Gx[w2];
          int y2 = y + Gy[w2];
          if (a[x2][y2] == 0) {
            DFS(x2, y2, 1);
          }
        }
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> s[i] + 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (s[i][j] == 'X') {
        int dem = 0;
        for (int w = 0; w < 4; ++w) {
          int x = i + Gx[w];
          int y = j + Gy[w];
          if (s[x][y] == '.') ++dem;
        }
        if (dem & 1) return cout << "NO", 0;
        a[i][j] = dem * 5 / 2;
        deg[i][j] = dem * 5 / 2;
      }
  for (int i = 0; i <= n; ++i) a[i][0] = a[i][m + 1] = -1;
  for (int i = 0; i <= m; ++i) a[0][i] = a[n + 1][i] = -1;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (s[i][j] == '.' && a[i][j] == 0) {
        DFS(i, j, 1);
      }
  cout << "YES\n";
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) cout << a[i][j] << " \n"[j == m];
}
