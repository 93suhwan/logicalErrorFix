#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int TT = 1; TT <= T; TT++) {
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
      cin >> nums[i];
    }
    vector<long long> dp1(N + 1), dp2(N + 1);
    long long ans = 0;
    for (int i = 0; i < N; i++) {
      int x = nums[i];
      long long plus1 = dp1[x];
      long long plus2 = dp2[x];
      if (x > 0) {
        plus1 += dp1[x - 1];
      }
      if (x == 0) {
        plus1 += 1;
      }
      if (x == 1) {
        plus2 += 1;
      }
      if (x - 2 >= 0) {
        plus2 += dp1[x - 2];
      }
      dp1[x] = (dp1[x] + plus1) % MOD;
      dp2[x] = (dp2[x] + plus2) % MOD;
      if (x + 2 <= N) {
        plus2 += dp2[x + 2];
        dp2[x + 2] = (dp2[x + 2] * 2) % MOD;
      }
      ans = (ans + plus1 + plus2) % MOD;
    }
    cout << ans << endl;
  }
  return 0;
}
