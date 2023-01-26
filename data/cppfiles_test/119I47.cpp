#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr.begin(), arr.end());
  int i = 0, j = n - 1;
  while (i < j) {
    if (arr[i] < arr[j]) {
      int difference = arr[j] - arr[i];
      int factor = difference / 2;
      arr[j] -= factor;
      arr[i] += factor;
    }
    i++;
    j--;
  }
  int ans = INT_MIN;
  for (int i = 1; i < n; i++) {
    ans = max(ans, abs(arr[i] - arr[i - 1]));
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
