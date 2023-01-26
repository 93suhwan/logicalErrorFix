#include <bits/stdc++.h>
using namespace std;
const int maxn = 400 + 5;
const int mo = 1e9 + 7;
int readint() {
  int x = 0, f = 1;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    (s = getchar());
  }
  while (s >= '0' && s <= '9') {
    x = (x << 3) + (x << 1) + (s ^ 48);
    (s = getchar());
  }
  return x * f;
}
int a[maxn][maxn], pre[maxn][maxn];
int query(int a, int b, int c, int d) {
  return pre[c][d] - pre[a - 1][d] - pre[c][b - 1] + pre[a - 1][b - 1];
}
int main() {
  int t = readint();
  while (t--) {
    int n = readint(), m = readint();
    for (int i = 1; i <= n; i++) {
      char s[maxn];
      scanf("%s", s + 1);
      for (int j = 1; j <= m; j++) a[i][j] = s[j] ^ 48;
    }
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
    int ans = 16;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        for (int k = i + 4; k <= n; k++)
          for (int l = j + 3; l <= m; l++) {
            if (l - j - 1 - query(i, j + 1, i, l - 1) + l - j - 1 -
                    query(k, j + 1, k, l - 1) + k - i - 1 -
                    query(i + 1, j, k - 1, j) +
                    query(i + 1, j + 1, k - 1, l - 1) >=
                ans)
              break;
            ans = min(ans, l - j - 1 - query(i, j + 1, i, l - 1) + l - j - 1 -
                               query(k, j + 1, k, l - 1) + k - i - 1 -
                               query(i + 1, j, k - 1, j) + k - i - 1 -
                               query(i + 1, l, k - 1, l) +
                               query(i + 1, j + 1, k - 1, l - 1));
          }
    cout << ans << endl;
  }
  return 0;
}
