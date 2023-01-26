#include <bits/stdc++.h>
using namespace std;
int main() {
  int L, R;
  puts("? 1 1");
  fflush(stdout);
  scanf("%d", &L);
  puts("? 1 1000000000");
  fflush(stdout);
  scanf("%d", &R);
  int l = 1, r = 1000000000, pos = 1, dis = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    int x;
    printf("? 1 %d\n", mid), fflush(stdout);
    scanf("%d", &x);
    if (mid - 1 == L - x)
      pos = mid, dis = x, l = mid + 1;
    else
      r = mid - 1;
  }
  int xp, yp, xq, yq;
  xp = 1 + dis;
  yp = pos;
  R -= dis;
  yq = 1000000000 - R;
  printf("? 1000000000 %d\n", yq), fflush(stdout);
  int x;
  scanf("%d", &x);
  xq = 1000000000 - x;
  printf("! %d %d %d %d\n", xp, yp, xq, yq), fflush(stdout);
  return 0;
}
