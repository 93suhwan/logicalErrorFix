#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    if (m < n - 1 || m > n * (n - 1) / 2) {
      cout << "NO" << endl;
    } else if (n == 1 && k <= 1) {
      cout << "NO" << endl;
    } else if (n == 2 && k <= 2) {
      cout << "NO" << endl;
    } else if (m < n * (n - 1) / 2 && k <= 3) {
      cout << "NO" << endl;
    } else if (m == n * (n - 1) / 2 && k <= 2) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
