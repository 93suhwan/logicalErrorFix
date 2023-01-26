#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, d;
  cin >> n >> d;
  int ans = 0;
  vector<int> arr(2 * n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    arr[i + n] = arr[i];
  }
  vector<bool> vis(2 * n);
  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;
    for (int j = i; j < 2 * n; j += d) {
      int k = j;
      int cnt = 0;
      while (k < 2 * n && arr[k] == 1) {
        vis[k] = true;
        cnt++;
        k += d;
        if (k > 2 * n) {
          cout << "-1\n";
          return;
        }
      }
      ans = max(ans, cnt);
      j = k;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
