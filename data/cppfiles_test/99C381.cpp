#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  long long int x, n;
  long long int k;
  short int w;
  for (int i = 0; i < t; i++) {
    cin >> x >> n;
    k = (n - n % 4);
    w = n % 4;
    if (x % 2 == 0) {
      if (w == 0) {
        cout << x << endl;
      } else if (w == 1) {
        cout << (x - (k + 1)) << endl;
      } else if (w == 2) {
        cout << (x + 1) << endl;
      } else {
        cout << ((x + 1) + (k + 3)) << endl;
      }
    } else {
      if (w == 0) {
        cout << x << endl;
      } else if (w == 1) {
        cout << (x + (k + 1)) << endl;
      } else if (w == 2) {
        cout << (x - 1) << endl;
      } else {
        cout << ((x - 1) - (k + 3)) << endl;
      }
    }
  }
}
