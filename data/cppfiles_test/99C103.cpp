#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long x, n;
    cin >> x >> n;
    long long a2, a4;
    if (x % 2 == 0)
      a2 = x + 1;
    else
      a2 = x - 1;
    a4 = x;
    if (n % 2 == 0) {
      if (n % 4 == 0)
        cout << a4 << endl;
      else
        cout << a2 << endl;
    } else {
      if ((n + 1) % 4 == 0) {
        if (x % 2 == 0)
          cout << x + (n + 1) << endl;
        else
          cout << x - (n + 1) << endl;
      } else if ((n - 1) % 4 == 0) {
        if (x % 2 == 0)
          cout << x - n << endl;
        else
          cout << x + n << endl;
      }
    }
  }
  return 0;
}
