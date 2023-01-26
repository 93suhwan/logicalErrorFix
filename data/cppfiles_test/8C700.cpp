#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if (n % 3 == 0) {
      cout << n / 3 << " " << n / 3 << endl;
    } else {
      long long int x = floor(n / 3.0);
      if (x + 2 * (x + 1) == n) {
        cout << x << " " << x + 1 << endl;
      } else {
        cout << x + 1 << " " << x << endl;
      }
    }
  }
  return 0;
}
