#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
void solve() {
  int n;
  cin >> n;
  int y = n / 3;
  int a = y, b = 2 * y;
  y = y * 3;
  if (y == 0 && n == 2) {
    b += 2;
  } else if (y == 0 && n == 1) {
    a++;
  }
  if (y > 0 && n % y == 2) {
    b += 2;
  } else if (y > 0 && n % y == 1) {
    a++;
  }
  cout << a << " " << b / 2 << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
