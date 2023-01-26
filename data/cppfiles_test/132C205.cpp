#include <bits/stdc++.h>
using namespace std;
long long mod_power(int x, int n) {
  long long res = 1;
  while (n > 0) {
    if (n % 2 != 0) res = (res * x) % long long(1e9 + 7);
    x = (x * x) % long long(1e9 + 7);
    n /= 2;
  }
  return res;
}
long long power(int x, int n) {
  long long res = 1;
  while (n > 0) {
    if (n % 2 != 0) res *= x;
    x *= x;
    n /= 2;
  }
  return res;
}
void solve() {
  long long arr[7];
  for (int i = 0; i < 7; i++) {
    cin >> arr[i];
  }
  cout << arr[0] << " " << arr[1] << " " << arr[6] - arr[0] - arr[1] << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
