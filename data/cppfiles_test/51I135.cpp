#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int i = 0;
    int o = 2;
    int A;
    while (i >= 0) {
      if (n % 2 == 1) {
        A = n;
        i = -1;
        break;
      } else {
        n = n / 2;
        o = o * 2;
      }
    }
    if ((((A - o) / 2) + 1) < (A + o) / 2)
      cout << "" << (((A - o) / 2) + 1) << " " << ((A + o) / 2) << endl;
    else
      cout << "" << (((A - o) / 2)) << " " << ((A + o) / 2) << endl;
  }
  return 0;
}
