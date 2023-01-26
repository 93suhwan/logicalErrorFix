#include <bits/stdc++.h>
using namespace std;
const long long INF = 2e9 + 9;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    if (k == 0) {
      if (n % 2 == 0) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    } else if (m == 1) {
      if (k == 0 && (n % 2) == 0) {
        cout << "YES\n";
      } else
        cout << "NO\n";
    } else {
      if (n % 2 == 1) {
        if (m % 2 == 0) {
          k -= m / 2;
          n -= 1;
          if ((!(k >= 1) || m > 1) && (((2 * k) % k) % 2) == 0 &&
              ((2 * k) / m) % 2 == 0) {
            cout << "YES\n";
          } else {
            cout << "NO\n";
          }
        } else {
          cout << "NO\n";
        }
      } else {
        if ((!(k >= 1) || m > 1) && (((2 * k) % k) % 2) == 0 &&
            ((2 * k) / m) % 2 == 0) {
          cout << "YES\n";
        } else {
          cout << "NO\n";
        }
      }
    }
  }
  return 0;
}
