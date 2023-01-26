#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n, p, q, c;
  cin >> t;
  while (t--) {
    cin >> n;
    c = (long long int)sqrt(n) + (long long int)cbrt(n) -
        (long long int)(sqrt(cbrt(n)));
    cout << c << endl;
  }
  return 0;
}
