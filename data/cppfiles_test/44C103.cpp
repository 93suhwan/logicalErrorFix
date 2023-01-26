#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a, b;
    cin >> a >> b;
    if (a == b && a != 0) {
      cout << 1 << '\n';
    } else if (a == b && a == 0) {
      cout << 0 << '\n';
    } else if (((a + b) % 2) == 0) {
      cout << 2 << '\n';
    } else
      cout << -1 << '\n';
  }
}
