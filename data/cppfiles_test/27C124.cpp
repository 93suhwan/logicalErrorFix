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
    long long p = n - 1;
    long long q = (n * (n - 1)) / 2;
    if (n == 1 && m == 0 && k > 1)
      cout << "YES" << endl;
    else if (n == 2 && m == 1 && k > 2)
      cout << "YES" << endl;
    else if (m > q || m < p)
      cout << "NO" << endl;
    else {
      if (m >= p && m < q) {
        d = 2;
      } else if (m == q)
        d = 1;
      if (d < (k - 1))
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
  return 0;
}
