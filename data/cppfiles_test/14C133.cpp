#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &ai : a) {
      cin >> ai;
    }
    vector<int> dp(n, 0);
    int res = n + 1;
    for (int i = 0; i < n; ++i) {
      if (a[i] > i + 1) continue;
      dp[i] = 1;
      int del = i + 1 - a[i];
      for (int j = 0; j < i; ++j) {
        int ind = j + 1 - a[j];
        if (ind < 0 || ind > del || (del - ind) > (i - j - 1)) continue;
        dp[i] = max(dp[i], dp[j] + 1);
      }
      if (dp[i] >= k) {
        res = min(res, del);
      }
    }
    if (res == n + 1) {
      cout << "-1\n";
    } else {
      cout << res << '\n';
    }
  }
  return 0;
}
