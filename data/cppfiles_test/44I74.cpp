#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int c, d;
    if ((c - d) % 2 == 0) {
      cout << "2" << endl;
    } else if (c == d) {
      cout << "1" << endl;
    } else {
      cout << "-1" << endl;
    }
  }
  return 0;
}
