#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int a[n];
  int i;
  double mx = INT_MIN;
  double sum = 0;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (mx < a[i]) {
      mx = a[i];
    }
    sum += a[i];
  }
  double ans1 = (sum - mx) * 1.0 / (n - 1);
  double ans = ans1 + mx;
  cout << setprecision(18) << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
