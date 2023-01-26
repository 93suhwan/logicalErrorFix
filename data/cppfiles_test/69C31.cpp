#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long int n;
    scanf("%lld", &n);
    int nx[20];
    for (int i = 0; i < 20; i++) {
      nx[i] = 0;
    }
    int pn = 19;
    long long int dn = n;
    while (dn > 0) {
      nx[pn] = dn % 10;
      dn = dn / 10;
      pn -= 1;
    }
    pn += 1;
    long long int x[63];
    x[0] = 1;
    for (int i = 1; i < 63; i++) x[i] = x[i - 1] * 2;
    int ans = 1000000007;
    for (int i = 0; i < 63; i++) {
      int xx[20];
      for (int k = 0; k < 20; k++) {
        xx[k] = 0;
      }
      int px = 19;
      long long int dx = x[i];
      while (dx > 0) {
        xx[px] = dx % 10;
        dx = dx / 10;
        px -= 1;
      }
      px += 1;
      int cx = 0;
      int pnn = pn;
      for (int k = px; k < 20; k++) {
        int f = 0;
        for (int j = pnn; j < 20; j++) {
          if (xx[k] == nx[j]) {
            pnn = j + 1;
            f = 1;
            break;
          } else {
            cx += 1;
          }
        }
        if (pnn == 20) {
          if (f)
            cx += (20 - k - 1);
          else
            cx += (20 - k);
          break;
        }
        if (f == 0) {
          cx += (20 - k);
          pnn = 20;
          break;
        }
      }
      cx += (20 - pnn);
      if (cx < ans) ans = cx;
    }
    printf("%d", ans);
    printf("\n");
  }
  return 0;
}
