#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int grid[2][N], sum[2][N], n;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long ans, ans2;
    cin >> n;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> grid[i][j];
        sum[i][j + 1] = sum[i][j] + grid[i][j];
      }
    }
    long long mid = (n / 2) + 1;
    long long op1 = sum[0][n] - sum[0][mid];
    long long op2 = sum[1][mid - 1] - sum[1][0];
    ans = max(op1, op2);
    long long op3 = sum[0][n] + grid[1][n - 1];
    ans = min(op3, ans);
    long long op4 = sum[1][n] - grid[1][n - 1];
    ans = min(op4, ans);
    printf("%d\n", ans);
  }
  return 0;
}
