#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int total = abs(a - b) * 2;
    if (total < max(a, b) || c > total) {
      cout << -1 << endl;
    } else {
      if (c > total / 2) {
        cout << c - (total / 2) << endl;
      } else {
        cout << c + (total / 2) << endl;
      }
    }
  }
  return 0;
}
