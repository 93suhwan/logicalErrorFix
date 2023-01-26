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
      if (j < 2) {
        sol = max(sol, (ma - mi) * h);
      } else {
        sol2 = max(sol2, (ma - mi) * w);
      }
      mi = INT_MAX;
      ma = INT_MIN;
    }
    cout << max(sol, sol2) << endl;
  }
  return 0;
}
