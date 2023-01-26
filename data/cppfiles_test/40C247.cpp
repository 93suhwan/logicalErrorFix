#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int M = 2e9 + 1000;
int grid[2][N], n;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long ans, ans1, ans2;
    ans1 = ans2 = 0;
    ans = M;
    cin >> n;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> grid[i][j];
      }
    }
    for (int i = 0; i < n; ++i) ans1 += grid[0][i];
    for (int i = 0; i < n; ++i) {
      ans1 -= grid[0][i];
      ans = min(ans, max(ans1, ans2));
      ans2 += grid[1][i];
    }
    printf("%lld\n", ans);
  }
  return 0;
}
