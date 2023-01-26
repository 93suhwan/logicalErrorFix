#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x, y;
    cin >> x >> y;
    long long u = (x + y) / 2;
    if (x > y) {
      u = x + y;
    } else
      u = (x + y) / 2;
    cout << u << endl;
  }
}
