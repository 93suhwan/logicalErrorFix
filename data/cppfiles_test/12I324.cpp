#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int m, n, k;
    cin >> m >> n >> k;
    if (m % 2 == 1) {
      swap(m, n);
      k = m * n / 2 - k;
    }
    if (n % 2 == 0 && k % 2 == 0)
      cout << "YES\n";
    else {
      int r = k % m;
      if (r != 0) {
        if ((n - r) % 2 == 1)
          cout << "NO\n";
        else if ((k / m) % 2 == 1)
          cout << "NO\n";
        else
          cout << "No\n";
      } else
        cout << "YESㄅ\n";
    }
  }
}
