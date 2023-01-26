#include <bits/stdc++.h>
using namespace std;
double startTime;
double gct() { return ((double)clock() - startTime) / CLOCKS_PER_SEC; }
void suraj();
int main() {
  startTime = (double)clock();
  { suraj(); }
  return 0;
}
const long long MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
void suraj() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> free(n + 1, vector<int>(m + 1, true));
  long long stairs = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (i == 1) {
        for (int k = 1;; k++) {
          int nx = i + k / 2;
          int ny = j + (k + 1) / 2;
          if (nx > n || ny > m) {
            stairs += ((k - 1) * ((k - 1) + 1)) / 2;
            break;
          }
        }
      }
      if (j == 1) {
        for (int k = 1;; k++) {
          int nx = i + (k + 1) / 2;
          int ny = j + k / 2;
          if (nx > n || ny > m) {
            stairs += ((k - 1) * ((k - 1) + 1)) / 2;
            break;
          }
        }
      }
    }
  }
  stairs += n * m;
  long long currStairs = stairs;
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    free[x][y] = !free[x][y];
    long long rd = 0;
    for (rd = 1;; rd++) {
      int nx = x + (rd) / 2;
      int ny = y + (rd + 1) / 2;
      if (nx > n || ny > m || !free[nx][ny]) break;
    }
    long long tl = 0;
    for (tl = 1;; tl++) {
      int nx = x - (tl + 1) / 2;
      int ny = y - tl / 2;
      if (nx < 1 || ny < 1 || !free[nx][ny]) break;
    }
    long long dr = 0;
    for (dr = 1;; dr++) {
      int nx = x + (dr + 1) / 2;
      int ny = y + dr / 2;
      if (nx > n || ny > m || !free[nx][ny]) break;
    }
    long long lt = 0;
    for (lt = 1;; lt++) {
      int nx = x - (lt) / 2;
      int ny = y - (lt + 1) / 2;
      if (nx < 1 || ny < 1 || !free[nx][ny]) break;
    }
    rd--;
    tl--;
    dr--;
    lt--;
    if (!free[x][y]) {
      currStairs -= ((rd + tl + rd * tl) + (dr + lt + dr * lt) + 1);
    } else {
      currStairs += ((rd + tl + rd * tl) + (dr + lt + dr * lt) + 1);
    }
    cout << currStairs << "\n";
  }
}
