#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int a, b, c;
  while (t--) {
    cin >> a >> b >> c;
    if (c >= 1 && c <= (max(a, b) - min(a, b) + 1) && abs(a - b) != 1) {
      if (c >= (max(a, b) - min(a, b) + 1)) {
        cout << c - abs(a - b) << endl;
      } else
        cout << c + abs(a - b) << endl;
    } else
      cout << -1 << endl;
  }
  return 0;
}
