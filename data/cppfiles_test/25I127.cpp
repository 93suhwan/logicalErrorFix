#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string x, y;
    cin >> x >> y;
    if (x == y) {
      cout << "YES\n";
      continue;
    }
    bool ok = false;
    for (int j = 0; j < x.size(); j++) {
      if (x[j] == y[0]) {
        int m = 1, z = j + 1, i = 1;
        for (int k = j - 1; i < y.size() && j >= 0; i++, k--) {
          if (y[i] != x[k]) {
            break;
          }
        }
        if (i == y.size()) {
          ok = true;
          break;
        }
        for (; m < y.size() && z < x.size(); m++, z++) {
          if (y[m] != x[z]) {
            break;
          }
        }
        if (m == y.size()) {
          ok = true;
          break;
        }
        z -= 2;
        for (; m < y.size() && z >= 0; m++, z--) {
          if (y[m] != x[z]) {
            break;
          }
        }
        if (m == y.size()) {
          ok = true;
          break;
        }
      }
    }
    if (ok)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
