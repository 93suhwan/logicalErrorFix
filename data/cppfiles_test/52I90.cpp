#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int a[n];
  int i;
  float mx = INT_MIN;
  float sum = 0;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (mx < a[i]) {
      mx = a[i];
    }
    sum += a[i];
  }
  long double ans1 = (sum - mx) * 1.000000000 / (n - 1);
  long double ans = ans1 + mx;
  cout << setprecision(18) << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
