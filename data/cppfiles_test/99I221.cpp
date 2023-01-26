#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, d;
    cin >> x >> d;
    if (x % 2 == 0) {
      x += 1;
      int circle = d - 1;
      x += circle / 4 * 4;
      switch (circle % 4) {
        case 1:
          x -= d;
          break;
        case 2:
          x -= 2 * d - 1;
          break;
        case 3:
          x -= d - 3;
          break;
        default:
          break;
      }
    } else {
      x -= 1;
      int circle = d - 1;
      x -= circle / 4 * 4;
      switch (circle % 4) {
        case 1:
          x += d;
          break;
        case 2:
          x += 2 * d - 1;
          break;
        case 3:
          x += d - 3;
          break;
        default:
          break;
      }
    }
    cout << x << endl;
  }
  return 0;
}
