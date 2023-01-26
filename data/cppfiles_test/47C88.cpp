#include <bits/stdc++.h>
using namespace std;
long long solve(vector<int> a, int k) {
  sort(a.begin(), a.end());
  int n = a.size();
  vector<long long> dp(n + 1);
  for (int i = 1; i < n; i++) {
    dp[i] = dp[max(0, i - k)] + a[max(0, i - k)] + a[i];
  }
  return dp[n - 1] + a[n - 1];
}
void testCase() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  vector<int> pos = {0}, neg = {0};
  int mx = 0;
  for (int i = 0; i < n; i++) {
    mx = max(mx, abs(a[i]));
    if (a[i] < 0)
      pos.push_back(-a[i]);
    else
      neg.push_back(a[i]);
  }
  cout << solve(pos, k) + solve(neg, k) - mx << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    testCase();
  }
  return 0;
}
