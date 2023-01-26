#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    if (n % 2 == 0) {
      if (k % 2 == 0)
        cout << "YES\n";
      else
        cout << "NO\n";
    } else {
      if (k < m / 2)
        cout << "NO\n";
      else {
        if ((k - m / 2) % 2 == 0)
          cout << "YES\n";
        else
          cout << "NO\n";
      }
    }
  }
}
