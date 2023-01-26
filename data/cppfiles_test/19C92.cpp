#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int Q;
  cin >> Q;
  while (Q-- > 0) {
    int n;
    cin >> n;
    vector<int> dp(2001, inf);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      vector<int> aux(dp);
      fill(dp.begin(), dp.end(), inf);
      for (int j = 0; j < 2001; ++j) {
        if (aux[j] != inf) {
          dp[max(0, j - a)] = min(dp[max(0, j - a)], aux[j] + a);
          if (j + a < 2001) {
            dp[j + a] = min(dp[j + a], max(0, aux[j] - a));
          }
        }
      }
    }
    int res = inf;
    for (int i = 0; i <= 2000; ++i) {
      if (dp[i] != inf) {
        res = min(res, i + dp[i]);
      }
    }
    cout << res << '\n';
  }
  return 0;
}
