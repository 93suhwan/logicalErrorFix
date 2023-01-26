#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long x, n;
  cin >> x >> n;
  long long temp = n % 4;
  if (x % 2 == 0) {
    switch (temp) {
      case 0:
        x = x + 4 * (n / 4) - n;
        break;
      case 1:
        x = x + 4 * (n / 4) - (n - 1) - n;
        break;
      case 2:
        x = x + 4 * (n / 4) - (n - 2) - (n - 1) + n;
        break;
      case 3:
        x = x + 4 * (n / 4) - (n - 3) - (n - 2) + n - 1 + n;
        break;
      default:
        break;
    }
  } else {
    switch (temp) {
      case 0:
        x = x - 4 * (n / 4) + n;
        break;
      case 1:
        x = x - 4 * (n / 4) + (n - 1) + n;
        break;
      case 2:
        x = x - 4 * (n / 4) + (n - 2) + (n - 1) - n;
        break;
      case 3:
        x = x - 4 * (n / 4) + (n - 3) + (n - 2) - (n - 1) - n;
        break;
      default:
        break;
    }
  }
  cout << x << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t != 0) {
    solve();
    t--;
  }
}
