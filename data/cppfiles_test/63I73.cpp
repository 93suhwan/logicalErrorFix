#include <bits/stdc++.h>
using namespace std;
long long dp[1 << 20];
long long n;
long long balance[20];
long long prefixrbs[20][800005];
const int offset = 400000;
int minPoint[20];
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int balanceNow = 0;
    int minn = 0;
    for (auto t : s) {
      if (t == '(')
        balanceNow++;
      else
        balanceNow--;
      minn = min(minn, balanceNow);
      if (minn == balanceNow) prefixrbs[i][-minn + offset]++;
    }
    minPoint[i] = minn;
    balance[i] = balanceNow;
  }
  long long ans = 0;
  for (int mask = 1; mask < (1 << n); mask++) {
    int currentBalance = 0;
    for (int k = 0; k < n; k++) {
      if (mask & (1 << k)) currentBalance += balance[k];
    }
    for (int k = 0; k < n; k++) {
      if (mask & (1 << k)) {
        int oldbalance = currentBalance - balance[k];
        if (oldbalance < 0) continue;
        int oldmask = mask ^ (1 << k);
        long long now = dp[oldmask] + prefixrbs[k][oldbalance + offset];
        ans = max(ans, now);
        if (oldbalance + minPoint[k] >= 0) dp[mask] = max(dp[mask], now);
      }
    }
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
