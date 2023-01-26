#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int c11 = 0, c12 = 0, c21 = 0, c22 = 0, c1, c2;
    for (int k = 0; k < 1000000; k++) {
      if ((n - k) % 3 == 0 && (n + k) % 3 == 0) continue;
      if ((n - k) % 3 == 0 && (n + k) % 3 == 0) {
        c12 = (n - k) / 3;
        c11 = k + c12;
        c22 = (n + k) / 3;
        c21 = -k + c22;
        if (abs(c11 - c12) < abs(c21 - c22)) {
          c1 = c11;
          c2 = c12;
          cout << c1 << " " << c2 << endl;
          break;
        } else {
          c1 = c21;
          c2 = c22;
          cout << c1 << " " << c2 << endl;
          break;
        }
      }
      if ((n - k) % 3 == 0) {
        c12 = (n - k) / 3;
        c11 = k + c12;
        cout << c11 << " " << c12 << endl;
        break;
      }
      if ((n + k) % 3 == 0) {
        c22 = (n + k) / 3;
        c21 = -k + c22;
        cout << c21 << " " << c22 << endl;
        break;
      }
    }
  }
}
