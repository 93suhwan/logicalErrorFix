#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int w, h;
    cin >> w >> h;
    int n, mi = INT_MAX, ma = INT_MIN, sol = 0, sol2 = 0;
    for (int j = 0; j < 4; j++) {
      cin >> n;
      for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        mi = min(mi, a);
        ma = max(ma, a);
      }
      if (j == 0) sol = ma - mi;
      if (j == 2) sol2 = ma - mi;
      mi = INT_MAX;
      ma = INT_MIN;
    }
    sol = max(sol, 0);
    sol2 = max(sol2, 0);
    cout << max((sol * h), (sol2 * w)) << endl;
  }
  return 0;
}
