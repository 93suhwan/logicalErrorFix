#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    if (n % 2 == 0) {
      if (m % 2 == 0) {
        if (k & 1)
          cout << "NO" << endl;
        else
          cout << "YES" << endl;
      } else {
        if (k > n * (m - 1))
          cout << "NO" << endl;
        else {
          if (k & 1)
            cout << "NO" << endl;
          else
            cout << "YES" << endl;
        }
      }
    } else {
      if (n == 1) {
        if (k * 2 == n * m)
          cout << "YES" << endl;
        else
          cout << "NO" << endl;
      } else {
        int p = m / 2;
        if ((k % p != 0) || (k % p == 0 && (k / p) % 2 == 0))
          cout << "NO" << endl;
        else
          cout << "YES" << endl;
      }
    }
  }
  return 0;
}
