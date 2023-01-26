#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b;
  cin >> a >> b;
  int pxor;
  if (a % 4 == 1) {
    pxor = a - 1;
  } else if (a % 4 == 2) {
    pxor = 1;
  } else if (a % 4 == 3) {
    pxor = a;
  } else {
    pxor = 0;
  }
  if (pxor == b) {
    cout << a << endl;
  } else if ((pxor ^ b) != a) {
    cout << a + 1 << endl;
  } else {
    cout << a + 2 << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
