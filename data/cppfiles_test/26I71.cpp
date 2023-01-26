#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, i;
    cin >> n;
    long long int x = 1, y = 1000000007;
    for (i = 2; i <= (2 * n); i++) {
      x %= y;
      x *= (i % y);
      x %= y;
    }
    cout << x / 2 << "\n";
  }
  return 0;
}
