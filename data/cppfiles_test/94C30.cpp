#include <bits/stdc++.h>
int a[10];
int64_t pw(int x) {
  int64_t res = 1;
  while (x--) res *= 10;
  return res;
}
void test() {
  int64_t n, k;
  scanf("%lld%lld", &n, &k);
  k++;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int64_t res = 0;
  for (int i = 0; i < n - 1; i++) {
    int t = pw(a[i + 1] - a[i]) - 1;
    if (t > k) {
      n = i + 1;
      break;
    }
    k -= t;
  }
  printf("%lld\n", (k + 1) * pw(a[n - 1]) - 1);
}
int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) test();
  return 0;
}
