#include <bits/stdc++.h>
using namespace std;
int T;
long long s, n, k, siz;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%lld%lld%lld", &s, &n, &k);
    if (s == k)
      printf("YES\n");
    else if (k > s)
      printf("NO\n");
    else {
      long long siz = s + k;
      long long t = s / k * k;
      long long num1 = s - t + 1;
      long long num2 = k - num1;
      if ((s / k) % 2 == 1) {
        siz -= num1;
      } else {
        siz -= num2;
      }
      if ((2 * n + 1) <= siz)
        printf("NO\n");
      else
        printf("YES\n");
    }
  }
  return 0;
}
