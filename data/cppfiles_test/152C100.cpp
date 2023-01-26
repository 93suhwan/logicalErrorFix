#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int t, n;
int a[N];
int dp[N][2][2];
pair<int, pair<int, int> > be[N][2][2];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i)
      cin >> a[i], dp[i][0][0] = dp[i][1][0] = dp[i][1][1] = dp[i][0][1] = 1e9,
                   be[i][0][0] = be[i][1][0] = be[i][1][1] = be[i][0][1] =
                       make_pair(0, make_pair(0, 0));
    be[1][0][1] = be[1][1][1] = make_pair(-1, make_pair(0, 0));
    dp[1][0][1] = -1e9;
    dp[1][1][1] = -1e9;
    for (int i = 2; i <= n; ++i)
      for (int j = 0; j <= 1; ++j)
        for (int op1 = 0; op1 <= 1; ++op1)
          for (int op2 = 0; op2 <= 1; ++op2) {
            int now = j == 0 ? -a[i] : a[i];
            int from = op1 == 0 ? -a[i - 1] : a[i - 1];
            if (be[i - 1][op1][op2].first == 0) continue;
            if (op2 == 0) {
              if (now < from) continue;
              if (now > dp[i - 1][op1][op2]) {
                if (from < dp[i][j][1])
                  dp[i][j][1] = from,
                  be[i][j][1] = make_pair(i - 1, make_pair(op1, op2));
              } else {
                if (dp[i - 1][op1][op2] < dp[i][j][0])
                  dp[i][j][0] = dp[i - 1][op1][op2],
                  be[i][j][0] = make_pair(i - 1, make_pair(op1, op2));
              }
            } else {
              if (now < dp[i - 1][op1][op2]) continue;
              if (now > from) {
                if (dp[i - 1][op1][op2] < dp[i][j][1])
                  dp[i][j][1] = dp[i - 1][op1][op2],
                  be[i][j][1] = make_pair(i - 1, make_pair(op1, op2));
              } else {
                if (from < dp[i][j][0])
                  dp[i][j][0] = from,
                  be[i][j][0] = make_pair(i - 1, make_pair(op1, op2));
              }
            }
          }
    int op1, op2, flag = 0;
    for (op1 = 0; op1 <= 1 && flag == 0; ++op1) {
      for (op2 = 0; op2 <= 1 && flag == 0; ++op2)
        if (be[n][op1][op2].first != 0) {
          flag = 1;
          break;
        }
      if (flag) break;
    }
    if (op1 > 1)
      cout << "NO\n";
    else {
      cout << "YES\n";
      for (int i = n; i; --i) {
        pair<int, pair<int, int> > from = be[i][op1][op2];
        if (op1 == 0) a[i] = -a[i];
        op1 = from.second.first;
        op2 = from.second.second;
      }
      for (int i = 1; i <= n; ++i) cout << a[i] << " ";
      cout << "\n";
    }
  }
}
