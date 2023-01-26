#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e2 + 5;
int n, m;
char s[maxn][maxn];
int a[maxn][maxn];
int sum[maxn][maxn];
int ask(int x, int y) {
  int ans = 0;
  for (int i = x; i <= y; i++) {
    for (int j = 1; j <= 4; j++) {
      if (a[i][j] == 1) ans++;
    }
  }
  int temp = 0;
  for (int i = x + 1; i <= y - 1; i++) {
    for (int j = 2; j <= 3; j++) {
      if (a[i][j] == 1) temp++;
    }
  }
  ans -= a[x][1] + a[x][4] + a[y][1] + a[y][4] + temp;
  ans = 2 * (y - x - 1) + 4 - ans + temp;
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> s[i] + 1;
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        a[i][j] = s[i][j] - '0';
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
      }
    }
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 4; j <= n; j++) {
        int minedge = j - i - 1 - (sum[j - 1][1] - sum[i][1]);
        int temp = ask(i, j);
        ans = min(ans, temp);
        for (int k = 5; k <= m; k++) {
          int disvalue =
              2 - (a[i][k - 1] + a[j][k - 1]) +
              (j - i - 1 -
               (sum[j - 1][k] - sum[j - 1][k - 1] - sum[i][k] + sum[i][k - 1]));
          int temp3 = (sum[j - 1][k - 1] - sum[j - 1][k - 2] - sum[i][k - 1] +
                       sum[i][k - 2]);
          disvalue += temp3 - (j - i - 1 - temp3);
          temp += disvalue;
          int startpos = k - 3;
          minedge += 2 - (a[j][startpos] + a[i][startpos]) +
                     sum[j - 1][startpos] - sum[j - 1][startpos - 1] -
                     sum[i][startpos] + sum[i][startpos - 1];
          int newedge = (j - i - 1 -
                         (sum[j - 1][startpos] - sum[j - 1][startpos - 1] -
                          sum[i][startpos] + sum[i][startpos - 1]));
          if (newedge < minedge) {
            temp = temp - minedge + newedge;
            minedge = newedge;
          }
          ans = min(ans, temp);
        }
      }
    }
    printf("%d\n", ans);
  }
}
