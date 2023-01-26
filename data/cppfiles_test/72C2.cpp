#include <bits/stdc++.h>
using namespace std;
int m = 1e9;
long long k1, k2, k3;
long long x, y, p, q;
long long _x = 2, _y = 3, _p = 4, _q = 5;
long long Query(int x, int y) {
  int res = m * 2;
  printf("? %d %d\n", x, y);
  fflush(stdout);
  scanf("%d", &res);
  return res;
}
int main() {
  k1 = Query(1, 1) + 2;
  k2 = Query(m, 1) + 1 - m;
  k3 = m * 2 - Query(m, m);
  y = Query(k1 - k2 >> 1, 1) + 1;
  x = k1 - y;
  p = y - k2;
  q = k3 - p;
  printf("! %lld %lld %lld %lld\n", x, y, p, q);
  fflush(stdout);
  return 0;
}
