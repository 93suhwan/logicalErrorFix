#include <bits/stdc++.h>
using namespace std;
vector<int> dp(1 << 12, INT_MAX);
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x : a) {
    cin >> x;
  }
  int mx = *max_element(a.begin(), a.end());
  int mask = 0;
  for (int x : a) {
    mask |= (1 << (x % 12));
  }
  cout << dp[mask] + mx / 12 * 4 << '\n';
}
void prebuild() {
  for (int i = 0; i <= 6; ++i) {
    for (int j = 0; j <= 6; ++j) {
      for (int k = 0; k <= 4; ++k) {
        vector<int> v;
        for (int o = 0; o < i; ++o) v.push_back(1);
        for (int o = 0; o < j; ++o) v.push_back(2);
        for (int o = 0; o < k; ++o) v.push_back(3);
        int cmask = 0;
        do {
          int sum = 0;
          for (int x : v) {
            sum += x;
            if (sum < 12)
              cmask |= (1 << sum);
            else
              break;
          }
        } while (next_permutation(v.begin(), v.end()));
        for (int mask = 0; mask < (1 << 12); ++mask) {
          if ((cmask & mask) == mask) {
            dp[mask] = min(dp[mask], i + j + k);
          }
        }
      }
    }
  }
}
int main() {
  prebuild();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
