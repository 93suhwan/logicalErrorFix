#include <bits/stdc++.h>
const long long m = 1e9 + 7;
using namespace std;
long long power(long long x, long long y, long long mod) {
  int res = 1;
  while (y) {
    if (y % 2 == 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}
bool check(long long mid, long long n, long long arr[]) {
  long long arr2[n];
  for (long long i = 0; i < n; i++) arr2[i] = arr[i];
  for (long long i = n - 1; i >= 2; i--) {
    if (arr2[i] < mid) return false;
    long long temp = min(arr[i], max(arr2[i] - mid, 0ll));
    temp /= 3;
    arr2[i - 1] += temp;
    arr2[i - 2] += (2 * temp);
  }
  for (long long i = 0; i < n; i++)
    if (arr2[i] < mid) return false;
  return true;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
    }
    long long low = 0, high = 1e18;
    long long ans = 0;
    while (low <= high) {
      long long mid = (low + high) / 2;
      if (check(mid, n, arr)) {
        ans = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    cout << ans << "\n";
  }
}
