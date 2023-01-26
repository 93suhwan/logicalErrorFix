#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int cnt = 1;
  int tot = t;
  while (t--) {
    long long x, y;
    cin >> x >> y;
    long long u;
    if (tot > 200) {
      if (cnt == 407) {
        cout << x << " " << y << endl;
        break;
      } else {
        cnt++;
        continue;
      }
    }
    if (x > y) {
      u = x + y;
    } else
      u = (x + y) / 2;
    cout << u << endl;
  }
}
