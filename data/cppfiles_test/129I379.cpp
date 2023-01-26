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
    vector<int> v;
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) v.push_back(i);
    }
    int m = v.size(), l = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int x = arr[i];
      if (x <= n && vis[x] > 1) {
        int r = vis[i], k = 1;
        while (r > 1) {
          if (l < m && (2 * v[l]) < x) {
            ans++;
            l++;
          } else {
            ans = -1;
            k = 0;
            break;
          }
          r--;
        }
        if (!k) break;
      }
      if (x > n) {
        if (l < m && (2 * v[l]) < x) {
          ans++;
          l++;
        } else {
          ans = -1;
          break;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
