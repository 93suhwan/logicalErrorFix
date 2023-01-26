#include <bits/stdc++.h>
using namespace std;
int main() {
  int test, n, i, j, a, b;
  cin >> test;
  for (i = 0; i < test; i++) {
    cin >> n;
    for (a = 2; a < n; a++) {
      for (b = n - 1; b > a; b--) {
        if (n % a == n % b) {
          break;
        }
      }
      if (n % a == n % b) {
        cout << a << " " << b << endl;
        break;
      }
    }
  }
  return 0;
}
