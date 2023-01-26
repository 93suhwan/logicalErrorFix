#include <bits/stdc++.h>
using namespace std;
const int N = 123456;
int n;
int a[N];
int t;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;
    if (x == y)
      cout << x << '\n';
    else if (x > y) {
      cout << x + y << '\n';
    } else {
      if (y % x == 0)
        cout << y << '\n';
      else {
        long long l, r;
        long long now = (x + y) >> 1;
        for (now = (x + y) >> 1; now % x != y % now; now += (r - l) >> 1)
          l = now % x, r = y % now;
        cout << now << '\n';
      }
    }
  }
  return 0;
}
