#include <bits/stdc++.h>
using namespace std;
long long int arr[100001];
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int a, b;
    cin >> a >> b;
    if ((int)log2(b) - (int)log2(a) == 0) {
      cout << "0" << endl;
    } else {
      if ((int)log2(b) - (int)log2(a) == 1) {
        int f = log2(b);
        long long int x = pow(2, f);
        int xf = b - a + 1;
        if (xf % 2 == 1) {
          if (a % 2 == 1 or b % 2 == 1) {
            xf = xf / 2 + 1;
          } else {
            xf = xf / 2;
          }
        } else {
          xf = xf / 2;
        }
        cout << min(min((b - a + 1) - (x - a), b - a + 1 - xf),
                    (b - a + 1) - (b - x))
             << endl;
      } else if ((int)log2(b) - (int)log2(a) >= 2) {
        int x = b - pow(2, log2(b)) + 1;
        int y = pow(2, log2(b)) - pow(2, log2(b) - 1);
        int f = b - a + 1;
        if (f % 2 == 1) {
          if (a % 2 == 1 or b % 2 == 1) {
            f = f / 2 + 1;
          } else {
            f = f / 2;
          }
        } else {
          f = f / 2;
        }
        cout << min(b - a + 1 - x, min(b - a + 1 - y, b - a + 1 - f)) << endl;
      }
    }
  }
  return 0;
}
