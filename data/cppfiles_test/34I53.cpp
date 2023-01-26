#include <bits/stdc++.h>
using namespace std;
vector<int> e[5005];
int maxn = 1 << 13;
int n;
int dp[1 << 13];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    e[x].push_back(i);
  }
  memset(dp, 0x3f3f3f3f, sizeof dp);
  dp[0] = 0;
  for (int i = 1; i <= 5000; i++) {
    if (e[i].size() == 0) continue;
    for (int j = maxn; j >= 0; j--) {
      if (j ^ i < j) {
        int pos =
            lower_bound(e[i].begin(), e[i].end(), dp[i ^ j]) - e[i].begin();
        if (pos == e[i].size()) continue;
        dp[j] = min(dp[j], e[i][pos]);
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i <= maxn; i++) {
    if (dp[i] != 0x3f3f3f3f) cnt++;
  }
  printf("%d\n", cnt);
  for (int i = 0; i <= maxn; i++)
    if (dp[i] != 0x3f3f3f3f) printf("%d ", i);
  return 0;
}
