#include <bits/stdc++.h>
using namespace std;
const int X = 100, Y = 100, P = 200, Q = 200;
int l, r, L, R;
int A, B, C, D;
int p, q, x, y;
int query(int x, int y) {
  printf("? %d %d\n", x, y);
  fflush(stdout);
  int res;
  scanf("%d", &res);
  return res;
}
int main() {
  l = 1;
  r = 1000000000;
  L = 1;
  R = 1000000000;
  A = query(1, 1);
  B = query(1, 1000000000);
  C = query(1000000000, 1);
  l = 1;
  r = 1000000000;
  L = A;
  R = B;
  while (l < r && L != R) {
    int mid = l + r >> 1;
    if (L > R) {
      l = mid + 1;
      L = query(1, l);
    } else {
      r = mid;
      R = query(1, r);
    }
  }
  y = L + 1;
  x = A + 2 - y;
  q = x + 999999999 - C;
  p = y + 999999999 - B;
  printf("! %d %d %d %d\n", x, y, p, q);
}
