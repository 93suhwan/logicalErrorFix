#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long x, y, z;
    x = n % 6;
    y = n % 8;
    z = n % 10;
    if (x == 0)
      cout << n / 6 * 15 << endl;
    else if (y == 0)
      cout << n / 8 * 20 << endl;
    else if (z == 0)
      cout << n / 10 * 25 << endl;
    else if ((n / 6 + 1) * 6 <= (n / 8 + 1) * 8 &&
             (n / 6 + 1) * 6 <= (n / 10 + 1) * 10)
      cout << (n / 6 + 1) * 15 << endl;
    else if ((n / 8 + 1) * 8 <= (n / 6 + 1) * 6 &&
             (n / 8 + 1) * 8 <= (n / 10 + 1) * 10)
      cout << (n / 8 + 1) * 20 << endl;
    else if ((n / 10 + 1) * 10 <= (n / 6 + 1) * 6 &&
             (n / 10 + 1) * 10 <= (n / 8 + 1) * 8)
      cout << (n / 10 + 1) * 25 << endl;
  }
}
