#include <bits/stdc++.h>
using namespace std;
using namespace std;
int32_t main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b, c;
    cin >> a >> b >> c;
    if (a % 2 != 0 && b % 2 != 0 && c % 2 != 0)
      cout << 0 << '\n';
    else if ((a % 2 != 0 && b % 2 != 0) || (b % 2 != 0 && c % 2 != 0))
      cout << 1 << '\n';
    else if (a % 2 != 0 && c % 2 != 0)
      cout << 0 << '\n';
    else if (a % 2 != 0 || c % 2 != 0)
      cout << 1 << '\n';
    else
      cout << 0 << '\n';
  }
  return 0;
}
