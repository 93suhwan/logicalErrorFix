#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long mp[5][N];
long long sum_up[N], sum_down[N];
struct node {
  long long up, down;
  long long ma;
} mpp[N];
int main() {
  int t;
  cin >> t;
  while (t--) {
    memset(mpp, 0, sizeof mpp);
    long long m;
    cin >> m;
    for (int i = 1; i <= 2; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> mp[i][j];
      }
    }
    for (int i = 1; i <= m; i++) {
      sum_up[i] = sum_up[i - 1] + mp[1][i];
    }
    for (int i = 1; i <= m; i++) {
      sum_down[i] = sum_down[i - 1] + mp[2][i];
    }
    for (int i = 1; i <= m; i++) {
      mpp[i].up = sum_up[m] - sum_up[i];
      mpp[i].down = sum_down[i - 1];
      mpp[i].ma = max(mpp[i].down, mpp[i].up);
    }
    long long res = 1e9;
    for (int i = 1; i <= m; i++) {
      res = min(res, mpp[i].ma);
    }
    if (m == 1) res = 0;
    cout << res << '\n';
  }
  return 0;
}
