#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, a1 = 0, a2 = 0, a3 = 0;
    int f[105][3] = {0}, a[105];
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
      if (a3 * 3 >= a[i])
        a[i] %= 3;
      else
        a[i] -= a3 * 3;
      if (a2 * 2 >= a[i])
        a[i] %= 2;
      else
        a[i] -= a2 * 2;
      if (a1 >= a[i])
        a[i] = 0;
      else
        a[i] -= a1;
      f[i][0] = a[i] / 3;
      if (a[i] % 3 == 1) {
        if (a1)
          f[i][2] = 1;
        else
          f[i][1] = 1;
      } else if (a[i] % 3 == 2)
        f[i][2] = 1;
      a1 += f[i][1];
      a2 += f[i][2];
      a3 += f[i][0];
    }
    cout << a1 + a2 + a3 << endl;
  }
  return 0;
}
