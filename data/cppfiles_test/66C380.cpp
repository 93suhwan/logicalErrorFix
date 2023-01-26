#include <bits/stdc++.h>
using namespace std;
int main() {
  int te;
  cin >> te;
  while (te--) {
    int n;
    cin >> n;
    int ki = 1;
    int j = 1;
    while (j <= n) {
      if (ki % 3 != 0 && ki % 10 != 3) {
        j++;
      }
      ki++;
    }
    cout << ki - 1 << endl;
  }
  return 0;
}
