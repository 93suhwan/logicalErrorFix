#include <bits/stdc++.h>
using namespace std;
int main() {
  int m;
  cin >> m;
  while (m--) {
    int n;
    cin >> n;
    if (n % 2 == 0) {
      cout << n / 2 << " " << n / 2 - 1 << " " << 1 << endl;
    } else {
      int k = n + 1;
      k = k / 2;
      if (k % 2 == 0) {
        cout << k + 1 << " " << k - 3 << " " << 1 << endl;
      } else {
        cout << k << " " << k - 2 << " " << 1 << endl;
      }
    }
  }
  return 0;
}
