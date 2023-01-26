#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n];
    long long k;
    cin >> k;
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr, arr + n);
    long long sum = 0;
    for (long long i = n - 1; i >= n - k; i--) {
      sum += (arr[i - k] / arr[i]);
    }
    for (long long i = 0; i < n - 2 * k; i++) {
      sum += arr[i];
    }
    cout << sum << "\n";
  }
}
