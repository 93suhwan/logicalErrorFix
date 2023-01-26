#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c, diff;
    cin >> a >> b >> c;
    diff = abs(b - a);
    if (diff == 1) {
      cout << -1 << "\n";
    } else if ((2 * diff) > c) {
      if ((c + diff) > 2 * diff) {
        cout << c - diff << "\n";
      } else {
        cout << c + diff << "\n";
      }
    } else {
      cout << -1 << "\n";
    }
  }
  return 0;
}
