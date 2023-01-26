#include <bits/stdc++.h>
using namespace std;
const int M = 1e9;
int query(int x, int y) {
  printf("? %d %d\n", x, y);
  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  return ret;
}
int main() {
  long long d1 = query(1, 1);
  long long d2 = query(M, 1);
  long long max_x1 = (M + d1 - d2 - 2) / 2;
  long long y1 = query(1 + max_x1, 1);
  long long y2 = query(1 + max_x1, M);
  long long x1 = d1 - y1;
  long long x2 = d2 - y1;
  printf("! %lld %lld %lld %lld\n", x1 + 1, y1 + 1, M - x2, M - y2);
  fflush(stdout);
}
