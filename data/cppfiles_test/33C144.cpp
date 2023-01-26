#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 1e9 + 7;
constexpr int KINF = 0x3f3f3f3f;
constexpr int INF = 0x7f7f7f7f;
constexpr int maxn = 501, N = 64;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> dp(512, 501);
  dp[0] = 0;
  for (int i = (int)0; i < (int)n; ++i) {
    int x;
    cin >> x;
    vector<int> ndp = dp;
    for (int i = (int)0; i < (int)512; ++i) {
      if (dp[i] < x) ndp[i ^ x] = min(ndp[i ^ x], x);
    }
    dp = ndp;
  }
  set<int> ans;
  for (int i = (int)0; i < (int)512; ++i)
    if (dp[i] != 501) ans.insert(i);
  cout << ans.size() << "\n";
  for (auto v : ans) cout << v << " ";
  cout << "\n";
  return 0;
}
