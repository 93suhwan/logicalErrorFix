#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << "1" << endl;
    }
    int x = (int)sqrt(n) + (int)cbrt(n);
    int p = 0;
    int q = 1;
    bool r = true;
    while (r) {
      if (pow(q, 6) < n) {
        p++;
        q++;
      } else
        r = false;
    }
    cout << x - p << endl;
  }
  return 0;
}
