#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int l1, l2, l3;
    cin >> l1 >> l2 >> l3;
    if (l1 == l2 && l3 % 2 == 0 || l2 == l3 && l1 % 2 == 0 ||
        l1 == l3 && l2 % 2 == 0) {
      cout << "yes"
           << "\n";
    } else if (l1 + l2 == l3 || l2 + l3 == l1 || l1 + l3 == l2) {
      cout << "yes"
           << "\n";
    } else {
      cout << "no"
           << "\n";
    }
  }
  return 0;
}
