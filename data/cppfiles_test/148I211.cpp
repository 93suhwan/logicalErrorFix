#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int w, h;
    cin >> w >> h;
    int max1 = 0;
    for (int i = 0; i < 4; i++) {
      int k;
      cin >> k;
      vector<int> a(k);
      for (auto &x : a) {
        cin >> x;
      }
      if (i == 0 || i == 1) {
        if ((a[k - 1] - a[0]) * h > max1) {
          max1 = (a[k - 1] - a[0]) * h;
        }
      } else if (i == 2 || i == 3) {
        if ((a[k - 1] - a[0]) * w > max1) {
          max1 = (a[k - 1] - a[0]) * w;
        }
      }
    }
    cout << max1 << '\n';
  }
  return 0;
}
