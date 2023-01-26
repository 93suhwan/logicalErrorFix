#include <bits/stdc++.h>
using namespace std;
int t, n, a[109];
int up(int x) { return (x + 2) / 3; }
int cal(int i, int j) {
  int num = 0;
  for (int k = 1; k <= n; k++) {
    num = max(up(a[k] - i - 2 * j), num);
  }
  return num + i + j;
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int a1 = 0, a2 = 0, a3 = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] == 1)
        a1 = 1;
      else if (a[i] % 3 == 1)
        a3 = 1;
      else if (a[i] % 3 == 2)
        a2 = 1;
    }
    int minn = 1e9;
    if (a1 == 1) {
      minn = min(minn, cal(1, a2));
    } else {
      if (a3 == 1)
        minn = min(minn, cal(0, 2));
      else
        minn = min(minn, cal(0, 1));
    }
    cout << minn << endl;
  }
  return 0;
}
