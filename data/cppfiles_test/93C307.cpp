#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, xsm = 0;
    cin >> a >> b;
    vector<int> v;
    int k = a - 1;
    if (k % 4 == 1)
      xsm = 1;
    else if (k % 4 == 2)
      xsm = k + 1;
    else if (k % 4 == 3)
      xsm = 0;
    else if (k % 4 == 0)
      xsm = k;
    int c = xsm ^ b;
    if (xsm == b)
      cout << a;
    else if (c == a)
      cout << a + 2;
    else
      cout << a + 1;
    cout << "\n";
  }
  return 0;
}
