#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long T, g;
  cin >> T;
  for (g = 0; g < T; g++) {
    long long n, m, k, d;
    cin >> n >> m >> k;
    if (m > (n * (n - 1)) / 2)
      cout << "NO" << endl;
    else {
      long long p = n - 1;
      long long q = 2 * p - 1;
      if (m >= p && m <= q)
        d = 2;
      else if (m > q)
        d = 1;
      else if (m < p)
        d = -1;
      if (d == -1)
        cout << "NO" << endl;
      else {
        if (d < (k - 1))
          cout << "YES" << endl;
        else
          cout << "NO" << endl;
      }
    }
  }
  return 0;
}
