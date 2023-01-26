#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
    }
    int ans = 0;
    while (!is_sorted(arr.begin(), arr.end())) {
      ans++;
      if (ans % 2) {
        for (int i = 0; i < n - 1; i += 2) {
          if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
          }
        }
      } else {
        for (int i = 1; i < n - 1; i += 2) {
          if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
          }
        }
      }
    }
    cout << ans << endl;
  }
}
