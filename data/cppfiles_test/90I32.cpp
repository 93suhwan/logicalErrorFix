#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int testcases;
  cin >> testcases;
  while (testcases--) {
    unsigned long long x, y;
    cin >> x >> y;
    if (x <= y) {
      cout << x + (y - x) / 2 << "\n";
    } else {
      cout << x + y << "\n";
    }
  }
  return 0;
}
