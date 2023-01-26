#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, k;
  cin >> n >> k;
  long long int flag = 1;
  if (n % 2 == 0) flag = 0;
  if (flag == 0) {
    long long int x = k / 2;
    long long int sum = n + x;
    if (k % 2 != 0) {
      sum = sum - k;
    }
    cout << sum << "\n";
    return;
  } else {
    long long int x = k / 2;
    long long int sum = n - x;
    if (k % 2 != 0) {
      sum = sum + k;
    }
    cout << sum << "\n";
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
