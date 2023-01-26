#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18 + 5;
void solve() {
  long long n;
  cin >> n;
  long long arr[n];
  for (long long i = 0; i < n; i++) cin >> arr[i];
  long long res = 1;
  for (long long i = 0; i < n; i++) {
    if (i == 0) {
      res += arr[i] == 1;
    } else if (arr[i - 1] == 1) {
      if (arr[i] == 1) res += 5;
    } else if (arr[i - 1] == 0) {
      if (arr[i] == 1)
        res += 1;
      else {
        cout << -1 << '\n';
        return;
      }
    }
  }
  cout << res << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long T;
  cin >> T;
  while (T--) solve();
}
