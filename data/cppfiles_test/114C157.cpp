#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (auto &i : nums) cin >> i;
  sort(nums.begin(), nums.end());
  int count = 0;
  for (int i = n - 1; count < n / 2; i--, count++) {
    cout << nums[i] << " " << nums[0] << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
