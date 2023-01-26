#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int d = max(a, b) - min(a, b);
    int x = 2 * d;
    if (x < a || x < b || x < c)
      cout << -1 << "\n";
    else {
      if (d >= c) {
        cout << (c + d) << "\n";
      } else {
        cout << (c - d) << "\n";
      }
    }
  }
  return 0;
}
