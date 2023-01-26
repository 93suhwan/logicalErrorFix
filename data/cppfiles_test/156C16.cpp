#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long maxn = 2e5 + 9;
void init() {}
vector<long long> preSum;
bool solve(vector<long long>& arr, long long x, long long k, long long sum) {
  if (sum - x <= k) {
    return true;
  }
  long long tSum = sum;
  long long n = arr.size();
  if (x >= n - 1) {
    if (arr[n - 1] * n <= k) {
      return true;
    }
  }
  for (long long i = n - 2; i >= 0; --i) {
    long long remMoves = x - (i + 1);
    if (remMoves < 0) {
      continue;
    }
    long long smallestNum = arr[n - 1] - remMoves;
    long long newSum = tSum - preSum[i] - arr[n - 1] + smallestNum * (i + 2);
    if (newSum <= k) {
      return true;
    }
  }
  return false;
}
void test_case(long long tc) {
  long long n, k;
  cin >> n >> k;
  vector<long long> arr(n);
  long long sum = 0;
  for (long long i = 0; i <= n - 1; ++i) {
    cin >> arr[i];
    sum += arr[i];
  }
  preSum = vector<long long>(n, 0);
  sort(arr.begin(), arr.end(), greater<long long>());
  preSum[0] = arr[0];
  for (long long i = 1; i <= n - 1; ++i) preSum[i] = preSum[i - 1] + arr[i];
  long long start = 0, end = 1e18;
  long long ans = 0;
  while (end >= start) {
    long long mid = start + (end - start) / 2;
    if (solve(arr, mid, k, sum)) {
      ans = mid;
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long tc = 1; tc <= t; ++tc) test_case(tc);
}
