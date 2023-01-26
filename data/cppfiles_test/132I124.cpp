#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int b[7];
    for (int i = 0; i < 7; ++i) {
      cin >> b[i];
    }
    int x, y, z;
    x = b[0];
    y = b[1];
    for (int i = 2; i < 7; i++) {
      if (b[i] == x + y) {
        z = b[i];
        break;
      }
    }
    cout << x << " " << y << " " << z << "\n";
  }
}
