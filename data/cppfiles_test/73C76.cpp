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
      cin >> arr[i];
    }
    int ans = 1;
    while (!is_sorted(arr.begin(), arr.end())) {
      if (ans % 2) {
        for (int i = 0; i < n - 1; i++) {
          if (((i + 1) % 2) && arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
        }
      } else {
        for (int i = 0; i < n - 1; i++) {
          if (!((i + 1) % 2) && arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
        }
      }
      ans++;
    }
    cout << ans - 1 << endl;
  }
  return 0;
}
