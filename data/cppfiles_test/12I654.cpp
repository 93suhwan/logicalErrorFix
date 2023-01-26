#include <bits/stdc++.h>
using namespace std;
long long t, n, m, a, b;
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m >> a;
    b = (n * m) / 2 - a;
    if (n % 2 == 0 && m % 2 == 0) {
      if (a % 2 == 0 && b % 2 == 0)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
    if (n % 2 == 1 && m % 2 == 0) {
      if (a % 2 == 1 && b % 2 == 0 && a >= m / 2)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
    if (n % 2 == 0 && m % 2 == 1) {
      if (a % 2 == 0 && b % 2 == 1 && b >= n / 2)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
    if (n % 2 == 1 && m % 2 == 1) {
      cout << "NO\n";
    }
  }
  return 0;
}
