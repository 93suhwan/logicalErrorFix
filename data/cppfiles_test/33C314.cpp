#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    long long int ans = LLONG_MIN;
    long long int curr;
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        curr = (long long int)nums[i] * (long long int)nums[1];
      } else if (i == n - 1) {
        curr = (long long int)nums[i] * (long long int)nums[n - 2];
      } else {
        curr = (long long int)nums[i] *
               (long long int)max(nums[i - 1], nums[i + 1]);
      }
      ans = max(ans, curr);
    }
    cout << ans << endl;
  }
  return 0;
}
