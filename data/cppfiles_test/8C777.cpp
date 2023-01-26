#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long int t;
  cin >> t, t *= 1;
  while (t--) {
    long long int n;
    cin >> n;
    if (n % 3 == 0) {
      cout << n / 3 << " " << n / 3 << "\n";
    } else if (n % 3 == 1) {
      cout << n / 3 + 1 << " " << n / 3 << "\n";
    } else {
      cout << n / 3 << " " << n / 3 + 1 << "\n";
    }
  }
  return 0;
}
