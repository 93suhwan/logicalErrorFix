#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n % 2 == 0) {
      cout << (n - 1) / 2 << " " << ((n - 1) / 2) + 1 << " " << 1 << "\n";
    } else {
      for (long long i = 3; i <= 9; i = i + 2) {
        if ((n - (i + 1)) % i != 0) {
          cout << i << " " << n - (i + 1) << " " << 1 << "\n";
          break;
        }
      }
    }
  }
}
