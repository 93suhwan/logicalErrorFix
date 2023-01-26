#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int w, h;
    cin >> w >> h;
    long long int area = 0;
    int f = 0;
    for (int i = 0; i < 2; i++) {
      int k1, k2;
      cin >> k1;
      long long int mx0 = 0;
      long long int mn0 = 1000000;
      for (int j = 0; j < k1; j++) {
        int x;
        cin >> x;
        if (x > mx0) mx0 = x;
        if (x < mn0) mn0 = x;
      }
      cin >> k2;
      long long int mx1 = 0;
      long long int mn1 = 1e6;
      for (int j = 0; j < k2; j++) {
        int x;
        cin >> x;
        if (x > mx1) mx1 = x;
        if (x < mn1) mn1 = x;
      }
      if (f == 0) {
        area = max(area, max((mx1 - mn1), (mx0 - mn0)) * h);
        f = 1;
      } else {
        area = max(area, max((mx1 - mn1), (mx0 - mn0)) * w);
      }
    }
    cout << area << "\n";
  }
  return 0;
}
