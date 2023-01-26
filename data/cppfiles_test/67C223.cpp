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
    if (n <= a || n < b || c > n) {
      cout << "-1" << endl;
      continue;
    }
    if (c <= dif) {
      int l = c + dif;
      if (l > n)
        cout << "-1" << endl;
      else
        cout << l << endl;
    } else {
      int l = c - dif;
      if (l < 1)
        cout << "-1" << endl;
      else
        cout << l << endl;
    }
  }
  return 0;
}
