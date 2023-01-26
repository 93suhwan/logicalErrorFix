#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    if (m < n - 1 || m > (n * (n - 1)) / 2)
      cout << "NO\n";
    else {
      int p;
      if (m == (n * (n - 1)) / 2)
        p = 1;
      else
        p = 2;
      if (p < k - 1)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}
