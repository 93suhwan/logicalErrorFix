#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k, p;
    cin >> n >> m >> k;
    p = (n * m) / 2 - k;
    if (n == m) {
      if (k % 2 == 0)
        cout << "yes";
      else
        cout << "no";
    } else if (n % 2 != 0) {
      if (k % m == m / 2)
        cout << "yes";
      else
        cout << "no";
    } else {
      if (p % n == n / 2)
        cout << "yes";
      else
        cout << "no";
    }
  }
}
