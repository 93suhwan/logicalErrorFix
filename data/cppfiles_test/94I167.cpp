#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string str = to_string(n);
  vector<int> nums(2, -1);
  for (int i = 0; i < str.size(); ++i)
    nums[i % 2] = nums[i % 2] * 10 + str[i] - '0';
  cout << nums[0] * nums[1] + 2 * (nums[0] + nums[1]) + 2 << endl;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) solve();
  return 0;
}
