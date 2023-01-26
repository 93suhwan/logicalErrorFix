#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    long long int avg = 0;
    for (int i = 0; i < n - 1; ++i) avg += a[i];
    double ans = (avg * 1.0) / ((n - 1) * 1.0);
    ans += (a[n - 1] * 1.0);
    cout << fixed;
    cout << setprecision(9);
    cout << ans << "\n";
  }
  return 0;
}
