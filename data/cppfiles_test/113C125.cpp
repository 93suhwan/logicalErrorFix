#include <bits/stdc++.h>
using namespace std;
long long int a[200004];
int main(void) {
  int n;
  scanf("%d", &n);
  long long int sum = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    sum += a[i];
  }
  sort(a + 1, a + n + 1);
  int m;
  scanf("%d", &m);
  while (m--) {
    long long int x, y;
    scanf("%lld%lld", &x, &y);
    int k = lower_bound(a + 1, a + n + 1, x) - a;
    if (k > n) {
      long long int j = x - a[n];
      if ((sum - a[n]) < y) {
        j = j + (y - (sum - a[n]));
      }
      printf("%lld\n", j);
    } else if (a[k] == x) {
      if ((sum - x) >= y) {
        printf("0\n");
      } else {
        printf("%d\n", y - (sum - x));
      }
    } else if (k == 1) {
      long long int j = 0;
      if ((sum - a[1]) < y) {
        j = j + y - (sum - a[1]);
      }
      printf("%lld\n", j);
    } else {
      long long int jh = k, jq = k - 1;
      long long int sjh = 0;
      if ((sum - a[jh]) < y) {
        sjh = sjh + y - (sum - a[jh]);
      }
      long long int sjq = 0;
      sjq = sjq + (x - a[jq]);
      if ((sum - a[jq]) < y) {
        sjq = sjq + y - (sum - a[jq]);
      }
      long long int g = min(sjq, sjh);
      printf("%lld\n", g);
    }
  }
  return 0;
}
