#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long x1, p1;
    cin >> x1 >> p1;
    long long x2, p2;
    cin >> x2 >> p2;
    long long mini = min(p2, p1);
    p2 -= mini;
    p1 -= mini;
    if (p1 >= 7) {
      cout << ">\n";
    } else if (p2 >= 7) {
      cout << "<\n";
    } else {
      for (int i = 0; i < p1; i++) {
        x1 *= 10;
      }
      for (int i = 0; i < p2; i++) {
        x2 *= 10;
      }
      if (x1 > x2) {
        cout << ">\n";
      } else if (x1 < x2) {
        cout << "<\n";
      } else {
        cout << "=\n";
      }
    }
  }
  return 0;
}
