#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t, n, i, x;
  cin >> t;
  while (t--) {
    cin >> x >> n;
    long long p = n / 4;
    for (i = (4 * p) + 1; i <= n; i++) {
      if (x % 2 == 0)
        x = x - i;
      else
        x = x + i;
    }
    cout << x << "\n";
  }
  return 0;
}
