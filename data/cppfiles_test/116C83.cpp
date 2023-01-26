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
LL dp[2][500005];
const LL MOD = 998244353;
void Input() {
  scanf("%d", &n);
  for (int i = 0; i <= n + 3; ++i) {
    dp[0][i] = dp[1][i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &ar[i]);
  }
}
LL add(LL x, LL y) { return (x + y) % MOD; }
int main() {
  getCases();
  while (cases--) {
    Input();
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
      int x = ar[i];
      dp[0][x + 1] = add(dp[0][x + 1], dp[0][x + 1]);
      dp[0][x + 1] = add(dp[0][x + 1], dp[0][x]);
      if (x > 0) {
        dp[1][x - 1] = add(dp[1][x - 1], dp[1][x - 1]);
        dp[1][x - 1] = add(dp[1][x - 1], dp[0][x - 1]);
      }
      dp[1][x + 1] = add(dp[1][x + 1], dp[1][x + 1]);
    }
    LL ans = 0;
    for (int i = 0; i <= n + 3; ++i) {
      ans = add(ans, dp[0][i]);
      ans = add(ans, dp[1][i]);
    }
    ans = add(ans, MOD - 1);
    printf("%lld\n", ans);
  }
}
