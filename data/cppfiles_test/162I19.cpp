#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> nums, int x, int n) {
  vector<int> nums1(n, 0);
  for (int i = n - 1; i >= 0; i--) {
    if (i >= 2) {
      if (nums1[i] >= x) {
        int x = nums[i];
        x = x - x % 3;
        nums1[i - 1] += x * 1 / 3;
        nums1[i - 2] += x * 2 / 3;
      } else {
        if (nums1[i] + nums[i] >= x) {
          int x = nums[i] + nums1[i] - x;
          x = x - x % 3;
          nums1[i - 1] += x * 1 / 3;
          nums1[i - 2] += x * 2 / 3;
        } else
          return false;
      }
    } else if (nums[i] + nums1[i] < x)
      return false;
  }
  return true;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    int lo = 1, hi = 1000000000;
    int res = 1;
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      if (check(nums, mid, n)) {
        res = max(res, mid);
        lo = mid + 1;
      } else
        hi = mid - 1;
    }
    cout << res << endl;
  }
}
