#include <bits/stdc++.h>
using namespace std;
pair<int, int> arr[90010];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k, i, j;
    cin >> n >> m;
    for (i = 0; i < n * m; i++) {
      int a;
      cin >> a;
      arr[i] = {a, i};
    }
    sort(arr, arr + n * m);
    for (i = 0; i < n * m; i++) arr[i].second = -arr[i].second;
    int ans = 0;
    for (i = 0; i < n; i++) {
      sort(arr + i * m, arr + i * m + m);
      for (j = 0; j < m; j++) {
        for (k = 0; k < j; k++) {
          if (arr[i * m + k].second > arr[i * m + j].second) ans++;
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
