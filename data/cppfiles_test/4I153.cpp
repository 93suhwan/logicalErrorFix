#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int p;
    cin >> p;
    p = p - 1;
    if (p / 2 != 2) {
      cout << "2"
           << " " << p / 2 << endl;
    } else
      cout << "2"
           << "4" << endl;
  }
  return 0;
}
