#include <bits/stdc++.h>
using namespace std;
int t, a, b, c;
int main() {
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    int res = 0;
    if (c & 1) res = 3;
    if (res) {
      if (b & 1) res = 1;
      if (a & 1)
        res = 0;
      else
        res = 1;
    } else {
      if (b & 1) res = 2;
      if (a & 1)
        res = 1;
      else
        res = 0;
    }
    cout << res << endl;
  }
  return 0;
}
