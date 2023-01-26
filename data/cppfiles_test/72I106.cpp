#include <bits/stdc++.h>
using namespace std;
const int N = 1e9;
int main(void) {
  long long d1, d2, d3, d4;
  fflush(stdout);
  printf("? 1 %d\n", N);
  fflush(stdout);
  scanf("%lld", &d1);
  fflush(stdout);
  printf("? %d %d\n", N, N);
  fflush(stdout);
  scanf("%lld", &d2);
  long long ym = 1 + ((N - 1 - d1 + d2) / 2);
  fflush(stdout);
  printf("? %d %lld\n", N, ym);
  fflush(stdout);
  scanf("%lld", &d3);
  fflush(stdout);
  printf("? 1 %lld\n", ym);
  fflush(stdout);
  scanf("%lld", &d4);
  fflush(stdout);
  printf("! %lld %lld %lld %lld\n", 1 + d4, 1 + abs(d2 - d3), N - d3,
         N - abs(d1 - d3));
  fflush(stdout);
  return 0;
}
