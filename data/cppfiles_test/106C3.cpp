#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if (n == 1) {
      cout << 1 << "\n";
      continue;
    } else {
      for (long long int i = 1; i <= n; i++) {
        cout << i + 1 << ' ';
      }
      cout << "\n";
    }
  }
  return 0;
}
