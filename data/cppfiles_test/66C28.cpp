#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, MAX;
  cin >> t;
  vector<int> nums(t);
  for (int i = 0; i < t; i++) {
    cin >> nums[i];
  }
  MAX = *max_element(nums.begin(), nums.end());
  vector<int> res(MAX);
  int k = 1;
  for (int i = 0; i < MAX;) {
    if (k % 3 != 0 && k % 10 != 3) {
      res[i] = k;
      k++;
      i++;
    } else if (k % 3 == 0 || k % 10 == 3)
      k++;
  }
  for (int i = 0; i < t; i++) {
    nums[i]--;
    cout << res[nums[i]] << endl;
  }
  return 0;
}
