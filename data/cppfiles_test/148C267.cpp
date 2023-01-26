#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long w, h;
    cin >> w >> h;
    long long best = 0;
    for (int i = 0; i < 4; i++) {
      int k;
      cin >> k;
      long long m1 = 0, m2 = 0;
      for (int j = 0; j < k; j++) {
        long long y;
        cin >> y;
        if (j == 0) {
          m1 = y;
        }
        if (j == k - 1) {
          m2 = y;
        }
      }
      if ((i == 0) || (i == 1)) {
        long long ans = (m2 - m1) * h;
        if (ans > best) {
          best = ans;
        }
      } else {
        long long ans = (m2 - m1) * w;
        if (ans > best) {
          best = ans;
        }
      }
    }
    cout << best << endl;
  }
  return 0;
}
