#include <bits/stdc++.h>
using namespace std;
int f(int x) {
  int ans = 1;
  while (x > 0) {
    ans *= 10;
    x--;
  }
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x1, x2, p1, p2;
    cin >> x1 >> p1;
    cin >> x2 >> p2;
    int p = abs(p1 - p2);
    if (p1 > p2) {
      p1 -= p;
      while (p > 0) {
        p--;
        x1 *= 10;
      }
    } else if (p1 < p2) {
      p2 -= p;
      while (p > 0) {
        p--;
        x2 *= 10;
      }
    }
    if (x1 == x2)
      cout << "=" << endl;
    else if (x1 < x2)
      cout << "<" << endl;
    else
      cout << ">" << endl;
  }
  return 0;
}
