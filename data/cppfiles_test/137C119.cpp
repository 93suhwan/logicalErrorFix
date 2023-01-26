#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
long long x, y;
int xb[N], yb[N], lenx, leny;
void cmp() {
  for (int i = 1; i <= leny - lenx + 1; i++) {
    bool vis = 1;
    for (int j = 1; j <= lenx; j++) {
      if (xb[j] != yb[i + j - 1]) {
        vis = 0;
      }
    }
    for (int j = 1; j < i; j++) {
      if (yb[j] == 0) {
        vis = 0;
      }
    }
    for (int j = i + lenx; j <= leny; j++) {
      if (yb[j] == 0) {
        vis = 0;
      }
    }
    if (xb[1] == 0 && i - 1 == 0 && leny - (i + lenx - 1) > 0) {
      vis = 0;
    }
    if (vis) {
      printf("YES");
      exit(0);
    }
  }
}
int main() {
  scanf("%lld%lld", &x, &y);
  while (x) {
    xb[++lenx] = x % 2;
    x /= 2;
  }
  while (y) {
    yb[++leny] = y % 2;
    y /= 2;
  }
  cmp();
  reverse(yb + 1, yb + leny + 1);
  cmp();
  reverse(xb + 1, xb + lenx + 1);
  while (!xb[lenx]) {
    lenx--;
  }
  cmp();
  reverse(yb + 1, yb + leny + 1);
  cmp();
  printf("NO");
  return 0;
}
