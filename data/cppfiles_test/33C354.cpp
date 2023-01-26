#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (long long i = 0; i <= n - 1; i++) {
    cin >> arr[i];
  }
  long long ans = 0;
  for (long long i = 1; i <= n - 1; i++) {
    ans = max(ans, 1ll * arr[i] * arr[i - 1]);
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
