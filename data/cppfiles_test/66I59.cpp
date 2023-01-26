#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    int n = ((abs(a - b)));
    int ans;
    int f = 2 * n;
    if (c > n) {
      ans = c - n;
    } else {
      ans = c + n;
    }
    if (ans != a && ans != b && ans != c && f >= a && f >= b && f >= c) {
      cout << ans << endl;
    } else
      cout << "-1" << endl;
  }
}
