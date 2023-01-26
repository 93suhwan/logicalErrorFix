#include <bits/stdc++.h>
using namespace std;
int main() {
  int T, i, j, k = 0;
  cin >> T;
  while (T-- > 0) {
    int n;
    cin >> n;
    int a[n + 1], d = 1, die = 0;
    for (i = 1; i < n + 1; i++) cin >> a[i];
    a[0] = 0;
    for (i = 1; i < n + 1; i++) {
      if (a[i] == 1) {
        d++;
        if (a[i - 1] == 1) d += 4;
      } else {
        if (a[i - 1] == 0 && i > 1) {
          die++;
          break;
        }
      }
    }
    if (die != 0)
      cout << -1 << endl;
    else
      cout << d << endl;
  }
}
