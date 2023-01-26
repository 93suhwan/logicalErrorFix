#include <bits/stdc++.h>
using namespace std;
int main() {
  using namespace std;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    int ans = 0;
    int diff = 0;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
      diff = 0;
      if (arr[i] > i && i == 0) {
        diff = arr[i] - i;
        ans += diff;
      }
      if (arr[i] > i && i > 0) {
        diff = arr[i] - arr[i - 1] - 1;
        ans += diff;
      }
    }
    cout << ans - 1 << endl;
  }
  return 0;
}
