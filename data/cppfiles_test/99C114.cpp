#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x, n, r;
    cin >> x >> n;
    r = n % 4;
    for (long long i = n - r + 1; i <= n; i++) {
      if (abs(x) % 2 == 1) {
        x += i;
      } else {
        x += (-1 * i);
      }
    }
    cout << x << endl;
  }
  return 0;
}
