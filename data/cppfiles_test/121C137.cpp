#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
string a, b;
int n;
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> a >> b;
    int c[2][2] = {0};
    for (int i = 0; i < n; i++) {
      for (int b1 = 0; b1 < 2; b1++)
        for (int b2 = 0; b2 < 2; b2++)
          c[b1][b2] += (a[i] - '0' == b1) && (b[i] - '0' == b2);
    }
    int a0 = c[0][0] + c[0][1], a1 = n - a0;
    int ans = inf;
    if (c[1][1] - 1 >= c[0][0]) {
      int dif = c[1][1] - 1 - c[0][0];
      if (!dif) ans = min(ans, c[1][1] * 2 - 1);
    } else {
      int dif = c[0][0] - c[1][1] + 1;
      if (!dif) ans = min(ans, c[0][0] * 2 + 1);
    }
    if (c[1][0] >= c[0][1]) {
      int dif = c[1][0] - c[0][1];
      if (!dif) ans = min(ans, c[1][0] * 2);
    } else {
      int dif = c[0][1] - c[1][0];
      if (!dif) ans = min(ans, c[0][1] * 2);
    }
    if (ans < inf)
      cout << ans << endl;
    else
      cout << -1 << endl;
  }
}
