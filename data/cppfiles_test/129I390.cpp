#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n], vis[200005] = {0};
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      if (arr[i] <= n) vis[arr[i]]++;
    }
    sort(arr, arr + n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int x = arr[i];
      if (x > n) {
        int is = 0;
        for (int j = x - 1; j >= x - (n * 2); j--) {
          if (j >= 2 && x % j <= n && !vis[x % j] && x % j != 0) {
            vis[x % j]++;
            is = 1;
            ans++;
            break;
          }
        }
        if (!is) {
          ans = -1;
          break;
        }
      } else {
        if (vis[x] > 1) {
          int m = vis[x];
          int k = 1;
          while (m--) {
            int is = 0;
            for (int j = x - 1; j >= 2; j--) {
              if (x % j <= n && !vis[x % j] && x % j != 0) {
                vis[x % j]++;
                is = 1;
                ans++;
                break;
              }
            }
            if (!is) {
              k = 0;
              ans = -1;
              break;
            }
          }
          if (!k) break;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
