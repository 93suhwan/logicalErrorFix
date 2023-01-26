#include <bits/stdc++.h>
using namespace std;
char matrix[2020][2020];
int dp[2020][2020];
pair<int, int> p[2020 * 2020];
int n, m;
int fill(int i, int j) {
  if (i < 0 || j < 0 || i >= n || j >= m) {
    return 0;
  }
  if (dp[i][j] == -1) {
    int start_x = i;
    int start_y = j;
    int count = 0;
    p[count++] = {i, j};
    if (matrix[i][j] == 'U') {
      i = i - 1;
    } else if (matrix[i][j] == 'L') {
      j = j - 1;
    } else if (matrix[i][j] == 'D') {
      i = i + 1;
    } else {
      j = j + 1;
    }
    while (i != start_x || j != start_y) {
      p[count++] = {i, j};
      if (matrix[i][j] == 'U') {
        i = i - 1;
      } else if (matrix[i][j] == 'L') {
        j = j - 1;
      } else if (matrix[i][j] == 'D') {
        i = i + 1;
      } else {
        j = j + 1;
      }
    }
    for (int i = 0; i < count; i++) {
      dp[p[i].first][p[i].second] = (-1 * count);
    }
    return 0;
  }
  if (dp[i][j] != 0) {
    return dp[i][j];
  }
  dp[i][j] = -1;
  int ans = 1;
  if (matrix[i][j] == 'U') {
    ans += abs(fill(i - 1, j));
  } else if (matrix[i][j] == 'L') {
    ans += abs(fill(i, j - 1));
  } else if (matrix[i][j] == 'D') {
    ans += abs(fill(i + 1, j));
  } else {
    ans += abs(fill(i, j + 1));
  }
  if (dp[i][j] < -1) {
    ans = dp[i][j];
  }
  return dp[i][j] = ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> matrix[i][j];
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        dp[i][j] = 0;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        fill(i, j);
      }
    }
    int ans = dp[0][0];
    int x = 0;
    int y = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (abs(dp[i][j]) > ans) {
          x = i;
          y = j;
          ans = abs(dp[i][j]);
        }
      }
    }
    cout << (x + 1) << " " << (y + 1) << " " << ans << endl;
  }
}
