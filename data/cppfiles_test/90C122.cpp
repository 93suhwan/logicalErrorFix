#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int x, y, n;
    cin >> x >> y;
    if (x == y) {
      n = x;
    } else if (x > y) {
      n = x + y;
    } else {
      if (x > (y - x) / 2)
        n = x + ((y - x) / 2);
      else {
        n = y - (((y - x) % x) / 2);
      }
    }
    cout << n << "\n";
  }
  return 0;
}
