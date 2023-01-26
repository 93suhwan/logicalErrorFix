#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    long long xx = fabs(a - b);
    long long d = xx / 2;
    if ((a + b) % 2) {
      long long yy = a + b - 2 * d + 1;
      cout << yy << '\n';
      for (long long i = d; i <= a + b - d; i++) {
        cout << i << " ";
      }
      cout << '\n';
    } else {
      long long yy = (a + b - 2 * d) / 2 + 1;
      cout << yy << '\n';
      for (long long i = d; i <= a + b - d; i += 2) {
        cout << i << " ";
      }
      cout << '\n';
    }
  }
  return 0;
}
