#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    int ans = 1;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      if (arr[i]) ans++;
    }
    int flag = 0;
    for (int i = 0; i < n - 1; i++) {
      if (arr[i] == 0 && arr[i + 1] == 0) {
        flag = 1;
        break;
      } else if (arr[i] == 1 && arr[i + 1] == 1)
        ans += 4;
    }
    if (flag) {
      cout << -1 << endl;
      continue;
    }
    cout << ans << endl;
  }
  return 0;
}
