#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, i, k;
  cin >> n >> k;
  long long int arr[n];
  for (i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  reverse(arr, arr + n);
  long long int ans = 0;
  long long int cnt = 0;
  bool vis[n];
  for (i = 0; i < n; i++) vis[i] = false;
  for (i = 0; cnt < k && i < n; i++, cnt++) {
    ans = ans + (arr[i + k] / arr[i]);
    vis[i + k] = true;
    vis[i] = true;
  }
  while (i < n) {
    if (vis[i] == false) ans = ans + arr[i];
    i++;
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
