#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int arr[n];
    for (long long int i = 0; i < n; i++) cin >> arr[i];
    long long int ans = 1;
    for (long long int i = 0; i < n - 1; i++) {
      if (arr[i] == 0 && arr[i + 1] == 0) {
        ans = -1;
        break;
      } else if (arr[i] == 1 && arr[i + 1] == 1) {
        ans += 5;
      } else {
        ans += 1;
      }
    }
    cout << ans << endl;
  }
}
