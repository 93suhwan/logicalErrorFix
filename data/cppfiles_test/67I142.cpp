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
    int half = b - a;
    if (half <= a) {
      cout << "-1" << endl;
      continue;
    }
    if (c > half) {
      if (c > half * 2)
        cout << "-1" << endl;
      else
        cout << c - half << endl;
    } else {
      if (half + c > half * 2)
        cout << "-1" << endl;
      else
        cout << half + c << endl;
    }
  }
  return 0;
}
