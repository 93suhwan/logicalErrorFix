#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int c1 = 0;
    int c2 = 0;
    while (c1 + c2 < n) {
      int df = n - c1 - c2;
      if (df == 1) {
        c1++;
      } else if (df == 2) {
        c2 += 2;
      } else {
        c1 += df / 3;
        c2 += df / 3 * 2;
      }
    }
    cout << c1 << " " << c2 / 2 << endl;
  }
}
