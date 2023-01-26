#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int cases = -1;
enum InputType : int {
  SingleInput = 1,
  MultipleInput = 2,
  NotSet = 0,
};
void getCases() {
  InputType inputType = MultipleInput;
  if (inputType == SingleInput) {
    cases = 1;
  } else if (inputType == MultipleInput) {
    scanf("%d", &cases);
  } else {
    assert(false && "fix the function");
  }
}
int n;
int ar[500005];
LL dp[500005][3];
const LL MOD = 998244353;
void Input() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &ar[i]);
  }
}
LL add(LL x, LL y) { return (x + y) % MOD; }
int main() {
  getCases();
  while (cases--) {
    Input();
    for (int i = 0; i < n; ++i) {
      int x = ar[i];
      if (x == 0) {
        dp[x][0] = add(dp[x][0], dp[x][0] + 1);
      }
      if (x == 1) {
        dp[x][2] = add(dp[x][2], dp[x][2] + 1);
      }
      if (x > 0) {
        dp[x][0] = add(dp[x][0], dp[x - 1][0]);
      }
      if (x > 1) {
        dp[x][1] = add(dp[x][1], dp[x - 2][0]);
      }
      dp[x][0] = add(dp[x][0], dp[x + 2][1]);
    }
    LL ans = 0;
    for (int i = 0; i <= n; ++i) {
      ans = add(ans, dp[i][0]);
      ans = add(ans, dp[i][1]);
      ans = add(ans, dp[i][2]);
    }
    printf("%lld\n", ans);
    for (int i = 0; i <= n + 2; ++i) {
      dp[i][0] = dp[i][1] = dp[i][2] = 0;
    }
  }
}
