#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long int a, b, c;
    cin >> a >> b >> c;
    double diff = abs((double)(a - b));
    double totalpeople = diff * 2;
    if (c > totalpeople || a > totalpeople || b > totalpeople) {
      cout << "-1" << endl;
      continue;
    } else {
      if (c - diff <= 0) {
        cout << c + diff << endl;
        continue;
      }
      if (c - diff > 0) {
        cout << c - diff << endl;
        continue;
      }
    }
  }
  return 0;
}
