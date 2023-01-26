#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    double sum = 0;
    double ans = 0;
    int n;
    cin >> n;
    long maxi = LONG_MIN;
    long a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
      maxi = max(maxi, a[i]);
    }
    sum = sum - maxi;
    ans = (double)sum / (n - 1);
    ans += maxi;
    cout << std::fixed;
    cout << std::setprecision(9) << ans << "\n";
  }
  return 0;
}
