#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long val, c1, c2;
    cin >> val;
    if (val % 3 == 0) {
      c1 = val / 3;
      c2 = c1;
    } else if (val % 3 == 1) {
      c2 = val / 3;
      c1 = (c2 + 1);
    } else {
      c1 = val / 3;
      c2 = (c1 + 1);
    }
    cout << c1 << " " << c2 << endl;
  }
  return 0;
}
