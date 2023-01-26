#include <bits/stdc++.h>
const long long int sz = 2 * 1e5 + 5;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    long long int sum = 0;
    for (long long int i = 0; i < n - 1; i++) {
      sum += a[i];
    }
    double ans = (sum * 1.0 / (n - 1));
    ans += a[n - 1];
    cout << fixed << setprecision(9) << ans << "\n";
  }
}
