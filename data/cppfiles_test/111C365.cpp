#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  short m, l, r;
  cin >> m;
  while (m--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      l = n;
      r = l;
      while (l > 0) {
        for (int j = 1; j <= i; ++j) {
          if (l <= 0) break;
          cout << "(";
          l--;
        }
        cout << ")";
        r--;
      }
      for (int z = 0; z < r; ++z) cout << ")";
      cout << endl;
    }
  }
  return 0;
}
