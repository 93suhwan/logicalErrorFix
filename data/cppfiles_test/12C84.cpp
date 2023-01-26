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
        if ((n * m / 2 - k) % 2 == n / 2 % 2 && (n * m / 2 - k) >= n / 2)
          cout << "YES" << endl;
        else
          cout << "NO" << endl;
      }
    } else {
      if (k % 2 == m / 2 % 2 && k >= m / 2)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
  return 0;
}
