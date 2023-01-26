#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, c;
    cin >> a >> b >> c;
    int m = a + b * 2 + c * 3;
    if (m % 2 == 1) {
      cout << 1 << "\n";
    } else
      cout << 0 << "\n";
  }
  return 0;
}
