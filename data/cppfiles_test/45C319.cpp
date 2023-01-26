#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  int ans = 1, zero = 0;
  for (int i = 0; i < n; i++) {
    int curr = i;
    if (arr[i] == 0) {
      while (i < n && arr[i] == 0) i++;
      if (i == curr) i++;
      if (i - curr >= 2) {
        cout << -1 << "\n";
        return;
      }
    } else {
      while (i < n && arr[i] == 1) i++;
      if (i == curr) i++;
      if (i - curr > 1) {
        ans += (5 * (i - curr - 1));
        ans++;
      } else
        ans++;
    }
    if (i != curr) i--;
  }
  cout << ans << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
