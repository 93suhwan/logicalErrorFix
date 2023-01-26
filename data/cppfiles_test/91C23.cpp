#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
int64_t fx[10] = {0, 1, 0, -1, 1, -1, 1, -1};
int64_t fy[10] = {1, 0, -1, 0, 1, -1, -1, 1};
const long long M = 2e5 + 10, M2 = 2e6 + 10, oo = 1e9 + 7, mod = 998244353;
const long long MC = (1 << 20) + 5;
int64_t pos[M], dp[2][M];
void precomp() {}
void solve() {
  int64_t n;
  cin >> n;
  int64_t ara[n + 10];
  ara[0] = 0;
  for (int64_t i = 1; i <= n; i++) {
    cin >> ara[i];
  }
  ara[n + 1] = 0;
  long long ans = 0;
  for (int64_t i = n + 1; i >= 1; i--) {
    vector<int64_t> all;
    for (int64_t block = 1; block * block <= ara[i]; block++) {
      all.push_back(block);
      if (block < ara[i] / block) all.push_back(ara[i] / block);
    }
    if (i > 1) {
      dp[!(i & 1)][ara[i - 1]] = 1;
      for (int64_t b : all) {
        int64_t subs = dp[i & 1][b] * (i - 1),
                splits = ((ara[i - 1] + b - 1) / b) - 1;
        int64_t prev = ara[i - 1] / (splits + 1);
        dp[!(i & 1)][prev] += dp[i & 1][b];
        ans = (ans + (subs * splits) % mod) % mod;
      }
    }
    for (int64_t b : all) dp[i & 1][b] = 0;
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  precomp();
  int64_t T;
  cin >> T;
  for (int64_t tc = 1; tc <= T; tc++) {
    solve();
  }
  return 0;
}
