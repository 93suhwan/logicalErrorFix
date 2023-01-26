#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, m, k, a, b;
    cin >> n >> m >> k;
    b = k;
    if (n % 2 == 0 && m % 2 == 0) {
      if (k % 2 == 0)
        cout << "YES"
             << "\n";
      else
        cout << "NO"
             << "\n";
    } else if ((n == 1 && k != (n * m) / 2) || (m == 1 && k != 0))
      cout << "NO"
           << "\n";
    else if (n % 2 == 0 && m % 2 != 0) {
      a = (n * (m - 1)) / 2;
      if (k % 2 != 0) k++;
      if (k <= a && a - k + (n / 2) >= ((n * m) / 2) - b)
        cout << "YES"
             << "\n";
      else
        cout << "NO"
             << "\n";
    } else {
      a = (m * (n - 1)) / 2;
      k -= (m / 2);
      if (k % 2 != 0) k++;
      if (k <= a && a - k >= ((n * m) / 2) - b)
        cout << "YES"
             << "\n";
      else
        cout << "NO"
             << "\n";
    }
  }
}
