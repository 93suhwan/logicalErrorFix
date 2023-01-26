#include <bits/stdc++.h>
using namespace std;
long long int ar[200200], br[200200];
int main() {
  ios_base::sync_with_stdio(false);
  long long int t, j;
  cin >> t;
  for (j = 0; j < t; j++) {
    long long int z = 0, y = 0, k = 0, f, w = 0, n, i, x = 0, m = 0, a = 0,
                  b = 0, tt = 0;
    cin >> n >> m >> k;
    if (n % 2 == 0) {
      if (k % 2) x = 1;
      z = k / n;
      if (k % n) z++;
      if (2 * z > m) x = 1;
    }
    if (n % 2 == 0 && x == 0) {
      cout << "YES" << endl;
      continue;
    }
    x = 0;
    if (m % 2 == 0) {
      k = ((n * m) / 2) - k;
      if (k % 2) x = 1;
      z = k / m;
      if (k % m) z++;
      if (2 * z > n) x = 1;
    } else {
      cout << "NO" << endl;
      continue;
    }
    if (x == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
