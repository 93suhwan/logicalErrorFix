#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, x, y, z;
    cin >> n;
    if (n <= 6) {
      cout << 15 << endl;
    } else {
      if (n % 2 != 0) {
        n = n + 1;
      }
      cout << n / 2 * 5 << endl;
    }
  }
  return 0;
}
