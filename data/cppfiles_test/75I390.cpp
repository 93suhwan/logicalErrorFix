#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
void solve() {
  long long n, x, k;
  cin >> n;
  vector<vector<long long>> dp(n);
  vector<pair<long long, long long>> pw(n);
  for (long long i = 0; i < n; i++) {
    cin >> k;
    long long minn = 0;
    for (long long j = 0; j < k; j++) {
      cin >> x;
      dp[i].push_back(x);
      minn = max(minn, x);
    }
    pw[i] = {i, minn};
  }
  sort(pw.begin(), pw.end(),
       [](pair<long long, long long> &a, pair<long long, long long> &b) {
         return a.second < b.second;
       });
  long long low = 0, high = 1e9 + 7;
  while (low <= high) {
    long long mid = low + (high - low) / 2;
    long long inPow = mid;
    bool notPossible = false;
    for (long long i = 0; i < n; i++) {
      long long idx = pw[i].first;
      for (long long j = 0; j < dp[idx].size(); j++) {
        if (dp[idx][j] <= inPow)
          inPow++;
        else {
          notPossible = true;
          break;
        }
      }
      if (notPossible) break;
    }
    if (notPossible)
      low = mid + 1;
    else
      high = mid - 1;
  }
  cout << low + 1 << endl;
  return;
}
