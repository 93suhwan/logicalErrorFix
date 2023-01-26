#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long int n, m, i, j, k, x, t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    long long int arr[n];
    for (i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr, arr + n);
    long long int sum = 0;
    x = n - 2 * k;
    for (i = 0; i < x; i++) {
      sum += arr[i];
    }
    j = 1;
    m = -2842;
    for (i = x; i <= n - 1; i++) {
      if (i == n - 1) {
        m = max(m, j);
        break;
      }
      if (arr[i] == arr[i + 1]) {
        j++;
      } else {
        m = max(m, j);
        j = 1;
      }
    }
    cout << sum + max((m - k), 0ll) << "\n";
  }
}
