#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
vector<unordered_map<int, int>> dp;
vector<int> arr;
int cntdp(int i, int x) {
  if (i < 0) {
    return 0;
  }
  if (dp[i].find(x) != dp[i].end()) {
    return dp[i][x];
  }
  int d = (arr[i] + x - 1) / x;
  dp[i][x] = (cntdp(i - 1, arr[i] / d) + (i + 1) * (d - 1)) % mod;
  return dp[i][x];
}
int32_t main() {
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    arr.resize(n);
    dp.resize(n);
    for (int& e : arr) {
      cin >> e;
    }
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
      ans += cntdp(i, arr[i + 1]);
      ans %= mod;
    }
    cout << ans << endl;
    arr.clear();
    dp.clear();
  }
}
