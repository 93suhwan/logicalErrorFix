#include <bits/stdc++.h>
using namespace std;
void solve() {}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    vector<long long int> arr(n);
    for (long long int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    long long int ans = 0;
    for (long long int i = 0; i < k; i++) {
      ans += arr[i + k] / arr[i];
    }
    for (long long int i = 2 * k; i <= n; i++) ans += arr[i];
    cout << ans << "\n";
  }
  return 0;
}
