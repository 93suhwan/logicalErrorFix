#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
void solve() {
  int n;
  cin >> n;
  string str = to_string(n);
  vector<int> nums(2);
  for (int i = 0; i < str.size(); ++i) {
    nums[i % 2] *= 10;
    nums[i % 2] += str[i] - '0';
  }
  --nums[0];
  --nums[1];
  int ans = 0;
  if (nums[0] < 0 || nums[1] < 0) ans = max(nums[0], nums[1]);
  cout << nums[0] * nums[1] + 2 * (nums[0] + nums[1]) + 2 << endl;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) solve();
  return 0;
}
