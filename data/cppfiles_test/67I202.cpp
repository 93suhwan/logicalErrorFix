#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b) swap(a, b);
    int dif = b - a;
    int n = dif * 2;
    if (n <= a || n < b || (n == b && a != 1)) {
      cout << "-1" << endl;
      continue;
    }
    if (c > dif) {
      if (c - dif >= 1)
        cout << c - dif << endl;
      else
        cout << "-1" << endl;
    } else {
      if (c + dif > n)
        cout << "-1" << endl;
      else
        cout << c + dif << endl;
    }
  }
  return 0;
}
