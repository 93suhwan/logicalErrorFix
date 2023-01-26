#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, x, y, z;
    cin >> n;
    if (n % 10 == 0) {
      cout << (n / 10) * 25 << endl;
    } else if (n % 8 == 0) {
      cout << (n / 8) * 20 << endl;
    } else if (n % 6 == 0) {
      cout << (n / 6) * 15 << endl;
    } else if (n % 10 == 9) {
      cout << (n / 10) * 25 + 25 << endl;
    } else if (n % 10 == 8 or n % 10 == 7) {
      x = n / 10 * 25 + 20;
      z = n / 8 * 20 + 20;
      cout << min(x, z) << endl;
    } else if (n % 10 <= 6) {
      x = n / 10 * 25 + 15;
      z = n / 6 * 15 + 15;
      cout << min(x, z) << endl;
    }
  }
  return 0;
}
