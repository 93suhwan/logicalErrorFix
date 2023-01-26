#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, e, q1, q2, q3;
  string x, y;
  vector<int> v;
  cin >> a;
  while (a--) {
    cin >> b >> c >> d;
    int mid = max(b, c) - (min(b, c) - 1);
    if ((b < mid && c < mid) || (b > mid && c > mid)) {
      cout << -1 << endl;
    } else if (((mid - 1) * 2) < d) {
      cout << -1 << endl;
    } else if ((mid == b && c != 1) || (mid == c && b != 1)) {
      cout << -1 << endl;
    } else {
      if (mid == d) {
        cout << 1 << endl;
      } else {
        if (d < mid) {
          int point = (d - 1) + mid;
          cout << point << endl;
        } else {
          cout << (d - mid) + 1 << endl;
        }
      }
    }
  }
  return 0;
}
