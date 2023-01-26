#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, k;
  cin >> n >> k;
  if (k == 0) {
    cout << n << "\n";
    return;
  }
  long long int flag = 1;
  if (n % 2 == 0) flag = 0;
  long long int ans = n;
  if (flag == 0) {
    if (k % 4 == 1) {
      ans = n - k;
    } else if (k % 4 == 2) {
      ans += 1;
    } else if (k % 4 == 3) {
      long long int q = (k / 4) + 1;
      q = q * 4;
      ans += q;
    } else if (k % 4 == 0) {
      ans += 0;
    }
  } else {
    if (k % 4 == 1) {
      ans = n + k;
    } else if (k % 4 == 2) {
      ans += -1;
    } else if (k % 4 == 3) {
      long long int q = (k / 4) + 1;
      q = q * 4 * -1;
      ans += q;
    } else if (k % 4 == 0) {
      ans += 0;
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  long long int t = 1;
  cin >> t;
  cout << fixed << setprecision(9) << "\n";
  while (t--) {
    solve();
  }
  return 0;
}
