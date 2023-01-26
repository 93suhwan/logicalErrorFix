#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n < 9) {
      cout << "0" << endl;
    }
    if (n == 9) {
      cout << "1" << endl;
    }
    if (n > 9) {
      cout << n / 10 << endl;
      ;
    }
  }
  return 0;
}
