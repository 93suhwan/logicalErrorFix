#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int c2 = n / 3;
    int c1 = n / 3;
    while (c1 + 2 * c2 < n) {
      if (n - c1 - c2 > 1) {
        c2++;
      } else {
        c1++;
      }
    }
    cout << c1 << " " << c2 << endl;
  }
}
