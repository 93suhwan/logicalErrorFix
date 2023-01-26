#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int w, h;
    cin >> w >> h;
    int area = 0;
    for (int j = 0; j < 2; j++) {
      int k;
      cin >> k;
      int mn = 1e9 + 10;
      int mx = 0;
      for (int i = 0; i < k; i++) {
        int l;
        cin >> l;
        mn = min(mn, l);
        mx = max(mx, l);
      }
      area = max((mx - mn) * h, area);
    }
    for (int j = 0; j < 2; j++) {
      int k;
      cin >> k;
      int mn = 1e9 + 10;
      int mx = 0;
      for (int i = 0; i < k; i++) {
        int l;
        cin >> l;
        mn = min(mn, l);
        mx = max(mx, l);
      }
      area = max(area, (mx - mn) * w);
    }
    cout << area << endl;
  }
  return 0;
}
