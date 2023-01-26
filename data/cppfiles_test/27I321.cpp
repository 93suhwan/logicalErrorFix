#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    unsigned long long int upper = 0;
    if (n % 2 == 0)
      upper = n / 2 * (n - 1);
    else
      upper = (n - 1) / 2 * n;
    if (m > upper || (k == 1)) {
      cout << "NO\n";
    } else if (m < upper && k <= 3) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}
