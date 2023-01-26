#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long k;
    long long r, c;
    cin >> k;
    if (k == 1)
      cout << 1 << " " << 1;
    else if (k == 2)
      cout << 1 << " " << 2;
    else if (k == 3)
      cout << 2 << " " << 2;
    else if (k == 4)
      cout << 2 << " " << 1;
    else {
      long long sr = sqrt(k);
      long long gsp = (sr + 1) * (sr + 1);
      long long d = gsp - k;
      long long row = sqrt(gsp);
      if (d < row) {
        r = row;
        c = d + 1;
      } else {
        c = row;
        r = row - (d - (row - 1));
      }
      cout << r << " " << c;
    }
    cout << endl;
  }
  return 0;
}
