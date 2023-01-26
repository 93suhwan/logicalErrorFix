#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int ans = n / 3;
    if (n % 3 == 0) {
      cout << ans << " " << ans << "\n";
    } else if (n % 3 == 1) {
      cout << ans + 1 << " " << ans << "\n";
    } else {
      cout << ans << " " << ans + 1 << "\n";
    }
  }
}
