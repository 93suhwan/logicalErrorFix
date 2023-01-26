#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int n_c1, n_c2;
    if (n == 1) {
      cout << "1 0" << endl;
    } else if (n == 2) {
      cout << "0 1" << endl;
    } else if (n == 3) {
      cout << "1 1" << endl;
    } else {
      if (n % 3 == 0) {
        n_c1 = n / 3;
        cout << n_c1 << " " << n_c1 << " " << endl;
      } else {
        n_c1 = n / 3;
        n_c2 = n_c1 + 1;
        if (n_c1 + 2 * n_c2 == n) {
          cout << n_c1 << " " << n_c2 << " " << endl;
        } else if (n_c1 * 2 + n_c2 == n) {
          cout << n_c2 << " " << n_c1 << " " << endl;
        }
      }
    }
  }
  return 0;
}
