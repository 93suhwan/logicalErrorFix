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
    else if (x >= y && x >= z)
      cout << (n / 6 + 1) * 15 << endl;
    else if (y >= x && y >= z)
      cout << (n / 8 + 1) * 20 << endl;
    else if (z >= x && z >= y)
      cout << (n / 10 + 1) * 25 << endl;
  }
}
