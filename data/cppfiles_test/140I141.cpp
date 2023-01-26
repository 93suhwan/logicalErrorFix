#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n, p, q, c;
  cin >> t;
  while (t--) {
    cin >> n;
    c = 0;
    for (long long int i = 2; i <= sqrt(n); i++) {
      p = sqrt(i);
      q = cbrt(i);
      if (p * p == i || q * q * q == i) {
        c++;
      }
    }
    cout << c + 1 << endl;
  }
  return 0;
}
