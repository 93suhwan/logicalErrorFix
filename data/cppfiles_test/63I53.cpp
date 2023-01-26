#include <bits/stdc++.h>
using namespace std;
const int N = 20, M = 400000;
int n;
vector<int> cnt[N + 9];
int sum[(1 << N) + 9], mn[N + 9];
void into() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    static char s[M + 9];
    scanf("%s", s);
    int m = strlen(s);
    cnt[i].resize(m + 1);
    for (int j = 0, &pre = sum[1 << i]; j < m; ++j) {
      mn[i] = min(mn[i], pre += s[j] == '(' ? 1 : -1);
      if (pre == mn[i]) ++cnt[i][-pre];
    }
  }
}
int dp[(1 << N) + 9][2];
void Get_dp() {
  for (int s = 1; s < 1 << n; ++s) sum[s] = sum[s & -s] + sum[s ^ s & -s];
  for (int s = 1; s < 1 << n; ++s) {
    dp[s][0] = dp[s][1] = -M;
    for (int i = 0; i < n; ++i) {
      if (s >> i & 1 ^ 1) continue;
      int t = s ^ 1 << i;
      if (sum[t] >= 0 && dp[t][1] != -M) {
        int b = sum[t] + mn[i] < 0;
        dp[s][b] = max(dp[s][b], dp[t][1] + cnt[i][sum[t]]);
      }
      dp[s][1] = max(dp[s][1], dp[t][1]);
    }
  }
}
void work() { Get_dp(); }
void outo() { printf("%d\n", max(dp[(1 << n) - 1][0], dp[(1 << n) - 1][1])); }
int main() {
  int T = 1;
  for (; T--;) {
    into();
    work();
    outo();
  }
  return 0;
}
