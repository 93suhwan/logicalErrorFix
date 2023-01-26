#include <bits/stdc++.h>
using namespace std;
inline long long md(long long m, long long v) { return ((v % m) + m) % m; }
const int MAX = 8200;
const int NOT = 1e9;
void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  vector<vector<int> > idx(MAX + 1);
  for (int i = 0; i < n; i++) {
    idx[arr[i]].push_back(i);
  }
  vector<int> dp(MAX + 1, NOT);
  dp[0] = -1;
  for (int a = 1; a <= MAX; a++) {
    int I = a % 2, J = 1 - I;
    if ((int)(idx[a]).size() == 0) continue;
    int upper = idx[a].back();
    dp[a] = min(dp[a], idx[a].front());
    for (int b = 1; b <= MAX; b++) {
      int target = a ^ b;
      if (target > MAX) continue;
      if (dp[target] < upper) {
        int where =
            int(lower_bound((idx[a]).begin(), (idx[a]).end(), dp[target]) -
                begin(idx[a]));
        dp[b] = min(dp[b], idx[a][where]);
      }
    }
  }
  vector<int> ans;
  for (int i = 0; i <= MAX; i++) {
    if (dp[i] != NOT) ans.push_back(i);
  }
  cout << (int)(ans).size() << "\n";
  for (int i : ans) cout << i << ' ';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  solve();
  return 0;
}
