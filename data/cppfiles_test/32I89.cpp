#include <bits/stdc++.h>
using namespace std;
const int MX = 100005, SQ = 450;
int n, a[MX];
long long dp[MX][SQ], acu[MX];
long long sum(int i, int j) {
  if (i) return acu[j] - acu[i - 1];
  return acu[j];
}
void main_() {
  cin >> n;
  for (int i = 0; i < int(n); i++) {
    cin >> a[i];
    acu[i] = a[i];
    if (i) acu[i] += acu[i - 1];
  }
  for (int i = 0; i < int(n); i++) memset(dp[i], 0, sizeof(dp[i]));
  for (int i = n - 1; i >= 0; i--)
    for (int j = 1; j < SQ; j++) {
      if (i + 1 < n) dp[i][j] = dp[i + 1][j];
      if (i + j - 1 > n || i - j + 1 < 0) continue;
      if (j == 1 || sum(i - j + 1, i) < dp[i + j - 1][j - 1])
        dp[i][j] = max(dp[i][j], sum(i - j + 1, i));
    }
  int res = 0;
  for (int j = 1; j < SQ; j++)
    if (dp[0][j]) res = j;
  cout << res << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) main_();
  return 0;
}
