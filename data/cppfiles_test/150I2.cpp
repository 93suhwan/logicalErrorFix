#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x : a) {
    cin >> x;
  }
  int res = INT_MAX;
  int mx = *max_element(a.begin(), a.end());
  vector<bool> cnt(12, false);
  for (int x : a) {
    cnt[x % 12] = true;
  }
  for (int i = 0; i <= 3; ++i) {
    for (int j = 0; j <= 5; ++j) {
      for (int k = 0; k <= 4; ++k) {
        vector<int> v;
        for (int o = 0; o < i; ++o) v.push_back(1);
        for (int o = 0; o < j; ++o) v.push_back(2);
        for (int o = 0; o < k; ++o) v.push_back(3);
        vector<bool> dp(12, false);
        do {
          int sum = 0;
          for (int x : v) {
            sum += x;
            if (sum < 12) dp[sum] = true;
          }
        } while (next_permutation(v.begin(), v.end()));
        bool good = true;
        for (int o = 0; o < 12; ++o) {
          if (cnt[o] && !dp[o]) {
            good = false;
          }
        }
        if (good) {
          res = min(res, i + j + k);
        }
      }
    }
  }
  cout << res + *(max_element(a.begin(), a.end())) / 12 * 4 << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
