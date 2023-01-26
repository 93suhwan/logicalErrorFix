#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long ans = arr[0] * arr[1];
  for (auto i = 2; i < n; i++) {
    ans = max(ans, arr[i] * arr[i - 1]);
  }
  cout << ans << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
