#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  int l1, l2, l3;
  cin >> t;
  while (t--) {
    cin >> l1 >> l2 >> l3;
    if ((l1 + l2 + l3) % 2 == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
