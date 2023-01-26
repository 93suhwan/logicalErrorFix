#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
string g[25];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) cin >> g[i];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (g[i][j] != '.') {
          int kk = 0;
          while (i - kk >= 0 && j - kk >= 0 && j + kk < m &&
                 g[i - kk][j - kk] != '.' && g[i - kk][j + kk] != '.')
            kk++;
          kk--;
          if (kk >= k) {
            kk = 0;
            while (i - kk >= 0 && j - kk >= 0 && j + kk < m &&
                   g[i - kk][j - kk] != '.' && g[i - kk][j + kk] != '.')
              g[i - kk][j - kk] = g[i - kk][j + kk] = 'o', kk++;
          }
        }
    bool bj = 1;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (g[i][j] == '*') {
          bj = 0;
          break;
        }
    if (bj)
      puts("YES");
    else
      puts("NO");
  }
}
