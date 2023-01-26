#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int A[n];
  long long ans = 0;
  for (int &i : A) cin >> i;
  unordered_map<int, int> dp[n];
  for (int i = n - 1; i; i--) {
    dp[i][A[i]]++;
    for (auto val : dp[i]) {
      int split = (A[i - 1] - 1) / val.first + 1;
      int newST = A[i - 1] / split;
      dp[i - 1][newST] += val.second;
      ans += 1LL * val.second * (split - 1) * i;
    }
    dp[i].clear();
  }
  cout << ans % 998244353 << endl;
}
int main() {
  int tc;
  cin >> tc;
  while (tc--) solve();
}
