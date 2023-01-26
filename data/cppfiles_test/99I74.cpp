#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long x, n;
    cin >> x >> n;
    if (x & 1 != 1) {
      if (n % 4 == 0) {
        n = x;
      } else if (n % 4 == 1)
        n = x - n;
      else if (n % 4 == 2)
        n = x + 1;
      else
        n = x + n + 1;
    } else {
      if (n % 4 == 0) {
        n = x;
      } else if (n % 4 == 1) {
        n = x + n;
      } else if (n % 4 == 2) {
        n = x - 1;
      } else {
        n = x - n - 1;
      }
    }
    cout << n << "\n";
  }
  return 0;
}
