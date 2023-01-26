#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    cout << endl;
    long long n;
    cin >> n;
    if (n % 3 == 0) {
      cout << n / 3 << " " << n / 3 << endl;
      continue;
    } else if (n % 3 == 1) {
      cout << ((n - 1) / 3) + 1 << " " << (n - 1) / 3 << endl;
      continue;
    } else {
      cout << ((n - 1) / 3) << " " << ((n - 1) / 3) + 1 << endl;
      continue;
    }
  }
  return 0;
}
