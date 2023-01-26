#include <bits/stdc++.h>
using namespace std;
const int N = 9e3;
int n, a[N];
int main() {
  scanf("%d", &n);
  vector<vector<int>> upd(8192);
  vector<int> dp(8192, 8192);
  dp[0] = -1;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < 8192; i++) upd[i].push_back(0);
  for (int i = 1; i <= n; i++) {
    int p = dp[a[i]];
    for (int t : upd[a[i]]) {
      int p = dp[a[i] ^ t];
      if (a[i] < p) {
        dp[a[i] ^ t] = a[i];
        for (int j = a[i] + 1; j < p; j++) upd[j].push_back(a[i] ^ t);
      }
    }
    upd[a[i]].clear();
  }
  vector<int> ans;
  for (int i = 0; i < 8192; i++)
    if (dp[i] < 8192) ans.push_back(i);
  printf("%d\n", ans.size());
  for (int t : ans) printf("%d ", t);
  return 0;
}
