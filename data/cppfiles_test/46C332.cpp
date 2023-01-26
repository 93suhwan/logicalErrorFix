#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    int mx = *max_element(arr.begin(), arr.end());
    int ans = 0;
    int last = arr[n - 1];
    for (int i = n - 1; i >= 0; i--) {
      if (mx == arr[i] && mx == last) {
        break;
      }
      if (arr[i] > last) {
        last = arr[i];
        ans++;
      }
    }
    cout << ans << endl;
  }
}
