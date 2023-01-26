#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int c1, c2;
    for (int k = 0; k < 1000000; k++) {
      if ((n - k) % 3 == 0)
        c2 = (n - k) / 3;
      else
        continue;
      c1 = k + c2;
      cout << c1 << " " << c2 << endl;
      break;
    }
  }
}
