#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int a[maxn];
bool dp[maxn][2010];
int ma[maxn][2010];
int mi[maxn][2010];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      for (int j = 0; j <= 2000; j++) {
        dp[i][j] = mi[i][j] = ma[i][j] = 0;
      }
    }
    dp[0][1000] = 1;
    ma[0][1000] = 1000;
    mi[0][1000] = 1000;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= 2000; j++) {
        if (j - a[i] >= 0 && j - a[i] <= 2000 && dp[i - 1][j - a[i]]) {
          dp[i][j] = 1;
          int tma = max(ma[i - 1][j - a[i]], j);
          int tmi = min(mi[i - 1][j - a[i]], j);
          if ((ma[i][j] == 0 && mi[i][j] == 0) ||
              tma - tmi < ma[i][j] - mi[i][j]) {
            ma[i][j] = tma;
            mi[i][j] = tmi;
          }
        }
        if (j + a[i] >= 0 && j + a[i] <= 2000 && dp[i - 1][j + a[i]]) {
          dp[i][j] = 1;
          int tma = max(ma[i - 1][j + a[i]], j);
          int tmi = min(mi[i - 1][j + a[i]], j);
          if ((ma[i][j] == 0 && mi[i][j] == 0) ||
              tma - tmi < ma[i][j] - mi[i][j]) {
            ma[i][j] = tma;
            mi[i][j] = tmi;
          }
        }
      }
    }
    int an = 2000;
    for (int i = 0; i <= 2000; i++) {
      if (dp[n][i]) {
        an = min(an, ma[n][i] - mi[n][i]);
      }
    }
    cout << an << endl;
  }
  return 0;
}
