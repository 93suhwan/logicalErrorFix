#include <bits/stdc++.h>
using namespace std;
const long long intmax = LONG_MAX;
const long long intmin = LONG_MIN;
int main() {
  long long tc;
  cin >> tc;
  while (tc--) {
    long long n, k, ans = 0, c = 0;
    cin >> n >> k;
    vector<long long> arr(n);
    for (long long i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    if (k == 0) {
      for (long long i = 0; i < n; i++) ans += arr[i];
      cout << ans << "\n";
      continue;
    }
    for (long long i = 0; i < n - 2 * k; i++) ans += arr[i];
    for (long long i = n - 2 * k; i < n; i++) {
      if (i + k >= n) break;
      ans += arr[i] / arr[i + k];
    }
    cout << ans << "\n";
  }
  return 0;
}
