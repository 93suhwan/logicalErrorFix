#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<long long> dp(n + 1, 0);
  vector<long long> p(n + 1, 0);
  p[1] = 1;
  dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    dp[i] = p[i - 1];
    int j = i;
    while (j > 1) {
      int left = 1;
      int right = j;
      int cur = -1;
      while (left <= right) {
        int mid = (left + right) / 2;
        if ((i / mid) == (i / j)) {
          cur = mid;
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      }
      long long x = ((j - cur + 1) * dp[i / j]) % m;
      dp[i] = (dp[i] + x) % m;
      j = cur - 1;
    }
    p[i] = (p[i - 1] + dp[i]) % m;
  }
  cout << dp[n] << "\n";
}
