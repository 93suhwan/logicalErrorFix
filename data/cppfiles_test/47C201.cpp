#include <bits/stdc++.h>
using namespace std;
void fun() {
  long long n, k, ans(0);
  cin >> n >> k;
  vector<long long> nums(n);
  for (long long i = 0; i < n; i++) cin >> nums[i];
  sort(nums.begin(), nums.end());
  for (long long i = 0; i < n && nums[i] < 0; i += k) ans += 2 * abs(nums[i]);
  for (long long i = n - 1; i >= 0 && nums[i] > 0; i -= k) ans += 2 * nums[i];
  ans -= max(abs(nums[n - 1]), abs(nums[0]));
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) fun();
  return 0;
}
