#include <bits/stdc++.h>
using namespace std;
int split(int n) {
  int x = 1;
  while (x <= n) {
    if (n / x <= 10) return x;
    x *= 10;
  }
}
bool ispow10(int n) {
  int x = 1;
  while (x <= n) {
    if (x == n) return true;
    x *= 10;
  }
  return false;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int s, n;
    cin >> s >> n;
    vector<int> nums;
    nums.push_back(s);
    for (int q = 0; q < n - 1; q++) {
      int flag = 1;
      for (int i = 0; i < nums.size(); i++) {
        if (!ispow10(nums[i])) {
          int temp = nums[i];
          nums.erase(nums.begin() + i);
          nums.push_back(split(temp));
          nums.push_back(temp - split(temp));
          flag = 0;
          break;
        }
      }
      if (flag) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
          if (nums[i] > 1) {
            int temp = nums[i];
            nums.erase(nums.begin() + i);
            nums.push_back(split(temp));
            nums.push_back(temp - split(temp));
            break;
          }
      }
    }
    for (auto ele : nums) cout << ele << " ";
    cout << endl;
  }
}
