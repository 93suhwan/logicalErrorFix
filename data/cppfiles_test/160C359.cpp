#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  while (k--) {
    int a, b;
    int r1, c1, r2, c2;
    cin >> a >> b >> r1 >> c1 >> r2 >> c2;
    int t = 0;
    int fr = 1;
    int fc = 1;
    while (1) {
      if (r1 == r2 or c1 == c2) break;
      if (fc + c1 > b) {
        fc = fc * -1;
      }
      if (fc + c1 < 1) {
        fc = fc * -1;
      }
      if (fr + r1 > a) {
        fr = fr * -1;
      }
      if (fr + r1 < 1) {
        fr = fr * -1;
      }
      r1 += fr;
      c1 += fc;
      t++;
    }
    cout << t << "\n";
  }
}
