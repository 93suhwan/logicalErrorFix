#include <bits/stdc++.h>
using namespace std;
long long int MOD = 1000000007;
const long long int INF = 1e18;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int x, n, i, r, p;
    cin >> x >> n;
    if (x % 2 == 0) {
      if (n % 4 == 0)
        cout << x << "\n";
      else if (n % 4 == 2)
        cout << x + 1 << "\n";
      else if (n % 4 == 1) {
        cout << x - n << "\n";
      } else {
        cout << n + 1 + x << "\n";
      }
    } else {
      if (n % 4 == 0)
        cout << x << "\n";
      else if (n % 4 == 1)
        cout << x + n << "\n";
      else if (n % 4 == 2) {
        cout << x - 1 << "\n";
      } else {
        cout << x - (n + 1) << "\n";
      }
    }
  }
}
