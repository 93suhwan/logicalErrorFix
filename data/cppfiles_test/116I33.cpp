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
    vector<int> rcnt(N + 1, 0);
    for (int i = 0; i < N; i++) {
      cin >> nums[i];
      rcnt[nums[i]]++;
    }
    long long plus1 = 1;
    for (int i = 0; i < rcnt[1]; i++) {
      plus1 = (plus1 * 2) % MOD;
    }
    vector<long long> cnt(N + 1, 0);
    long long ans = 0;
    for (int i = 0; i < N; i++) {
      int x = nums[i];
      rcnt[x]--;
      long long cntx = cnt[x];
      long long cntx_1 = 0;
      long long cntx_0 = x == 0;
      if (x > 0) {
        cntx_1 = cnt[x - 1];
      }
      long long plus = cntx + cntx_1 + cntx_0;
      ans = (ans + plus) % MOD;
      cnt[x] = (cnt[x] + plus) % MOD;
      if (x + 2 <= N) {
        ans = (ans + plus * rcnt[x + 2]) % MOD;
      }
    }
    ans = (ans + plus1 - 1) % MOD;
    cout << ans << endl;
  }
  return 0;
}
