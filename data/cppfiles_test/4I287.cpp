#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int p;
    cin >> p;
    p = p - 1;
    for (int i = 3; i < p; i++) {
      if (p % i == 0) {
        cout << "2" << i << endl;
        break;
      }
    }
  }
  return 0;
}
