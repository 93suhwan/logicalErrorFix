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
    for (long long i = n - 1; i >= 0; i--) {
      if (k == 0) {
        for (long long j = 0; j < i; j++) ans += arr[j];
        break;
      }
      k--;
      if (i - 2 >= 0) {
        ans += arr[i - 2] / arr[i];
      } else
        ans += arr[i - 1] / arr[i];
      c++;
      if (c == 2) {
        c = 0;
        if (k)
          i -= 2;
        else
          i--;
        continue;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
