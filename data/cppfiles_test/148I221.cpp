#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int w, h, max_area = 0;
    cin >> w >> h;
    for (int i = 0; i < 4; i++) {
      int n;
      cin >> n;
      int a[n];
      for (auto &x : a) cin >> x;
      int area1 = a[n - 1] - a[0];
      if (i == 0 || i == 1)
        area1 = area1 * h;
      else
        area1 = area1 * w;
      max_area = max(max_area, area1);
    }
    cout << max_area << endl;
  }
  return 0;
}
