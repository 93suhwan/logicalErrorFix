#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;
ll ad(ll a, ll b) { return (a + b + mod) % mod; }
ll ml(ll a, ll b) { return ((a % mod) * (b % mod)) % mod; }
const int N = 5e5;
ll dp[N + 1][2] = {0};
ll DP[N + 1] = {0};
ll a[N + 1];
ll dp_(int idx, int i) { return idx < 0 ? 0 : dp[idx][i]; }
ll DP_(int idx) { return idx < 0 ? 0 : DP[idx]; }
void solver() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  dp[0][1] = 0, dp[0][0] = 1, DP[0] = 1;
  ll total = 1;
  stack<int> s;
  for (int i = 1; i <= n; ++i) {
    total = ml(total, a[i]);
    dp[i][1] = ml(a[i], dp[i - 1][1]);
    while (!s.empty() && a[s.top()] > a[i]) s.pop();
    int idx = 0;
    if (!s.empty()) idx = s.top();
    if ((i - idx) % 2 == 0) {
      dp[i][1] = ad(dp[i][1], ml(a[i], DP_(idx - 1)));
      dp[i][1] = ad(dp[i][1], ml(a[i], DP_(i - 2)));
      dp[i][1] = ad(dp[i][1], dp[idx][1]);
      dp[i][1] = ad(dp[i][1], -ml(a[idx], dp_(idx - 1, 0)));
      dp[i][1] = ad(dp[i][1], -ml(a[idx], dp_(idx - 1, 1)));
    } else {
      dp[i][1] = ad(dp[i][1], ml(a[i], ad(DP_(i - 2), -DP_(idx - 1))));
      dp[i][1] = ad(dp[i][1], ad(ml(a[idx], dp_(idx - 1, 0)), -dp_(idx, 1)));
      dp[i][1] = ad(dp[i][1], ml(a[idx], dp_(idx - 1, 1)));
    }
    dp[i][0] = ad(total, -dp[i][1]);
    DP[i] = ad(dp[i][0], -DP[i - 1]);
    s.push(i);
  }
  cout << dp[n][0] << "\n";
  return;
}
int main() {
  solver();
  return 0;
}
