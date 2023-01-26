#include <bits/stdc++.h>
using namespace std;
void printVec(vector<int>& nums) {
  for (int x : nums) {
    cout << x << " ";
  }
  cout << "\n";
}
void shiftSort(vector<int>& nums, vector<vector<int>>& res) {
  int n = nums.size();
  for (int i = 0; i < n; i++) {
    int index = i;
    int minVal = nums[i];
    for (int j = i + 1; j < n; j++) {
      if (nums[j] < minVal) {
        minVal = min(minVal, nums[j]);
        index = j;
      }
    }
    if (index != i) {
      int t = nums[index];
      for (int k = index; k >= i + 1; k--) {
        nums[k] = nums[k - 1];
      }
      nums[i] = t;
      res.push_back({i + 1, index + 1, index - i});
    }
  }
}
int main(void) {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<vector<int>> res;
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }
    shiftSort(nums, res);
    cout << res.size() << "\n";
    for (auto r : res) {
      cout << r[0] << " " << r[1] << " " << r[2] << "\n";
    }
  }
  return 0;
}
