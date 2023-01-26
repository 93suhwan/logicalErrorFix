#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, m, k;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    char A[n][m];
    int B[n][m];
    priority_queue<pair<int, int>> P;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> A[i][j];
        B[i][j] = 0;
        if (A[i][j] == '*') P.push({i, j});
      }
    }
    int ticks_min = INT_MAX, ticks_max = 0;
    ;
    while (!P.empty()) {
      pair<int, int> lp = P.top();
      P.pop();
      int h = 1;
      int streak = 0;
      int br = 0;
      while (lp.first - h >= 0 && lp.second - h >= 0 && lp.second + h < m) {
        char p1 = A[lp.first - h][lp.second - h];
        char p2 = A[lp.first - h][lp.second + h];
        if (p1 == '*' && p2 == '*') {
          if (B[lp.first - h][lp.second - h] == 0 ||
              B[lp.first - h][lp.second + h] == 0)
            streak++;
          B[lp.first - h][lp.second - h] = 1;
          B[lp.first - h][lp.second + h] = 1;
        } else {
          break;
        }
        h++;
      }
      if (streak > 0) {
        B[lp.first][lp.second] = 1;
        ticks_min = min(ticks_min, streak);
        ticks_max = max(ticks_max, streak);
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (A[i][j] == '*' && B[i][j] == 0) {
          ticks_min = 0;
          ticks_max = 0;
        }
      }
    }
    if (k <= ticks_min && ticks_min > 0 && ticks_max > 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
