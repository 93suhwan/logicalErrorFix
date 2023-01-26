#include <bits/stdc++.h>
using namespace std;
int t, n, m, k, l, r;
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    l = n % 2 * m / 2;
    r = (n - n % 2) * (m - m % 2) / 2 + l;
    if (l <= k && k <= r && (k - l) % 2 == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
