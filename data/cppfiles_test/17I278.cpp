#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d, e, f, g, i, j, l, r, k;
  cin >> a;
  while (a--) {
    cin >> b;
    long long arr[b + 1][6];
    for (i = 1; i <= b; i++) {
      for (j = 1; j <= 5; j++) {
        cin >> arr[i][j];
      }
    }
    bool chk = false;
    long long x;
    for (i = 1; i <= b; i++) {
      chk = true;
      x = i;
      for (j = 1; j <= b; j++) {
        if (i == j) continue;
        long long cnt = 0;
        for (k = 1; k <= 5; k++) {
          if (arr[i][k] < arr[j][k]) {
            cnt++;
          }
        }
        if (cnt >= 3) {
          chk = false;
          break;
        }
      }
      if (chk) break;
    }
    if (chk) cout << x << endl;
    if (!chk) cout << -1 << endl;
  }
}
