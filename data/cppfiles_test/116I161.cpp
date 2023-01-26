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
LL dp[500005][2];
int cnt[500005];
const LL MOD = 998244353;
void Input() {
  scanf("%d", &n);
  for (int i = 0; i <= n; ++i) {
    dp[i][0] = dp[i][1] = 0;
    cnt[i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &ar[i]);
  }
}
LL add(LL x, LL y) { return (x + y) % MOD; }
LL mul(LL x, LL y) { return (x * y) % MOD; }
LL myPow(LL x, LL y) {
  if (y == 0) return 1;
  if (y == 1) return x;
  LL tmp = myPow(x, y / 2) % MOD;
  return mul(mul(tmp, tmp), (y % 2 == 1 ? x : 1));
}
int main() {
  getCases();
  while (cases--) {
    Input();
    for (int i = 0; i < n; ++i) {
      int x = ar[i];
      if (x == 0) {
        dp[x][0] = add(dp[x][0], myPow(2, cnt[x]));
        cnt[x]++;
      } else if (x == 1) {
        dp[x][0] = add(dp[x][0], mul(dp[x - 1][0], myPow(2, cnt[x])));
        dp[x][1] = add(dp[x][1], myPow(2, cnt[x]));
        cnt[x]++;
      } else {
        dp[x][0] = add(dp[x][0], mul(dp[x - 1][0], myPow(2, cnt[x])));
        dp[x][1] = add(dp[x][1], mul(dp[x - 2][0], myPow(2, cnt[x])));
        cnt[x]++;
      }
    }
    LL ans = 0;
    for (int i = 0; i <= n; ++i) {
      ans = add(ans, dp[i][0]);
      ans = add(ans, dp[i][1]);
    }
    printf("%lld\n", ans);
  }
}
