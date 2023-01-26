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
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else {
      if (n == 1) {
        if (n * m == 2 * k)
          cout << "YES" << endl;
        else
          cout << "NO" << endl;
      } else {
        if (m == 2) {
          if (k % 2 == 1)
            cout << "YES" << endl;
          else
            cout << "NO" << endl;
        } else {
          if (k % 2 == 0)
            cout << "YES" << endl;
          else
            cout << "NO" << endl;
        }
      }
    }
  }
  return 0;
}
