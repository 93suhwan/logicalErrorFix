#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long arr[n];
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr, arr + n, greater<int>());
    long long ans = 0;
    for (int i = 0; i < k; i++) {
      ans += arr[i + k] / arr[i];
    }
    for (int i = 2 * k; i < n; i++) {
      ans += arr[i];
    }
    cout << ans << "\n";
  }
  return 0;
}
