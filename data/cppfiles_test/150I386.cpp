#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, x, a1 = 0, a2 = 0, a3 = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> x;
      if (x % 3 == 1)
        a1 = 1;
      else
        a2 = 1;
      if (a1 && a2)
        a3 = (a3, x / 3 - 1);
      else
        a3 = max(a3, x / 3);
    }
    cout << a1 + a2 + a3 << endl;
  }
  return 0;
}
