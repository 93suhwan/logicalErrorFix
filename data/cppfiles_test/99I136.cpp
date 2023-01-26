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
  if (flag == 0) {
    if (k % 2 == 0) {
      cout << n + 1 << "\n";
      return;
    }
    long long int x = k / 2;
    if (x % 2 == 0)
      cout << n - k << "\n";
    else
      cout << n + k + 1 << "\n";
    return;
  } else {
    if (k % 2 == 0) {
      cout << n - 1 << "\n";
      return;
    }
    long long int x = k / 2;
    if (x % 2 == 0)
      cout << n + k << "\n";
    else
      cout << n - k - 1 << "\n";
    return;
  }
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
