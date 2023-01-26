#include <bits/stdc++.h>
using namespace std;
int T, n, dp1[2005][2005][2], dp2[2005][2005][2];
char a1[2005], a2[2005];
int add(int x, int y) {
  x += y;
  return x < 1000000007 ? x : x - 1000000007;
}
void W(int &x, int y) {
  x += y;
  if (x >= 1000000007) x -= 1000000007;
}
void slv() {
  scanf("%d %s %s", &n, a1 + 1, a2 + 1);
  for (int i = 1; i <= n; i += 2) {
    if (isdigit(a1[i])) a1[i] ^= '0' ^ '1';
    if (isdigit(a2[i])) a2[i] ^= '0' ^ '1';
  }
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n; ++j) {
      dp1[i][j][0] = (!i && !j);
      dp1[i][j][1] = dp2[i][j][0] = dp2[i][j][1] = 0;
      if (i && (a1[i] == '0' || a1[i] == '?'))
        W(dp1[i][j][0], dp1[i - 1][j][0]), W(dp2[i][j][0], dp2[i - 1][j][0]);
      if (j && (a2[j] == '0' || a2[j] == '?')) {
        W(dp1[i][j][1], dp1[i][j - 1][0]);
        W(dp2[i][j][1], dp2[i][j - 1][0]);
        W(dp1[i][j][1], dp1[i][j - 1][1]);
        W(dp2[i][j][1], dp2[i][j - 1][1]);
      }
      if (i && j && (a1[i] == '1' || a1[i] == '?') &&
          (a2[j] == '1' || a2[j] == '?')) {
        W(dp1[i][j][0], dp1[i - 1][j - 1][0]);
        W(dp2[i][j][0], dp2[i - 1][j - 1][0] + 1ll * dp1[i - 1][j - 1][0] *
                                                   abs(i - j) % 1000000007);
        W(dp1[i][j][0], dp1[i - 1][j - 1][1]);
        W(dp2[i][j][0], dp2[i - 1][j - 1][1] + 1ll * dp1[i - 1][j - 1][1] *
                                                   abs(i - j) % 1000000007);
      }
    }
  printf("%d\n", add(dp2[n][n][0], dp2[n][n][1]));
}
int main() {
  scanf("%d", &T);
  while (T--) slv();
  return 0;
}
