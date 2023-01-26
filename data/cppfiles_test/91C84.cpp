#include <bits/stdc++.h>
typedef struct {
  int64_t x, c;
} pr;
int b[100050];
pr u[1000];
void test() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  int64_t res = 0;
  u[0].x = 1;
  u[0].c = 1;
  int un = 1;
  for (int i = n - 2; i >= 0; i--) {
    for (int j = 0; j < un; j++) {
      u[j].x = (b[i] - 1) / (b[i + 1] / u[j].x) + 1;
      res = (res + (u[j].x - 1) * u[j].c * (i + 1)) % 998244353;
    }
    u[un].x = 1;
    u[un].c = 1;
    un++;
    int t = 0;
    for (int j = 1; j < un; j++) {
      if (u[j].x == u[t].x) {
        u[t].c += u[j].c;
        continue;
      }
      u[++t] = u[j];
    }
    un = t + 1;
  }
  printf("%lld\n", res);
}
int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) test();
  return 0;
}
