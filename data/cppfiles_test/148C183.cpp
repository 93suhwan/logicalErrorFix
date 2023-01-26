#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long w, h;
    cin >> w >> h;
    long long area = 0;
    for (int j = 0; j < 2; j++) {
      long long k;
      cin >> k;
      long long mn = 1e18 + 10;
      long long mx = 0;
      for (int i = 0; i < k; i++) {
        long long l;
        cin >> l;
        mn = min(mn, l);
        mx = max(mx, l);
      }
      area = max((mx - mn) * h, area);
    }
    for (int j = 0; j < 2; j++) {
      long long k;
      cin >> k;
      long long mn = 1e18 + 10;
      long long mx = 0;
      for (int i = 0; i < k; i++) {
        long long l;
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
