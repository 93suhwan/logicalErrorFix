#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, x, n;
  cin >> t;
  while (t--) {
    cin >> x >> n;
    if (x % 2 == 0) {
      if (n % 4 == 0)
        cout << x << endl;
      else if (n % 4 == 1)
        cout << x - n << endl;
      else if (n % 4 == 2)
        cout << 1 + x << endl;
      else
        cout << n + 1 + x << endl;
    } else {
      if (n % 4 == 0)
        cout << x + 1 << endl;
      else if (n % 4 == 1)
        cout << x + n + 1 << endl;
      else if (n % 4 == 2)
        cout << x << endl;
      else
        cout << x - n << endl;
    }
  }
}
