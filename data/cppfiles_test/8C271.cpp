#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n, k1, k2;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    if (n % 3 > 1) {
      k2 = (n / 3) + 1;
      k1 = n - (k2 * 2);
      cout << k1 << " " << k2 << endl;
    } else {
      k2 = n / 3;
      k1 = n - (k2 * 2);
      cout << k1 << " " << k2 << endl;
    }
  }
  return 0;
}
