#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int flag = 0;
    long l, r;
    cin >> l >> r;
    long result = 0;
    if (l - r == 0) {
      flag = 1;
      cout << 0 << endl;
    } else if ((r - l - 1) == 0) {
      flag = 1;
      cout << 1 << endl;
    } else if ((r / 2) >= l) {
      result = r - ((r / 2) + 1);
      cout << result << endl;
    } else {
      result = r % l;
      cout << result << endl;
    }
  }
}
