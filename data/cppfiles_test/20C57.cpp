#include <bits/stdc++.h>
using namespace std;
long long T, n, m;
long long num[500][500];
long long sum1[500][500], sum0[500][500];
int main() {
  scanf("%d", &T);
  while (T--) {
    cin >> n >> m;
    long long minsum = 10000000000;
    long long ans = 10000000000;
    for (long long i = 1; i <= n; i++)
      for (long long j = 1; j <= m; j++) {
        char ch;
        cin >> ch;
        num[i][j] = ch - '0';
        sum1[i][j] = sum1[i - 1][j] + num[i][j];
        sum0[i][j] = sum0[i - 1][j] + !num[i][j];
      }
    for (int i = 1; i <= n; i++) {
      for (int ii = i + 4; ii <= n; ii++) {
        minsum = 10000000000;
        for (int j = 3; j < m; j++) {
          minsum = min(
              !num[i][j] + !num[i][j - 1] + !num[ii][j] + !num[ii][j - 1] +
                  sum1[ii - 1][j] - sum1[i][j] + sum1[ii - 1][j - 1] -
                  sum1[i][j - 1] + sum0[ii - 1][j - 2] - sum0[i][j - 2],
              minsum + !num[i][j] + !num[ii][j] + sum1[ii - 1][j] - sum1[i][j]);
          ans = min(ans, minsum + sum0[ii - 1][j + 1] - sum0[i][j + 1]);
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
