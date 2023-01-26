#include <bits/stdc++.h>
using namespace std;
long long t, x1, p1, x2, p2;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> x1 >> p1 >> x2 >> p2;
    while (x1 <= x2 && p1 > p2) {
      x1 *= 10;
      p1--;
    }
    while (x2 <= x1 && p1 < p2) {
      x2 *= 10;
      p2--;
    }
    cout << (x1 > x2 ? '>' : (x1 == x2 ? '=' : '<')) << endl;
  }
  return 0;
}
