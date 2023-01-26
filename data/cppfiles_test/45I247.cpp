#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, arr[1000];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int ans = 1;
    int f = 1;
    for (int i = 0; i < n; i++) {
      if (arr[i] == arr[i + 1] && arr[i] == 0) {
        ans = 0;
        f = 0;
        break;
      }
      if (arr[i] == arr[i + 1] && arr[i] == 1) {
        ans += 5;
      }
      if (arr[i] == 1) ans += 1;
    }
    cout << ans << "\n";
  }
  return 0;
}
