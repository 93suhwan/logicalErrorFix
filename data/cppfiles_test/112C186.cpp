#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    if (a < b) {
      swap(a, b);
    }
    if (a < c) {
      swap(a, c);
    }
    if (b < c) {
      swap(b, c);
    }
    int maxp = a + b + c - 3;
    int minp = a - b - c - 1;
    if (m <= maxp && m >= minp) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
