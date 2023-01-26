#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int x, n;
    cin >> x >> n;
    if (x % 2 == 0) {
      if (n % 4 == 0)
        cout << x << endl;
      else if (n % 4 == 1)
        cout << x - n << endl;
      else if (n % 4 == 2)
        cout << x + 1 << endl;
      else
        cout << x + 1 + n << endl;
    } else {
      if (n % 4 == 0)
        cout << x << endl;
      else if (n % 4 == 1)
        cout << x + n << endl;
      else if (n % 4 == 2)
        cout << x - 1 << endl;
      else
        cout << x - 1 - n << endl;
    }
  }
}
