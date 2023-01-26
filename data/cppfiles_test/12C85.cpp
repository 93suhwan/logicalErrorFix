#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int p = (n % 2) * m + (m % 2) * n;
    if (n % 2 == 1) {
      k -= m / 2;
      if (k < 0 || k % 2 == 1)
        cout << "NO" << endl;
      else
        cout << "YES" << endl;
    } else if (m % 2 == 1) {
      k = n * m / 2 - k;
      k -= n / 2;
      if (k < 0 || k % 2 == 1)
        cout << "NO" << endl;
      else
        cout << "YES" << endl;
    } else {
      if (k % 2 == 1)
        cout << "NO" << endl;
      else
        cout << "YES" << endl;
    }
  }
  return 0;
}
