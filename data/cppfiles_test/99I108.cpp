#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x, n;
    cin >> x >> n;
    if (!n)
      cout << x << endl;
    else if ((n - 1) % 4 == 0) {
      if (x & 1)
        cout << x + n << endl;
      else
        cout << x - n << endl;
    } else if ((n - 1) % 4 == 1) {
      if (x & 1)
        cout << x + (n - 1) - n << endl;
      else
        cout << x - (n - 1) + n << endl;
    } else if ((n - 1) % 4 == 2) {
      if (x & 1)
        cout << x + (n - 2) - (n + (n - 1)) << endl;
      else
        cout << x - (n - 2) + (n + (n - 1)) << endl;
    } else if ((n - 1) % 4 == 3) {
      if (x & 1)
        cout << x + (n - 2) - ((n - 1) + (n - 2)) + n;
      else
        cout << x - (n - 2) + ((n - 1) + (n - 2)) - n;
    }
  }
}
