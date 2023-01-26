#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int n = abs(b - a) * 2;
    if (a > n || b > n || c > n) {
      cout << "-1\n";
      continue;
    }
    int ans = (c + (n / 2)) % n;
    if (ans == 0) ans = n;
    cout << ans << "\n";
  }
  return 0;
}
