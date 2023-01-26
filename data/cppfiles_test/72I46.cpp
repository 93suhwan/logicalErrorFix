#include <bits/stdc++.h>
using namespace std;
int main(void) {
  long long d1, d2, d3, d4;
  fflush(stdout);
  printf("? 1 1000000000\n");
  fflush(stdout);
  scanf("%lld", &d1);
  fflush(stdout);
  printf("? 1000000000 1000000000\n");
  fflush(stdout);
  scanf("%lld", &d2);
  long long ym = 1 + ((1000000000 - 1 - d1 + d2) / 2);
  fflush(stdout);
  printf("? 1000000000 %lld\n", ym);
  fflush(stdout);
  scanf("%lld", &d3);
  fflush(stdout);
  printf("? 1 %lld\n", ym);
  fflush(stdout);
  scanf("%lld", &d4);
  fflush(stdout);
  printf("! %lld %lld %lld %lld\n", 1 + d4, 1 + abs(d2 - d3), 1000000000 - d3,
         1000000000 - abs(d1 - d3));
  fflush(stdout);
  return 0;
}
