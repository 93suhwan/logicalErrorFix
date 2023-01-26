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
    int m = a % 2, n = c % 2;
    if (m == n)
      cout << 0 << "\n";
    else
      cout << 1 << "\n";
  }
  return 0;
}
