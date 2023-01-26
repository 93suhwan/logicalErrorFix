#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t, c1, c2;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    c1 = 0;
    c2 = 0;
    if (n % 3 == 0) {
      c1 = c2 = n / 3;
    } else if ((n - 1) % 3 == 0) {
      c2 = (n - 1) / 3;
      c1 = c2 + 1;
    } else if ((n - 2) % 3 == 0) {
      c1 = (n - 2) / 3;
      c2 = c1 + 1;
    }
    cout << c1 << " " << c2 << endl;
  }
}
