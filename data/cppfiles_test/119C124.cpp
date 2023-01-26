#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, tt, n, m, i, sum, res;
  cin >> tt;
  for (t = 1; t <= tt; t++) {
    cin >> n;
    sum = 0;
    for (i = 1; i <= n; i++) {
      cin >> m;
      sum += m;
    }
    if (sum % n == 0) {
      res = 0;
    } else {
      res = 1;
    }
    cout << res << endl;
  }
}
