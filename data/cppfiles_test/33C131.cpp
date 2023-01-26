#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> mini_dp(512, 2e9);
  mini_dp[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 512; j++) {
      if (mini_dp[j] < a[i]) {
        mini_dp[j ^ a[i]] = min(mini_dp[j ^ a[i]], a[i]);
      }
    }
  }
  vector<int> ans;
  for (int i = 0; i < 512; i++) {
    if (mini_dp[i] != 2e9) {
      ans.push_back(i);
    }
  }
  cout << ans.size() << '\n';
  for (auto itr : ans) {
    cout << itr << " ";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
