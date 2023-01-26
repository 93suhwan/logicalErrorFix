#include <bits/stdc++.h>
using namespace std;
const int N = 109;
int t, n, arr[N], k, ans;
int main() {
  ios::sync_with_stdio(0);
  cin.tie();
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr, arr + n);
    ans = 0;
    for (int i = n - 1, j = 0; i >= 0 && j < k; i--, j++) {
      if (arr[i] == arr[i - k]) {
        ans++;
      }
    }
    for (int i = 0; i < n - 2 * k; i++) {
      ans += arr[i];
    }
    cout << ans << "\n";
  }
  return 0;
}
