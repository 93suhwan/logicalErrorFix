#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int c1 = 0, c2 = 0;
    int c = 0;
    if (n % 3 == 0) {
      c1 = n / 3;
      c2 = n / 3;
    } else {
      c = n / 3;
      if ((n % 2 == 0 && c % 2 == 0) || (n % 2 != 0 && c % 2 != 0)) {
        c2 = c + 1;
        c1 = c;
      } else {
        c1 = c + 1;
        c2 = c;
      }
    }
    cout << c1 << " " << c2;
    cout << endl;
  }
  return 0;
}
