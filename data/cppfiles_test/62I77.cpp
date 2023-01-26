#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, q;
  cin >> n >> m >> q;
  bool available[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      available[i][j] = true;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int b = 0; b <= 1; b++) {
        int len = 1;
        while (true) {
          int x = i + (len + !b) / 2;
          int y = j + (len + b) / 2;
          if (x >= n || y >= m) {
            break;
          }
          len++;
        }
        ans += len - 1;
      }
    }
  }
  ans += n * m;
  while (q--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    int new_ans1 = 1;
    for (int b = 0; b <= 1; b++) {
      int len = 1;
      while (true) {
        int x1 = x + (len + !b) / 2;
        int y1 = y + (len + b) / 2;
        if (x1 >= n || y1 >= m || !available[x1][y1]) {
          break;
        }
        len++;
      }
      new_ans1 += len - 1;
    }
    int new_ans2 = 1;
    for (int b = 0; b <= 1; b++) {
      int len = 1;
      while (true) {
        int x1 = x - (len + !b) / 2;
        int y1 = y - (len + b) / 2;
        if (x1 < 0 || y1 < 0 || !available[x1][y1]) {
          break;
        }
        len++;
      }
      new_ans2 += len - 1;
    }
    if (available[x][y]) {
      ans -= new_ans1 * new_ans2;
    } else {
      ans += new_ans1 * new_ans2;
    }
    available[x][y] = !available[x][y];
    cout << ans << endl;
  }
}
