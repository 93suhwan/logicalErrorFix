#include <bits/stdc++.h>
using namespace std;
int main() {
  int pp;
  cin >> pp;
  for (int jiaran = 1; jiaran <= pp; jiaran++) {
    int left, right, t = 1;
    cin >> left >> right;
    int p1 = 1, p2 = 2, temp = 0, p;
    int l, r, k1, k2, k;
    while (p2 <= right * 2) {
      p = 0;
      l = left / p1 + (left % p1 > 0);
      r = right / p1;
      if (r >= l) {
        p = (r - l);
        p /= 2;
        if (l % 2 > 0 && r % 2 == 0) p++;
        p *= p1;
        if (l % 2 == 0) p += l * p1 - left;
        if (r % 2 != 0) p += right - r * p1 + 1;
      } else {
        if (r % 2 > 0) p = right - left + 1;
      }
      if (p > temp) {
        temp = p;
      }
      p1 *= 2;
      p2 *= 2;
    }
    cout << right - left + 1 - temp << endl << endl;
  }
  return 0;
}
