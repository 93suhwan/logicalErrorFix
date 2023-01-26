#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int x, n, out = 0;
    cin >> x >> n;
    if ((x % 2 == 1 || x % 2 == (-1)) && n % 2 == 0 && n % 4 == 0) {
      out = x;
    } else if ((x % 2 == 1 || x % 2 == (-1)) && n % 2 == 0 && n % 4 == 2) {
      out = x - 1;
    } else if ((x % 2 == 1 || x % 2 == (-1)) && n % 2 == 1 && n % 4 == 3) {
      out = x - 1 - n;
    } else if ((x % 2 == 1 || x % 2 == (-1)) && n % 2 == 1 && n % 4 == 1) {
      out = x + n;
    } else if (x % 2 == 0 && n % 2 == 1 && n % 4 == 1) {
      out = x - n;
    } else if (x % 2 == 0 && n % 2 == 1 && n % 4 == 3) {
      out = x + 1 + n;
    } else if (x % 2 == 0 && n % 2 == 0 && n % 4 == 0) {
      out = x;
    } else if (x % 2 == 0 && n % 2 == 0 && n % 4 == 2) {
      out = x + 1;
    }
    cout << out << endl;
  }
  return 0;
}
