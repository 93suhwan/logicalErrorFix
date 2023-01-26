#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n;
  cin >> t;
  for (long long int i = 1; i <= t; i++) {
    cin >> n;
    long long int k = n / 3;
    if (3 * k == n) {
    } else {
      long long int r1 = (n - (k + 1)) / 2;
      cout << k + 1 << " " << r1 << endl;
    }
  }
}
