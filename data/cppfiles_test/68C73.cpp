#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 13;
int n, m;
int a[maxn];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long n;
    long long x, y;
    scanf("%lld", &n);
    if (n == 1) {
      printf("1 1\n");
      continue;
    }
    long long p = sqrt(n);
    if (p * p != n) p++;
    if (p * p - n < p) {
      x = p;
      y = p * p - n + 1;
    } else {
      y = p;
      x = n - (p - 1) * (p - 1);
    }
    printf("%lld %lld\n", x, y);
  }
}
