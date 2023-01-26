#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long l1, l2, l3;
    cin >> l1 >> l2 >> l3;
    bool flag = false;
    if (l1 + l2 == l3 || l2 + l3 == l1 || l3 + l1 == l2) {
      flag = true;
    }
    if (l1 == l2 && l3 % 2 == 0) {
      flag = true;
    }
    if (l3 == l2 && l1 % 2 == 0) {
      flag = true;
    }
    if (l1 == l3 && l2 % 2 == 0) {
      flag = true;
    }
    if (flag) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
