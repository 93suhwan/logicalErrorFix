#include <bits/stdc++.h>
using namespace std;
int n;
int f(vector<vector<int> > dp, vector<int> s, int key) {
  vector<int> v;
  for (int i = 0; i < n; i++) {
    v.push_back(dp[i][key] + dp[i][key] - s[i]);
  }
  sort(v.begin(), v.end());
  int sum = 0, count = 0;
  for (int i = n - 1; i >= 0; i--) {
    sum += v[i];
    if (sum <= 0) return count;
    count++;
  }
  return count;
}
void solve() {
  cin >> n;
  vector<vector<int> > dp(n, vector<int>(5, 0));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (char c : s) dp[i][c - 'a']++;
  }
  vector<int> s(n, 0);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 5; j++) s[i] += dp[i][j];
  int ans = 0;
  for (int i = 0; i < 5; i++) ans = max(ans, f(dp, s, i));
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  for (int testcase = 1; testcase <= T; testcase++) {
    solve();
  }
  return 0;
}
