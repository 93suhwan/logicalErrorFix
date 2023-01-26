#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t, n, a, b;
  cin >> t;
  while (t--) {
    cin >> n;
    int x = 0;
    a = 0;
    b = 0;
    while (n) {
      if (x & 1) {
        a += (n % 10) * pow(10, x / 2);
      } else {
        b += (n % 10) * pow(10, x / 2);
      }
      x++;
      n /= 10;
    }
    cout << (a + 1) * (b + 1) - 2 << '\n';
  }
  return 0;
}
