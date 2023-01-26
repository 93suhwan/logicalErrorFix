#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n;
  cin >> t;
  for (long long int i = 1; i <= t; i++) {
    cin >> n;
    long long int k = n / 3;
    if (3 * k == n) {
      cout << k << " " << k << endl;
    } else {
      long long int r1 = (n - (k + 1)) / 2;
      if (2 * (k + 1) + r1 == n) {
        cout << r1 << " " << k + 1 << endl;
      } else
        cout << k + 1 << " " << r1 << endl;
    }
  }
}
