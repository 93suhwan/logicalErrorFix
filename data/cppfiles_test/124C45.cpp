#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int T;
int n;
char s[2010], t[2010];
long long dp[2010][2010], qzh[2010][2010], tot[2010][2010], qzhtot[2010][2010];
int bes[2010], bet[2010];
long long calc1(int x1, int x2, int y1, int y2) {
  return qzh[x2][y2] - (x1 == 0 ? 0 : qzh[x1 - 1][y2]) -
         (y1 == 0 ? 0 : qzh[x2][y1 - 1]) +
         (x1 == 0 || y1 == 0 ? 0 : qzh[x1 - 1][y1 - 1]);
}
long long calc2(int x1, int x2, int y1, int y2) {
  return qzhtot[x2][y2] - (x1 == 0 ? 0 : qzhtot[x1 - 1][y2]) -
         (y1 == 0 ? 0 : qzhtot[x2][y1 - 1]) +
         (x1 == 0 || y1 == 0 ? 0 : qzhtot[x1 - 1][y1 - 1]);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 0; i <= n; ++i)
      for (int j = 0; j <= n; ++j) {
        dp[i][j] = qzh[i][j] = tot[i][j] = qzhtot[i][j] = 0;
      }
    cin >> s + 1 >> t + 1;
    for (int i = 1; i <= n; ++i) {
      bes[i] = bes[i - 1];
      if (s[i] != '?' && ((s[i] - '0' + i) & 1)) bes[i] = i;
      bet[i] = bet[i - 1];
      if (t[i] != '?' && ((t[i] - '0' + i) & 1)) bet[i] = i;
    }
    tot[0][0] = 1;
    for (int i = 0; i <= n; ++i) qzhtot[0][i] = qzhtot[i][0] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if ((s[i] == '?' || ((s[i] - '0' + i) & 1)) &&
            (t[j] == '?' || ((t[j] - '0' + j) & 1))) {
          tot[i][j] =
              (calc2(bes[i - 1], i - 1, bet[j - 1], j - 1) % MOD + MOD) % MOD;
          dp[i][j] = ((calc1(bes[i - 1], i - 1, bet[j - 1], j - 1) +
                       tot[i][j] * abs(i - j) % MOD) %
                          MOD +
                      MOD) %
                     MOD;
        }
        qzhtot[i][j] = (qzhtot[i][j - 1] + qzhtot[i - 1][j] -
                        qzhtot[i - 1][j - 1] + tot[i][j] + MOD) %
                       MOD;
        qzh[i][j] = (qzh[i][j - 1] + qzh[i - 1][j] - qzh[i - 1][j - 1] +
                     dp[i][j] + MOD) %
                    MOD;
      }
    }
    cout << (calc1(bes[n], n, bet[n], n) % MOD + MOD) % MOD << "\n";
  }
}
