#include <bits/stdc++.h>
using namespace std;
template <class T>
T sqr(T a) {
  return a * a;
}
template <class T>
T abs(T x) {
  if (x < 0) return -x;
  return x;
}
const double eps = 1e-8;
const double pi = acos(-1.0);
char str[1000010];
int main() {
  int tks, ks = 1;
  scanf("%d", &tks);
  while (tks--) {
    int x, y, mxx, mxy, mnx, mny, n, i, r, c;
    int lmxx = 0, lmxy = 0, lmnx = 0, lmny = 0;
    x = y = mxx = mxy = mnx = mny = 0;
    scanf("%d%d", &r, &c);
    scanf("%s", str);
    n = strlen(str);
    for (i = 0; i < n; i++) {
      if (str[i] == 'L') x--;
      if (str[i] == 'R') x++;
      if (str[i] == 'U') y--;
      if (str[i] == 'D') y++;
      mxx = max(mxx, x);
      mxy = max(mxy, y);
      mnx = min(mnx, x);
      mny = min(mny, y);
      if (mxx - mnx + 1 > c) break;
      if (mxy - mny + 1 > r) break;
      lmxx = mxx;
      lmxy = mxy;
      lmnx = mnx;
      lmny = mny;
    }
    x = 1 + abs(lmnx);
    y = 1 + abs(lmny);
    printf("%d %d\n", y, x);
  }
  return 0;
}
