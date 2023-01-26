#include <bits/stdc++.h>
using namespace std;
vector<vector<long long int>> nums(200005, vector<long long int>(21, 0));
void solve() {
  long long int l, r;
  cin >> l >> r;
  long long int res = INT_MAX;
  for (long long int p = 0; p < 21; p++) {
    res = min(res, (r - l + 1) - (nums[r][p] - nums[l - 1][p]));
  }
  cout << res << "\n";
}
int main() {
  long long int t;
  cin >> t;
  for (long long int i = 1; i < 200004; i++) {
    long long int j = 0, k = i;
    while (k) {
      nums[i][j++] = k & 1;
      k /= 2;
    }
    for (long long int p = 0; p < 21; p++) nums[i][p] += nums[i - 1][p];
  }
  while (t--) {
    solve();
  }
}
