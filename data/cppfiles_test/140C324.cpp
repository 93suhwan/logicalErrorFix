#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int k1 = (int)sqrt(n) + (int)cbrt(n);
    int k2 = k1 - (int)sqrt(cbrt(n));
    cout << k2 << endl;
  }
  return 0;
}
