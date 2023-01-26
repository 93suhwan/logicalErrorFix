#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353, INF = 1e18;
class Solution {
 public:
  Solution() {}
  void findAnswer() {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<long long> dp(n, 0), temp(n, 0);
    for (int i = 0; i < n; i++) {
      if (i + 1 >= a[i]) {
        temp[i + 1 - a[i]]++;
      }
    }
    for (int i = 0; i < n; i++) {
      if (i + 1 >= a[i]) {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
          if (a[i] > a[j] && a[i] - a[j] <= abs(i - j)) {
            dp[i] = max(dp[i], dp[j] + 1LL);
          }
      }
    }
    long long ans = n, flag = 0;
    for (int i = 0; i < n; i++)
      if (temp[i] >= k) {
        ans = i;
        flag = 1;
        break;
      }
    for (int i = 0; i < n; i++)
      if (i + 1 >= a[i]) {
        temp[i + 1 - a[i]]--;
        if (((dp[i] + temp[i + 1 - a[i]]) >= k)) {
          flag = 1;
          ans = min(ans, i + 1 - a[i]);
        }
      }
    if (!flag)
      cout << "-1\n";
    else
      cout << ans << "\n";
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  Solution obj;
  for (long long test = 1; test <= t; test++) {
    obj.findAnswer();
  }
  return 0;
}
