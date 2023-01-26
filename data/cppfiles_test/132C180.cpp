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
    for (int i = 1; i < 6; ++i) {
      for (int j = i + 1; j < 7; ++j) {
        if (b[i] + b[j] + x == b[6]) {
          y = b[i];
          z = b[j];
        }
      }
    }
    cout << x << " " << y << " " << z << "\n";
  }
}
