#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b;
    cin >> a >> b;
    long long int xo = 0;
    long long int y = a - 1;
    if (y % 4 == 0)
      xo = y;
    else if (y % 4 == 1)
      xo = 1;
    else if (y % 4 == 2)
      xo = y + 1;
    else
      xo = 0;
    if (xo == b) {
      cout << a << endl;
      continue;
    }
    long long int z = xo ^ b;
    if (z != a)
      cout << a + 1 << endl;
    else {
      cout << a + 2 << endl;
    }
  }
  return 0;
}
