#include <bits/stdc++.h>
using namespace std;
void solve() {}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    int ans = 0;
    for (int i = 0; i < k; i++) {
      ans += arr[i + k] / arr[i];
    }
    for (int i = 2 * k; i < n; i++) ans += arr[i];
    cout << ans << "\n";
  }
  return 0;
}
