#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
const int mod = 998244353;
signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }
    int dp[n][2][2];
    vector<int> pred[n][2][2];
    for (int i = 0; i < n; i++) {
      for (int first = 0; first < 2; first++) {
        for (int second = 0; second < 2; second++) {
          dp[i][first][second] = 1e9;
          pred[i][first][second] = {-1, -1, -1, -1};
        }
      }
    }
    dp[0][0][0] = -1e9;
    dp[0][0][1] = -1e9;
    pred[0][0][0] = {-1, -1, -1, -p[0]};
    pred[0][0][1] = {-1, -1, -1, p[0]};
    for (int i = 1; i < n; i++) {
      for (int first = 0; first < 2; first++) {
        int a, b;
        for (int second = 0; second < 2; second++) {
          if (dp[i - 1][first][second] == 1e9) {
            continue;
          }
          if (first == 0) {
            b = dp[i - 1][first][second];
            a = p[i - 1];
            if (second == 0) {
              a *= -1;
            }
          } else {
            b = p[i - 1];
            a = dp[i - 1][first][second];
            if (second == 0) {
              b *= -1;
            }
          }
          if (p[i] > a) {
            if (dp[i][0][1] > b) {
              dp[i][0][1] = b;
              pred[i][0][1] = {i - 1, first, second, p[i]};
            }
          } else if (p[i] > b) {
            if (dp[i][1][1] > a) {
              dp[i][1][1] = a;
              pred[i][1][1] = {i - 1, first, second, p[i]};
            }
          }
          if (-p[i] > a) {
            if (dp[i][0][0] > b) {
              dp[i][0][0] = b;
              pred[i][0][0] = {i - 1, first, second, -p[i]};
            }
          } else if (-p[i] > b) {
            if (dp[i][1][0] > a) {
              dp[i][1][0] = a;
              pred[i][1][0] = {i - 1, first, second, -p[i]};
            }
          }
        }
      }
    }
    int fl = 0;
    vector<int> ans(n);
    for (int first = 0; first < 2; first++) {
      for (int second = 0; second < 2; second++) {
        if (dp[n - 1][first][second] < 1e9) {
          int i, x1, y1;
          i = n - 1;
          x1 = first;
          y1 = second;
          while (i >= 0) {
            int x2, y2;
            x2 = pred[i][x1][y1][1];
            y2 = pred[i][x1][y1][2];
            ans[i] = pred[i][x1][y1][3];
            x1 = x2;
            y1 = y2;
            i--;
          }
          fl = 1;
        }
      }
    }
    if (!fl) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}
