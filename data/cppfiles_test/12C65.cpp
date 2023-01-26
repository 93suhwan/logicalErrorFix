#include <bits/stdc++.h>
using namespace std;
int main(void) {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m, k, tot, x, y, z;
    cin >> n >> m >> k;
    if (n % 2 == 0) {
      tot = (m / 2) * n;
      if (k > tot) {
        cout << "NO" << endl;
      } else {
        if (k % 2 == 0) {
          cout << "YES" << endl;
        } else {
          cout << "NO" << endl;
        }
      }
    } else {
      z = m / 2;
      k -= z;
      if (k < 0) {
        cout << "NO" << endl;
      } else {
        tot = (m / 2) * (n - 1);
        if (k > tot) {
          cout << "NO" << endl;
        } else {
          if (k % 2 == 0) {
            cout << "YES" << endl;
          } else {
            cout << "NO" << endl;
          }
        }
      }
    }
  }
}
