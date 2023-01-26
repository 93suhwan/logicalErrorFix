#include <bits/stdc++.h>
using namespace std;
using namespace std;
int _, n, m, i, ans, c[401][401], u, j, k, p, l, q;
char s[401][401];
int center(int u, int v, int w, int x) {
  return c[w][x] - c[w][v - 1] - c[u - 1][x] + c[u - 1][v - 1];
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
      cin >> s[i] + 1;
    }
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) {
        c[i][j] =
            c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1] + (s[i][j] == '0');
      }
    }
    ans = 16;
    for (i = 1; i <= n; i++)
      for (j = 1; j <= m; j++)
        for (k = 5, p = i + 4; p <= n; p++, k++) {
          if (center(i + 1, j, p - 1, j) > ans) break;
          for (l = 4, q = j + 3; q <= m; q++, l++) {
            u = (k - 2) * (l - 2) - center(i + 1, j + 1, p - 1, q - 1) +
                center(i + 1, j, p - 1, j) + center(i, j + 1, i, q - 1) +
                center(p, j + 1, p, q - 1) + center(i + 1, q, p - 1, q);
            if (u >= ans)
              break;
            else {
              ans = u;
            }
          }
        }
    cout << ans << endl;
  }
}
