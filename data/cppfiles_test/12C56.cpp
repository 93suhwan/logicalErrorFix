#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    if (n % 2 == 0 && m % 2 == 0)
      cout << (k % 2 == 0 ? "YES" : "NO") << endl;
    else if (n % 2 == 1)
      cout << ((k - m / 2) >= 0 && (k - m / 2) % 2 == 0 ? "YES" : "NO") << endl;
    else
      cout << (k <= n * (m - 1) / 2 && k % 2 == 0 ? "YES" : "NO") << endl;
  }
  return 0;
}
