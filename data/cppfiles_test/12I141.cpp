#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    if (m == 1) {
      if (k >= 1) {
        cout << "NO"
             << "\n";
      } else {
        cout << "YES"
             << "\n";
      }
    } else if (n == 1) {
      if (k == (m / 2)) {
        cout << "YES"
             << "\n";
      } else {
        cout << "NO"
             << "\n";
      }
    } else {
      if ((n % 2) == 0 && (m % 2) == 0) {
        if (k % 2 == 0) {
          cout << "YES"
               << "\n";
        } else {
          cout << "NO"
               << "\n";
        }
      } else if ((n % 2) != 0 && (m % 2) == 0) {
        if (k % (m) == m / 2) {
          cout << "YES"
               << "\n";
        } else {
          cout << "NO"
               << "\n";
        }
      } else if ((n % 2) == 0 && (m % 2) != 0) {
        if (k % 2 == 0 && k <= (n * ((m - 1) / 2))) {
          cout << "YES"
               << "\n";
        } else {
          cout << "NO"
               << "\n";
        }
      } else {
        cout << "NO"
             << "\n";
      }
    }
  }
}
