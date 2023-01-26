#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int arr[n];
    long long int sum = 0;
    for (long long int i = 0; i < n; i++) {
      cin >> arr[i];
      sum += arr[i];
    }
    long long int n1 = 0;
    long long int n0 = 0;
    if (sum == 0) {
      cout << 0 << "\n";
      continue;
    }
    for (long long int i = 0; i < n; i++) {
      if (arr[i] == 0) {
        n0++;
      }
      if (arr[i] == 1) {
        n1++;
      }
    }
    if (n1 == 0) {
      cout << 0 << "\n";
      continue;
    }
    if (sum == 1) {
      long long int t = pow(2, n0);
      cout << t << "\n";
      continue;
    }
    long long int ans = (n0 + 1) * n1;
    if (n1 == 1) {
      if (n0 > 1) {
        ans++;
        cout << ans << "\n";
      } else
        cout << ans << "\n";
    } else {
      cout << ans << "\n";
    }
  }
  return 0;
}
