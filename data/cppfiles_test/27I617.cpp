#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    long long l;
    if (n >= 3) {
      l = n + n * (n - 3) / 2;
    } else {
      if (n == 1) {
        l = 0;
      } else {
        l = 1;
      }
    }
    if (n % 2 == 0) {
      if (l > m) {
        if (n / 2 < k - 1) {
          cout << "YES\n";
        } else {
          cout << "NO\n";
        }
      } else if (m == l) {
        if (k > 1) {
          cout << "YES\n";
        } else {
          cout << "NO\n";
        }
      } else {
        cout << "NO\n";
      }
    } else {
      if (l > m) {
        if (n / 2 + 1 < k - 1) {
          cout << "YES\n";
        } else {
          cout << "NO\n";
        }
      } else if (m == l) {
        if (k > 1) {
          cout << "YES\n";
        } else {
          cout << "NO\n";
        }
      } else {
        cout << "NO\n";
      }
    }
  }
  return 0;
}
